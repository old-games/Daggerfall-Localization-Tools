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
TForm3 *Form3;
//---------------------------------------------------------------------------
typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned int   dword;
typedef char           string[256];
//---------------------------------------------------------------------------
FILE *f;
byte Header[0x0210];
byte Particle[10];
dword particles_count=0;
dword rumors_count=0;

AnsiString default_dat;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
 AnsiString cd,s;
 int i;
 if(OpenDialog->Execute())
 {
  cd=GetCurrentDir()+"\\";
  default_dat=
   OpenDialog->FileName.SubString(cd.Length()+1,OpenDialog->FileName.Length()-cd.Length());
  Form3->Caption="TES2: Daggerfall DAT-files Editor { "+default_dat+" }";
  Application->Title="{ "+default_dat+" }";
  Log->Lines->Add("Открытие файла '"+default_dat+"'...");
  f=fopen(OpenDialog->FileName.c_str(),"rb+");
  //NAMEGEN.DAT
  if(default_dat=="NAMEGEN.DAT")
  {
   particles_count=0;
   PageControl1->ActivePage=TabSheet1;
   ParticlesList->Clear();
   fread(Header,sizeof(Header),1,f);
   while(!feof(f))
   {
    fread(Particle,sizeof(Particle),1,f);
    if(!feof(f))
    {
     ParticlesList->Lines->Add((char *)Particle);
     particles_count++;
    }
    Application->ProcessMessages();
   }
  }
  fclose(f);
  Log->Lines->Add("Открытие файла завершено.");
  if(default_dat=="NAMEGEN.DAT")
   Log->Lines->Add("Считано "+IntToStr(particles_count)+" частиц имен.");
  if(default_dat=="RUMORS.DAT")
   Log->Lines->Add("Считано "+IntToStr(rumors_count)+" слухов.");
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
 AnsiString s;
 int i,j;
 if(SaveDialog->Execute())
 {
  Log->Lines->Add("Сохранение файла ...");
  f=fopen(SaveDialog->FileName.c_str(),"wb");
  //NAMEGEN.DAT
  if(default_dat=="NAMEGEN.DAT")
  {
   fwrite(Header,sizeof(Header),1,f);
   for(i=0;i<ParticlesList->Lines->Count;i++)
   {
    for(j=0;j<10;j++)Particle[j]=0;
    strcpy(Particle,ParticlesList->Lines->Strings[i].c_str());
    fwrite(Particle,sizeof(Particle),1,f);
   }
  }
  fclose(f);
  Log->Lines->Add("Сохранение завершено.");
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button3Click(TObject *Sender)
{
 TButton *sb=(TButton *)Sender;
 AnsiString f;
 int i,j,k;
 bool found=false;
 f=ParticlesList->Text;
 sb->Tag=~sb->Tag;
 if(sb->Tag==0)sb->Caption="NewRus -> NewEng";
 else sb->Caption="NewEng -> NewRus";
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
 ParticlesList->Text=f;
}
//---------------------------------------------------------------------------

