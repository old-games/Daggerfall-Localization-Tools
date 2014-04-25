//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "..\\..\\Common Files\\letters.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
//#pragma link "iComponent"
//#pragma link "iCustomComponent"
//#pragma link "iGradient"
//#pragma link "iVCLComponent"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
typedef unsigned char      byte;
typedef unsigned short int word;
typedef unsigned int       dword;
typedef unsigned long int  qword;
typedef char               string[256];
#define InMiddle       0xFD
#define FontNumber     0xF9
#define EndOfPage      0xF6
#define Return         0x00
#define MAX_PAGES_COUNT 100
#define MAX_PAGE_SIZE  4000
//---------------------------------------------------------------------------
byte BookHeader[0xEA];
word PagesCount;
word CurrentPage;
dword PageAddress[MAX_PAGES_COUNT];
dword PageSize[MAX_PAGES_COUNT];
byte Page[MAX_PAGES_COUNT][MAX_PAGE_SIZE];
AnsiString default_txt;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 AnsiString cd;
 FILE *f;
 int i;
 dword curpos;
 if(OpenDialog->Execute())
 {
  cd=GetCurrentDir()+"\\";
  default_txt=
   OpenDialog->FileName.SubString(cd.Length()+1,OpenDialog->FileName.Length()-cd.Length());
  Timer->Enabled=true;
  f=fopen(OpenDialog->FileName.c_str(),"rb+");
  Log->Clear();
  //Заголовок
  Log->Lines->Add("Чтение заголовка...");
  fread(BookHeader,sizeof(BookHeader),1,f);
  Title->Text="";
  for(i=0;i<64;i++)Title->Text=Title->Text+(char)BookHeader[i];
  Author->Text="";
  for(i=64;i<224;i++)Author->Text=Author->Text+(char)BookHeader[i];
  //Количество страниц
  Log->Lines->Add("Чтение количества страниц...");
  fread(&PagesCount,sizeof(PagesCount),1,f);
  CurrentPage=1;
  PC->Caption=IntToStr(PagesCount);
  CP->Caption=IntToStr(CurrentPage);
  PCMax->Value=PagesCount;
  //Адреса страниц
  Log->Lines->Add("Чтение адресов страниц...");
  fread(PageAddress,sizeof(dword)*PagesCount,1,f);
  curpos=ftell(f);
  fseek(f,0,SEEK_END);
  PageAddress[PagesCount]=ftell(f);
  fseek(f,curpos,SEEK_SET);
  //Размер страниц
  Log->Lines->Add("Подсчет размеров страниц...");
  for(i=0;i<PagesCount;i++)PageSize[i]=PageAddress[i+1]-PageAddress[i];
  //Страницы
  Log->Lines->Add("Чтение содержимого страниц...");
  for(i=0;i<PagesCount;i++)
  {
   fseek(f,PageAddress[i],SEEK_SET);
   fread(Page[i],sizeof(byte)*PageSize[i],1,f);
   Application->ProcessMessages();
  }
  Log->Lines->Add("Чтение документа "+OpenDialog->FileName+" завершено.");
  Form1->Caption="TES: Daggerfall Book Editor { "+OpenDialog->FileName+" }";
  Timer->Enabled=false;
  fclose(f);
  SpeedButton3Click(NULL);
  SaveDialog->FileName=OpenDialog->FileName;
  Form1->Caption="TES2:Daggerfall Books-files Editor { "+default_txt+" }";
  Application->Title="{ "+default_txt+" }";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
 dword i,index=CurrentPage-1;
 AnsiString s="";
 Memo->Clear();
 for(i=0;i<PageSize[index];i++)
 {
  switch(Page[index][i])
  {
   case InMiddle:Memo->Lines->Add("<0xFD>");break;
   case FontNumber:
   {
    i++;
    Memo->Lines->Add("<0xF9="+IntToStr(Page[index][i])+">");
//    Memo->Lines->Add("");
   };break;
   case Return:
   {
    if(s.Length()!=0){Memo->Lines->Add(s);s="";}
    else Memo->Lines->Add("");
//    Memo->Lines->Add("<End Of Line>");
   };break;
   case EndOfPage:
   {
    if(s.Length()!=0){Memo->Lines->Add(s);s="";}
    Memo->Lines->Add("<0xF6>");
   };break;
   default:s=s+(char)Page[index][i];
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
 if(CurrentPage>1)
 {
  CurrentPage--;
  CP->Caption=IntToStr(CurrentPage);
  SpeedButton3Click(NULL);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
 if(CurrentPage<PagesCount)
 {
  CurrentPage++;
  CP->Caption=IntToStr(CurrentPage);
  SpeedButton3Click(NULL);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
 if(Form1->WindowState!=wsMaximized)
 {
  Form1->WindowState=wsMaximized;
  Update();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTimer(TObject *Sender)
{
 Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 FILE *f;
 int i;
 dword curpos;
 if(SaveDialog->Execute())
 {
  Timer->Enabled=true;
  f=fopen(SaveDialog->FileName.c_str(),"wb+");
  Log->Clear();
  //Заголовок
  Log->Lines->Add("Запись заголовка...");
  for(i=0;i<224;i++)BookHeader[i]=0;
  for(i=1;i<=Title->Text.Length();i++)BookHeader[i-1]=Title->Text[i];
  for(i=1;i<=Author->Text.Length();i++)BookHeader[64+i-1]=Author->Text[i];
  fwrite(BookHeader,sizeof(BookHeader),1,f);
  //Количество страниц
  Log->Lines->Add("Запись количества страниц...");
  fwrite(&PagesCount,sizeof(PagesCount),1,f);
  //Адреса страниц
  Log->Lines->Add("Формирование адресов страниц...");
  curpos=sizeof(BookHeader)+sizeof(PagesCount)+sizeof(dword)*PagesCount;
  for(i=0;i<PagesCount;i++)
  {
   PageAddress[i]=curpos;
   curpos+=PageSize[i];
  }
  Log->Lines->Add("Запись адресов страниц...");
  fwrite(PageAddress,sizeof(dword)*PagesCount,1,f);
  //Страницы
  Log->Lines->Add("Запись содержимого страниц...");
  for(i=0;i<PagesCount;i++)
  {
   fwrite(Page[i],sizeof(byte)*PageSize[i],1,f);
   Application->ProcessMessages();
  }
  Log->Lines->Add("Запись документа "+SaveDialog->FileName+" завершена.");
  Form1->Caption="TES: Daggerfall Book Editor { "+SaveDialog->FileName+" }";
  Timer->Enabled=false;
  fclose(f);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
 AnsiString s,f;
 dword index=CurrentPage-1;
 int i,j=0,k;
 for(i=0;i<Memo->Lines->Count;i++)
 {
  s=Memo->Lines->Strings[i];
  if(s.Length()==0){Page[index][j]=Return;j++;}
  else
  {
   f=s.SubString(1,6);
   if(s=="<0xFD>")
   {
    Page[index][j]=InMiddle;
    j++;
   }
   else if(s=="<0xF6>")
   {
    Page[index][j]=EndOfPage;
    j++;
   }
   else if(f=="<0xF9=")
   {
    Page[index][j]=FontNumber;j++;
    Page[index][j]=StrToInt(s[7]);j++;
   }else
   {
    for(k=1;k<=s.Length();k++)
    {
     Page[index][j]=s[k];
     j++;
    }
    Page[index][j]=Return;j++;
   }
  }
 }
 PageSize[index]=j;
 SpeedButton2Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
 AnsiString f;
 Memo->Lines->Add("");
 for(int i=Memo->Lines->Count-2;i>=0;i--)
 {
  Memo->Lines->Strings[i+1]=Memo->Lines->Strings[i];
 }
 Memo->Lines->Strings[0]="<0xF9=1>";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MemoChange(TObject *Sender)
{
 int lc=0;
 for(int i=0;i<Memo->Lines->Count;i++)
 {
  AnsiString f=Memo->Lines->Strings[i];
  if(f!="<0xF6>" && f!="<0xFD>" && f.SubString(1,6)!="<0xF9=")
   lc++;
 }
 LC->Caption=IntToStr(lc);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PCMaxChange(TObject *Sender)
{
 PagesCount=PCMax->Value;
 PC->Caption=IntToStr(PagesCount);
}
//---------------------------------------------------------------------------




















void __fastcall TForm1::Button2Click(TObject *Sender)
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
 if(CP->Caption=="1")
 {
 f=Title->Text;
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
 Title->Text=f;
 f=Author->Text;
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
 Author->Text=f;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
 TButton *sb=(TButton *)Sender;
 AnsiString f,ff;
 int i,j,k;
 bool found=false;
 f=Memo->Text;
 sb->Tag=~sb->Tag;
 if(sb->Tag==0)sb->Caption="Rus -> Eng";
 else sb->Caption="Eng -> Rus";
 for(i=1;i<=f.Length();i++)
 {
  if(f[i]==':')
  {
   ff=f.SubString(i-4,4);
   if(ff=="name")
   {
    for(k=i;f[k]!='\r';k++)
    {
     found=false;
     for(j=0;j<66;j++)
     {
       if(sb->Tag==0 && f[k]==NewEngLetters[j])
       {found=true;break;}
      else if(f[k]==NewRusLetters[j])
       {found=true;break;}
     }
     if(found)
     {
      if(sb->Tag==0)f[k]=NewRusLetters[j];
      else f[k]=NewEngLetters[j];
     }
    }i=k;
   }
  }
 }
 Memo->Text=f;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 TButton *sb=(TButton *)Sender;
 AnsiString f;
 int i,j,k;
 bool found=false;
// f=Memo->Text;
 sb->Tag=~sb->Tag;
 if(sb->Tag==0)sb->Caption="Rus -> Eng";
 else sb->Caption="Eng -> Rus";
 for(k=0;k<Memo->Lines->Count;k++)
 {
  f=Memo->Lines->Strings[k];
  if(f.Length()>0)
  {
   if(f[1]>='0' && f[1]<='9')
   {
    while(f[1]<'a' || f[1]>'z')
    {
     for(i=1;i<=f.Length();i++)
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
     Memo->Lines->Strings[k]=f;
     k++;f=Memo->Lines->Strings[k];
    }
   }
   for(i=2;i<=f.Length();i++)
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
   Memo->Lines->Strings[k]=f;
   k++;if(k<Memo->Lines->Count)
   {
    f=Memo->Lines->Strings[k];
    while(f.Length()>0 && (f[1]<'a' || f[1]>'z'))
    {
     k++;f=Memo->Lines->Strings[k];
    }
   }k--;
  }
 }
 Memo->SetFocus();Memo->SelectAll();
}
//---------------------------------------------------------------------------

