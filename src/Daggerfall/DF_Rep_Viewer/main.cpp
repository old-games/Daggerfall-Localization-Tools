/*
****************************************************
DAG_REP.EXE  (c) Alexander A. Bouroff 2:5020/308.59
This program lists non-zero reputation values for
        different guilds of DaggerFall
  To compile, enter: "WCL386 /ox DAG_REP.CPP"
****************************************************
      Modified source by VorteX DrAgON (c)2005
****************************************************
*/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include "..\\..\\Common Files\\letters.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
struct guild_head{
 char guild_name[26];
 signed char rep;
 char unknown_shit[92-27];
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
AnsiString StrLeft(AnsiString s, int l)
{
 int i;AnsiString d="";
 if(l<=s.Length())for(i=1;i<=l;i++)d=d+s[i];
 return d;
}
AnsiString StrRight(AnsiString s, int l)
{
 int i;AnsiString d="";
 if(l<=s.Length())for(i=s.Length()+1-l;i<=s.Length();i++)d=d+s[i];
 return d;
}
//---------------------------------------------------------------------------
AnsiString Convert2RUS(AnsiString s)
{
 AnsiString f;
 int i,j,k;
 bool found=false;
 f=s;
// if(sb->Tag==0)sb->Caption="Rus -> Eng";
// else sb->Caption="Eng -> Rus";
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
    if(f[i]==NewEngLetters[j]){found=true;break;}
   }
   if(found)
   {
    f[i]=NewRusLetters[j];
   }
  }
 }
 return f;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Memo->Clear();
// char z;
 AnsiString xx;
// z=argv[1][0];
 Memo->Lines->Add(cbSaveGame->Text);
 Memo->Lines->Add("-----------------------");
 FILE *in;
 guild_head h;
 xx=Edit1->Text+"\\"+cbSaveGame->Text+"\\savevars.dat";
 in=fopen(xx.c_str(),"rb+");
 if(in!=NULL)
 {
  fseek(in,0x17D3,SEEK_SET);

  while(!feof(in))
  {
   fread(&h,sizeof(h),1,in);
   if (h.rep!=0)
   {
    if(cbEng->Checked)
      Memo->Lines->Add((AnsiString)h.guild_name+" ("+IntToStr(h.rep)+")");
    else
      Memo->Lines->Add(Convert2RUS(h.guild_name)+" ("+IntToStr(h.rep)+")");
   }
  }
  fclose(in);
 }else
 {
  Memo->Lines->Add("Папка с игрой не выбрана или выбрана неверно!");
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int i,j;
 AnsiString s,p,cd;
 if(OpenDialog->Execute())
 {
  ClientHeight=Panel1->Height+Panel2->Height;
  Panel2->Show();
  Form1->Top=Form1->Top-(Panel2->Height/2);
  Update();
  cd=GetCurrentDir();
  Edit1->Text=AnsiLowerCase(cd);
  Memo->Clear();
  Edit1->Tag=1;
  cbSaveGame->ItemIndex=0;
  Memo->Clear();
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
 ClientHeight=Panel1->Height;
}
//---------------------------------------------------------------------------
