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
TForm1 *Form1;
//---------------------------------------------------------------------------
typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned int   dword;
typedef char           string[256];
typedef struct {
 byte block01[14];
 byte bdr,adr,cld;//длительность
 byte block02[6];
 byte bch,ach,clc;//шанс
 byte block03[6];
 byte bm1,bm2,am1,am2,clm;
 byte block04[10];
 char Name[25];
 byte block05[17];
}TSpell;
//---------------------------------------------------------------------------
FILE *f;
TSpell Spell[200];
int SpellsCount=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 int i=0;
 if(OpenDialog->Execute())
 {
  Log->Lines->Add("Подключение к SPELLS.STD ...");
  fclose(f);
  f=fopen(OpenDialog->FileName.c_str(),"rb+");
  ListBox->Items->Clear();
  Log->Lines->Add("Чтение данных ...");
  fread(&Spell[i],sizeof(TSpell),1,f);
  while(!feof(f))
  {
   ListBox->Items->Add("Запись №"+IntToStr(i)+" ["+Spell[i].Name+"]");
   i++;
   fread(&Spell[i],sizeof(TSpell),1,f);
  }
  SpellsCount=i;
  fclose(f);
  Log->Lines->Add(IntToStr(SpellsCount)+" записей считано.");
  ListBox->ItemIndex=0;
  ListBoxClick(NULL);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if(SaveDialog->Execute())
 {
  Log->Lines->Add("Сохранение файла ...");
  f=fopen(SaveDialog->FileName.c_str(),"wb+");
  for(int i=0;i<SpellsCount;i++)
  {
   fwrite(&Spell[i],sizeof(TSpell),1,f);
  }
  fclose(f);
  Log->Lines->Add("Сохранение завершено.");
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBoxClick(TObject *Sender)
{
 int index=ListBox->ItemIndex;
 SpellName->Text=Spell[index].Name;
 bch->Text=IntToStr(Spell[index].bch);
 ach->Text=IntToStr(Spell[index].ach);
 clc->Text=IntToStr(Spell[index].clc);
 bdr->Text=IntToStr(Spell[index].bdr);
 adr->Text=IntToStr(Spell[index].adr);
 cld->Text=IntToStr(Spell[index].cld);
 bm1->Text=IntToStr(Spell[index].bm1);
 bm2->Text=IntToStr(Spell[index].bm2);
 am1->Text=IntToStr(Spell[index].am1);
 am2->Text=IntToStr(Spell[index].am2);
 clm->Text=IntToStr(Spell[index].clm);
 if(FixBox->Checked)
 {
  SpeedButton1->Tag=0;
  SpeedButton1->Tag=~SpeedButton1->Tag;
  SpeedButton1Click(SpeedButton1);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 int index=ListBox->ItemIndex;
 strcpy(Spell[index].Name,SpellName->Text.c_str());
 ListBox->SetFocus();
 ListBox->ItemIndex++;
 ListBoxClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
 TSpeedButton *sb=(TSpeedButton *)Sender;
 AnsiString f;
 int i,j,k;
 bool found=false;
 f=SpellName->Text;
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
 SpellName->Text=f;
}
//---------------------------------------------------------------------------

