//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "..\\..\\Common Files\\letters.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DirDialog"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
#define TEXTBUFSIZE      10000
typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned int   dword;
typedef char           string[256];
typedef struct {
 word Index;
 dword Offset;
 dword Size;
 byte *TextBuf;
}TQRCHeader;
//---------------------------------------------------------------------------
FILE *f;
word HeaderLength;
TQRCHeader *QRCHeader;
AnsiString default_qrc="";
AnsiString default_path=".";
TSearchRec fsrc;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 AnsiString cd;
 int i,j;
 dword maxs=0;
 if(OpenDialog->Execute())
 {
  if(default_qrc.Length()>0)
  {
   for(i=0;i<ListBox->Tag;i++)delete QRCHeader[i].TextBuf;
   delete[] QRCHeader;
   ListBox->Clear();
   Memo->Clear();
  }
  cd=GetCurrentDir()+"\\";
  default_qrc=
   OpenDialog->FileName.SubString(cd.Length()+1,OpenDialog->FileName.Length()-cd.Length());
  SaveDialog->FileName=OpenDialog->FileName;
  Log->Lines->Add("Подключение к "+default_qrc+" ...");
  fclose(f);
  f=fopen(OpenDialog->FileName.c_str(),"rb+");
  Log->Lines->Add("Чтение заголовка ...");
  fread(&HeaderLength,sizeof(HeaderLength),1,f);
  HeaderLength/=6;ListBox->Tag=HeaderLength;
  QRCHeader=new TQRCHeader[HeaderLength];
  for(i=0;i<HeaderLength;i++)
  {
   QRCHeader[i].TextBuf=new byte[TEXTBUFSIZE];
   fread(&QRCHeader[i].Index,sizeof(QRCHeader[i].Index),1,f);
   fread(&QRCHeader[i].Offset,sizeof(QRCHeader[i].Offset),1,f);
   if(i>0)
   {
    QRCHeader[i-1].Size=QRCHeader[i].Offset-QRCHeader[i-1].Offset;
    if(QRCHeader[i-1].Size>maxs)maxs=QRCHeader[i-1].Size;
   }
  }fseek(f,0,SEEK_END);
  QRCHeader[i-1].Size=ftell(f)-QRCHeader[i-1].Offset;
  ListBox->Items->Clear();
  Log->Lines->Add("Чтение данных ...");
  for(i=0;i<HeaderLength;i++)
  {
   fseek(f,QRCHeader[i].Offset,SEEK_SET);
   fread(QRCHeader[i].TextBuf,QRCHeader[i].Size,1,f);
   ListBox->Items->Add("Rec.№"+IntToStr(i)+" ["+QRCHeader[i].Index+"]");
  }
  fclose(f);
  Log->Lines->Add("Подключение завершено.");
  Form1->Caption="TES2:Daggerfall QRC-files Editor { "+default_qrc+" }";
  Application->Title="{ "+default_qrc+" }";
  ListBox->ItemIndex=0;ListBoxClick(NULL);
  Button2->Enabled=true;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBoxClick(TObject *Sender)
{
 AnsiString s,d;
 dword i;
 char c;
 int index=ListBox->ItemIndex;
 Memo->Clear();d="";
 for(i=0;i<QRCHeader[index].Size;i++)
 {
  switch(QRCHeader[index].TextBuf[i])
  {
   case 0xFB:
   {
    s="<0xFB="+IntToStr(QRCHeader[index].TextBuf[i+1])+">";
    i++;
   }break;
   case 0xFC:{
    s="<0xFC>\r\n";
   }break;
   case 0xFD:{
    s="<0xFD>\r\n";
   }break;
   case 0xFE:s="<0xFE>";break;
   case 0xFF:{
    s="<0xFF>\r\n";
   }break;
   default:s=(char)QRCHeader[index].TextBuf[i];
  }
  d=d+s;
 }
 Memo->Text=Memo->Text+d;
 if(FixBox->Checked)
 {
  Button4->Tag=0;
  Button4->Tag=~Button4->Tag;
  Button4Click(Button4);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
 TButton *sb=(TButton *)Sender;
 AnsiString f;
 int i,j,k;
 bool found=false;
 f=Memo->Text;
 sb->Tag=~sb->Tag;
 if(sb->Tag==0)sb->Caption="Rus -> Eng";
 else sb->Caption="Eng -> Rus";
 for(i=1;i<=f.Length();i++)
 {
  if(f.SubString(i,3)=="<0x")
  {
   for(j=i+1;j<=f.Length();j++)if(f[j]=='>')break;
   i=j;
  }
  else if(f[i]==dfVar1)
  {
   for(j=i+1;j<=f.Length();j++)
   if((f[j]<'a' || f[j]>'z')&&(f[j]<'0' || f[j]>'9'))break;
   i=j-1;
  }
  else if(f[i]=='_' || f[i]=='=')
  {
   for(j=i+1;j<=f.Length();j++)
   if((f[j]<'a' || f[j]>'z')&&(f[j]<'0' || f[j]>'9'))break;
   i=j-1;
  }else
  {
   found=false;
   for(j=0;j<66;j++)
   {
    if(sb->Tag==0 && f[i]==NewEngLetters[j])
     {found=true;break;}
    else if(f[i]==NewRusLetters[j])
     {found=true;break;}
   }
   if(found)
   {
    if(sb->Tag==0)f[i]=NewRusLetters[j];
    else f[i]=NewEngLetters[j];
   }
  }
 }
 Memo->Text=f;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 AnsiString f=Memo->Text;
 int i,j,index=ListBox->ItemIndex,k;
 for(i=1,j=0;i<=f.Length();i++,j++)
 {
  if(f[i]=='\r')i+=2;
  if(f.SubString(i,6)!="<0xFB=" &&
     f.SubString(i,6)!="<0xFC>" &&
     f.SubString(i,6)!="<0xFD>" &&
     f.SubString(i,6)!="<0xFE>" &&
     f.SubString(i,6)!="<0xFF>")
  {
   QRCHeader[index].TextBuf[j]=f[i];
  }else
  {
   if(f.SubString(i,6)=="<0xFB=")
   {
    QRCHeader[index].TextBuf[j]=0xFB;
    i+=6;k=i;
    while(f[k]!='>')k++;
    QRCHeader[index].TextBuf[j]=0xFB;
    j++;
    QRCHeader[index].TextBuf[j]=(byte)StrToInt(f.SubString(i,k-i));
    i=k;
   }else
   {
    if(f.SubString(i,6)=="<0xFC>")
     QRCHeader[index].TextBuf[j]=0xFC;
    if(f.SubString(i,6)=="<0xFD>")
     QRCHeader[index].TextBuf[j]=0xFD;
    if(f.SubString(i,6)=="<0xFE>")
    {
     QRCHeader[index].TextBuf[j]=0xFE;
     j++;
     break;
    }
    if(f.SubString(i,6)=="<0xFF>")
     QRCHeader[index].TextBuf[j]=0xFF;
    i+=5;
   }
  }
 }
 QRCHeader[index].Size=j;
 ListBox->Items->Strings[index]=
  "Rec.№"+IntToStr(index)+" ["+QRCHeader[index].Index+"]";
 ListBox->SetFocus();
 ListBox->ItemIndex++;
 ListBoxClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
 Application->Title="TES2:Daggerfall QRC-files Editor";
 Form1->WindowState=wsMaximized;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int i,offset;
 if(SaveDialog->Execute())
 {
  Log->Lines->Add("Сохранение файла ...");
  f=fopen(SaveDialog->FileName.c_str(),"wb+");
  Log->Lines->Add("Запись заголовка ...");
  HeaderLength*=6;
  fwrite(&HeaderLength,sizeof(HeaderLength),1,f);
  HeaderLength/=6;offset=QRCHeader[0].Offset;
  for(i=0;i<HeaderLength;i++)
  {
   if(i>0)
   {
    offset+=QRCHeader[i-1].Size;
    QRCHeader[i].Offset=offset;
   }
   fwrite(&QRCHeader[i].Index,sizeof(QRCHeader[i].Index),1,f);
   fwrite(&QRCHeader[i].Offset,sizeof(QRCHeader[i].Offset),1,f);
  }
  Log->Lines->Add("Запись данных ...");
  for(i=0;i<HeaderLength;i++)
  {
   fwrite(QRCHeader[i].TextBuf,QRCHeader[i].Size,1,f);
  }
  fclose(f);
  for(i=0;i<ListBox->Tag;i++)delete QRCHeader[i].TextBuf;
  delete[] QRCHeader;
  ListBox->Clear();
  Memo->Clear();
  default_qrc="";
  Log->Lines->Add("Сохранение завершено.");
  Form1->Caption="TES2:Daggerfall QRC-files Editor";
  Application->Title="TES2:Daggerfall QRC-files Editor";
  Button2->Enabled=false;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::QRCListClick(TObject *Sender)
{
 AnsiString cd;
 int i,j;
 dword maxs=0;
 if(default_qrc!=QRCList->Items->Strings[QRCList->ItemIndex])
 {
  if(default_qrc.Length()>0)
  {
   for(i=0;i<ListBox->Tag;i++)delete QRCHeader[i].TextBuf;
   delete[] QRCHeader;
   ListBox->Clear();
   Memo->Clear();
  }
  cd=GetCurrentDir()+"\\";
  default_qrc=QRCList->Items->Strings[QRCList->ItemIndex];
  Log->Clear();
  Log->Lines->Add("Подключение к "+default_qrc+" ...");
  fclose(f);
  f=fopen((default_path+"\\"+default_qrc).c_str(),"rb+");
  Log->Lines->Add("Чтение заголовка ...");
  fread(&HeaderLength,sizeof(HeaderLength),1,f);
  HeaderLength/=6;ListBox->Tag=HeaderLength;
  QRCHeader=new TQRCHeader[HeaderLength];
  for(i=0;i<HeaderLength;i++)
  {
   QRCHeader[i].TextBuf=new byte[TEXTBUFSIZE];
   fread(&QRCHeader[i].Index,sizeof(QRCHeader[i].Index),1,f);
   fread(&QRCHeader[i].Offset,sizeof(QRCHeader[i].Offset),1,f);
   if(i>0)
   {
    QRCHeader[i-1].Size=QRCHeader[i].Offset-QRCHeader[i-1].Offset;
    if(QRCHeader[i-1].Size>maxs)maxs=QRCHeader[i-1].Size;
   }
  }fseek(f,0,SEEK_END);
  QRCHeader[i-1].Size=ftell(f)-QRCHeader[i-1].Offset;
  ListBox->Items->Clear();
  Log->Lines->Add("Чтение данных ...");
  for(i=0;i<HeaderLength;i++)
  {
   fseek(f,QRCHeader[i].Offset,SEEK_SET);
   fread(QRCHeader[i].TextBuf,QRCHeader[i].Size,1,f);
   ListBox->Items->Add("Rec.№"+IntToStr(i)+" ["+QRCHeader[i].Index+"]");
  }
  fclose(f);
  Log->Lines->Add("Подключение завершено.");
  Form1->Caption="TES2:Daggerfall QRC-files Editor { "+default_qrc+" }";
  Application->Title="{ "+default_qrc+" }";
  ListBox->ItemIndex=0;ListBoxClick(NULL);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
 int i,offset;
 {
  Log->Clear();
  Log->Lines->Add("Сохранение файла ...");
  f=fopen((default_path+"\\"+default_qrc).c_str(),"wb+");
  Log->Lines->Add("Запись заголовка ...");
  HeaderLength*=6;
  fwrite(&HeaderLength,sizeof(HeaderLength),1,f);
  HeaderLength/=6;offset=QRCHeader[0].Offset;
  for(i=0;i<HeaderLength;i++)
  {
   if(i>0)
   {
    offset+=QRCHeader[i-1].Size;
    QRCHeader[i].Offset=offset;
   }
   fwrite(&QRCHeader[i].Index,sizeof(QRCHeader[i].Index),1,f);
   fwrite(&QRCHeader[i].Offset,sizeof(QRCHeader[i].Offset),1,f);
  }
  Log->Lines->Add("Запись данных ...");
  for(i=0;i<HeaderLength;i++)
  {
   fwrite(QRCHeader[i].TextBuf,QRCHeader[i].Size,1,f);
  }
  fclose(f);
  Log->Lines->Add("Сохранение завершено.");
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
 DirDlg->FileName="Select directory...";
 if(DirDlg->Execute() && GetCurrentDir()/*DirDlg->Directory*/!=default_path)
 {
  default_path=GetCurrentDir();//DirDlg->Directory;
  QRCList->Items->Clear();
  if(FindFirst(default_path+"\\*.qrc",faAnyFile,fsrc)==0)
  {
   do
   {
    QRCList->Items->Add(fsrc.Name);
   }while(FindNext(fsrc)==0);
   FindClose(fsrc);
   QRCList->ItemIndex=0;QRCListClick(NULL);
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
 FILE *ft;
 int i;
 AnsiString fn=default_qrc.SubString(1,8)+".txt",s;
 Log->Lines->Add("Экспорт текста в '"+fn+"' ...");
 ft=fopen(fn.c_str(),"wt");
 for(i=0;i<ListBox->Items->Count-1;i++)
 {
  ListBox->ItemIndex=i;
  ListBoxClick(NULL);
  s=Memo->Text;
  fprintf(ft,"\nСекция №%d\n\n",i);
  fprintf(ft,"%s",s.c_str());
  fprintf(ft,"\n________________________________________\n");
 }
 fclose(ft);
 Log->Lines->Add("Экспорт текста завершен.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FixBoxClick(TObject *Sender)
{
 ListBoxClick(NULL);        
}
//---------------------------------------------------------------------------

