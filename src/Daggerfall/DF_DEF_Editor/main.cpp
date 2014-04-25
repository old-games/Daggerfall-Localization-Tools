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
dword HeaderLength;
struct TDEFItem{
  byte Name[32];
  byte Info[30];
}DEFItemsList[100];
AnsiString default_def;
int defitems_count;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ListBoxClick(TObject *Sender)
{
 AnsiString s;
 dword i;
 char c;
 int index=ListBox->ItemIndex;
 ItemName->Text=(char *)DEFItemsList[index].Name;
 ItemName->SetFocus();
 if(FixBox->Checked)
 {
  SpeedButton1->Tag=0;
  SpeedButton1->Tag=~SpeedButton1->Tag;
  SpeedButton1Click(SpeedButton1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
 AnsiString cd;
 int i,j;
 if(OpenDialog->Execute())
 {
  Log->Lines->Add("Подключение к MAGIC.DEF ...");
  fclose(f);
  f=fopen(OpenDialog->FileName.c_str(),"rb+");
  Log->Lines->Add("Чтение заголовка ...");
  fread(&HeaderLength,sizeof(HeaderLength),1,f);
  ListBox->Clear();
  Log->Lines->Add("Чтение данных ...");
  i=0;defitems_count=0;
  while(!feof(f))
  {
   fread(&DEFItemsList[i],sizeof(TDEFItem),1,f);
   if(!feof(f))
   {
    ListBox->Items->Add("Rec.№"+IntToStr(i)+" ["+(char *)DEFItemsList[i].Name+"]");
    i++;
   }
  }
  defitems_count=i;
  fclose(f);
  Log->Lines->Add("Подключение завершено.");
  cd=GetCurrentDir()+"\\";
  default_def=
   OpenDialog->FileName.SubString(cd.Length()+1,OpenDialog->FileName.Length()-cd.Length());
  Form2->Caption="TES2: Daggerfall DEF-files Editor { "+default_def+" }";
  Application->Title="{ "+default_def+" }";
  ListBox->ItemIndex=0;
  ListBoxClick(NULL);
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
  fwrite(&HeaderLength,sizeof(HeaderLength),1,f);
  Log->Lines->Add("Запись данных ...");
  for(i=0;i<defitems_count;i++)
  {
   fwrite(&DEFItemsList[i],sizeof(TDEFItem),1,f);
  }
  fclose(f);
  Log->Lines->Add("Сохранение завершено.");
  Form2->Caption="TES2: Daggerfall DEF-files Editor";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
 AnsiString f=ItemName->Text;
 int i,j,index=ListBox->ItemIndex,k;
 for(i=0;i<32;i++)DEFItemsList[index].Name[i]=0;
 for(j=1;j<=f.Length();j++)DEFItemsList[index].Name[j-1]=f[j];
 ListBox->SetFocus();
 ListBox->ItemIndex++;
 ListBoxClick(NULL);
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
 f=ItemName->Text;
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
 ItemName->Text=f;
}
//---------------------------------------------------------------------------


