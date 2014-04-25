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
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned int   dword;
typedef char           string[256];
//---------------------------------------------------------------------------
FILE *f;
word HeaderLength;
word RSCIndex[4000];
dword RSCOffset[4000];
dword RSCSize[4000];
byte **text;
AnsiString default_rsc;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ListBoxClick(TObject *Sender)
{
 AnsiString s,d;
 dword i;
 char c;
 int index=ListBox->ItemIndex;
 Memo->Clear();d="";
 for(i=0;i<RSCSize[index];i++)
 {
  switch(text[index][i])
  {
   case dfOffset:
   {
    s=dftOffset+IntToStr(text[index][i+1])+">";
    i++;
   }break;
   case df0xF8:{
    s=dft0xF8;
   }break;
   case dfCRRight:{
    s=dftCRRight"\r\n";
   }break;
   case dfCRCenter:{
    s=dftCRCenter"\r\n";
   }break;
   case dfEOB:s=dftEOB;break;
   case dfEOR:{
    s=dftEOR"\r\n";
   }break;
   default:s=(char)text[index][i];
  }
  d=d+s;
 }
 Memo->Text=Memo->Text+d;
 if(FixBox->Checked)
 {
  SpeedButton1->Tag=0;
  SpeedButton1->Tag=~SpeedButton1->Tag;
  SpeedButton1Click(SpeedButton1);
 }
 if(SelectBox->Checked)
 {
  Memo->SetFocus();
  Memo->SelectAll();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
 AnsiString cd;
 int i,j;
 dword maxs=0;
 if(OpenDialog->Execute())
 {
  Log->Lines->Add("Подключение к TEXT.RSC ...");
  fclose(f);
  f=fopen(OpenDialog->FileName.c_str(),"rb+");
  Log->Lines->Add("Чтение заголовка ...");
  fread(&HeaderLength,sizeof(HeaderLength),1,f);
  HeaderLength/=6;
  for(i=0;i<HeaderLength;i++)
  {
   fread(&RSCIndex[i],sizeof(RSCIndex[i]),1,f);
   fread(&RSCOffset[i],sizeof(RSCOffset[i]),1,f);
   if(i>0)
   {
    RSCSize[i-1]=RSCOffset[i]-RSCOffset[i-1];
    if(RSCSize[i-1]>maxs)maxs=RSCSize[i-1];
   }
  }fseek(f,0,SEEK_END);
  RSCSize[i-1]=ftell(f)-RSCOffset[i-1];
  ListBox->Items->Clear();
  Log->Lines->Add("Чтение данных ...");
  for(i=0;i<HeaderLength;i++)
  {
   fseek(f,RSCOffset[i],SEEK_SET);
   fread(text[i],RSCSize[i],1,f);
   ListBox->Items->Add("Запись №"+IntToStr(i)+" ["+RSCIndex[i]+"]");
  }
  fclose(f);
  Log->Lines->Add("Подключение завершено.");
  Log->Lines->Add(IntToStr(maxs));
  cd=GetCurrentDir()+"\\";
  default_rsc=
   OpenDialog->FileName.SubString(cd.Length()+1,OpenDialog->FileName.Length()-cd.Length());
  Form2->Caption="TES2: Daggerfall RSC-files Editor { "+default_rsc+" }";
  Application->Title="{ "+default_rsc+" }";
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{
 int i,offset;
 if(SaveDialog->Execute())
 {
  Log->Lines->Add("Сохранение файла ...");
  f=fopen(SaveDialog->FileName.c_str(),"wb+");
  Log->Lines->Add("Запись заголовка ...");
  HeaderLength*=6;
  fwrite(&HeaderLength,sizeof(HeaderLength),1,f);
  HeaderLength/=6;offset=RSCOffset[0];
  for(i=0;i<HeaderLength;i++)
  {
   if(i>0)
   {
    offset+=RSCSize[i-1];
    RSCOffset[i]=offset;
   }
   fwrite(&RSCIndex[i],sizeof(RSCIndex[i]),1,f);
   fwrite(&RSCOffset[i],sizeof(RSCOffset[i]),1,f);
  }
  Log->Lines->Add("Запись данных ...");
  for(i=0;i<HeaderLength;i++)
  {
   fwrite(text[i],RSCSize[i],1,f);
  }
  fclose(f);
  Log->Lines->Add("Сохранение завершено.");
  Form2->Caption="TES2: Daggerfall RSC-files Editor";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
 AnsiString f=Memo->Text;
 int i,j,index=ListBox->ItemIndex,k;
 for(i=1,j=0;i<=f.Length();i++,j++)
 {
  if(f[i]=='\r')i+=2;
  if(f.SubString(i,6)!=dft0xFA &&
     f.SubString(i,6)!=dftOffset &&
     f.SubString(i,6)!=dft0xF8 &&
     f.SubString(i,6)!=dftCRRight &&
     f.SubString(i,6)!=dftCRCenter &&
     f.SubString(i,6)!=dftEOB &&
     f.SubString(i,6)!=dftEOR)
  {
   text[index][j]=f[i];
  }else
  {
   if(f.SubString(i,6)==dft0xFA)
   {
    text[index][j]=df0xFA;
    i+=6;k=i;
    while(f[k]!='>')k++;
    text[index][j]=df0xFA;
    j++;
    text[index][j]=(byte)StrToInt(f.SubString(i,k-i));
    i=k;
   }else
   if(f.SubString(i,6)==dftOffset)
   {
    text[index][j]=dfOffset;
    i+=6;k=i;
    while(f[k]!='>')k++;
    text[index][j]=dfOffset;
    j++;
    text[index][j]=(byte)StrToInt(f.SubString(i,k-i));
    i=k;
   }else
   {
    if(f.SubString(i,6)==dft0xF8)
     text[index][j]=df0xF8;
    if(f.SubString(i,6)==dftCRRight)
     text[index][j]=dfCRRight;
    if(f.SubString(i,6)==dftCRCenter)
     text[index][j]=dfCRCenter;
    if(f.SubString(i,6)==dftEOB)
     text[index][j]=dfEOB;
    if(f.SubString(i,6)==dftEOR)
     text[index][j]=dfEOR;
    i+=5;
   }
  }
 }
 RSCSize[index]=j;
 ListBox->SetFocus();
 ListBox->ItemIndex++;
 ListBoxClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
 text=new byte*[4000];
 for(int i=0;i<4000;i++)text[i]=new byte[30000];
 Form2->WindowState=wsMaximized;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
 for(int i=0;i<4000;i++)delete[] text[i];
 delete[] text;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ApplicationEvents1ShortCut(TWMKey &Msg,
      bool &Handled)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
 TSpeedButton *sb=(TSpeedButton *)Sender;
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

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
 Timer1->Enabled=false;
 int i,j,sl=0;
 AnsiString s=Memo->Lines->Strings[Memo->CaretPos.y];
 for(i=1;i<=s.Length();i++)
 {
  if(s[i]>='0' && s[i]<='9')sl+=4;
  else
  switch(s[i])
  {
   case ' ':sl+=SpaceWidth;break;
   case '.':sl+=2;break;
   case ',':sl+=2;break;
   case ':':sl+=1;break;
   case ';':sl+=2;break;
   case '?':sl+=4;break;
   case '!':sl+=1;break;
   default:
   {
    for(j=0;j<66;j++)if(s[i]==NewRusLetters[j])break;
    if(j<66)sl+=LettersWidth[j];
   }break;
  }
 }
 LineWidth->Caption=IntToStr(sl);
/* Timer1->Enabled=false;
 if(LocationList->Lines->Strings[LocationList->CaretPos.y].Length()>31)
  Edit2->Font->Color=clRed;
 else
  Edit2->Font->Color=clBlack;
 Edit1->Text=IntToStr(LocationList->CaretPos.y);
 Edit2->Text=IntToStr(LocationList->Lines->Strings[LocationList->CaretPos.y].Length());
 */
}
//---------------------------------------------------------------------------

void __fastcall TForm2::MemoChange(TObject *Sender)
{
 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::MemoKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button4Click(TObject *Sender)
{
 FILE *ft;
 int i,j;
 AnsiString fn="text.txt",s;
 Log->Lines->Add("Экспорт текста в '"+fn+"' ...");
 ft=fopen(fn.c_str(),"wt");
 for(i=Edit1->Text.ToInt();i<=Edit2->Text.ToInt();i++)
 {
  ListBox->ItemIndex=i;
  ListBoxClick(NULL);
  s="";
  for(j=0;j<Memo->Lines->Count-1;j++)
  {
   s=s+Memo->Lines->Strings[j]+"\n";
  }
  fprintf(ft,"%s",s.c_str());
  fprintf(ft,"\n");
 }
 fclose(ft);
 Log->Lines->Add("Экспорт текста завершен.");
}
//---------------------------------------------------------------------------

