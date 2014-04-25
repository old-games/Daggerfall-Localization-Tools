//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
FILE *f;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 int i,j;
 AnsiString s,p;
 if(OpenDialog->Execute())
 {
  if(OpenDialog->FileName!="Z.CFG")
  {
   ClientHeight=Panel1->Height+PageControl1->Height;
   PageControl1->Show();
   Form1->Top=Form1->Top-(PageControl1->Height/2);
   Update();
   s=OpenDialog->FileName;
   for(i=s.Length();i>=1;i--)if(s[i]=='\\')break;
   Edit1->Text=StrLeft(OpenDialog->FileName,i);
   Memo->Lines->LoadFromFile(OpenDialog->FileName);
   Edit2->Text="";
   Edit3->Text="";
   cb1->Checked=false;
   cb2->Checked=false;
   for(i=0;i<Memo->Lines->Count;i++)
   {
    s=Memo->Lines->Strings[i];
    if(AnsiLowerCase(StrLeft(s,5))=="path ")
    {
     Edit2->Text=StrRight(s,s.Length()-5);
    }
     if(AnsiLowerCase(StrLeft(s,7))=="pathcd ")
    {
     Edit3->Text=StrRight(s,s.Length()-7);
    }
    if(AnsiLowerCase(StrLeft(s,12))=="magicrepair ")
    {
     p=StrRight(s,1);
     if(p=="1")
      cb1->Checked=true;
     else
      cb1->Checked=false;
    }
    if(AnsiLowerCase(StrLeft(s,10))=="cheatmode ")
    {
     p=StrRight(s,1);
     if(p=="1")
      cb2->Checked=true;
     else
      cb2->Checked=false;
    }
   }
   Edit1->Tag=1;
  }
  else Edit1->Tag=0;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cb1Click(TObject *Sender)
{
 int idx;
 if(Edit1->Tag==1)
 {
  if(cb1->Checked==true)Memo->Lines->Add("magicrepair 1");
  else
  {
   idx=Memo->Lines->IndexOf("magicrepair 1");
   if(idx!=-1)Memo->Lines->Delete(idx);
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cb2Click(TObject *Sender)
{
 int idx;
 if(Edit1->Tag==1)
 {
  if(cb2->Checked==true)Memo->Lines->Add("cheatmode 1");
  else
  {
   idx=Memo->Lines->IndexOf("cheatmode 1");
   if(idx!=-1)Memo->Lines->Delete(idx);
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Edit3->Text=Edit2->Text;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Edit2->Text=Edit1->Text+"arena2\\";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Memo->Lines->SaveToFile(OpenDialog->FileName);
 Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
 int i;
 AnsiString s;
 if(Edit1->Tag==1)
 {
  for(i=0;i<Memo->Lines->Count;i++)
  {
   s=Memo->Lines->Strings[i];
   if(AnsiLowerCase(StrLeft(s,5))=="path ")break;
  }
  Memo->Lines->Strings[i]="path "+AnsiLowerCase(Edit2->Text);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
 int i;
 AnsiString s;
 if(Edit1->Tag==1)
 {
  for(i=0;i<Memo->Lines->Count;i++)
  {
   s=Memo->Lines->Strings[i];
   if(AnsiLowerCase(StrLeft(s,7))=="pathcd ")break;
  }
  Memo->Lines->Strings[i]="pathCD "+AnsiLowerCase(Edit3->Text);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
 ClientHeight=Panel1->Height;        
}
//---------------------------------------------------------------------------

