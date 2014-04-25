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
#define SEC1OFF         0x1A9604
#define SEC1END         0x1B1C2A
#define SEC2OFF         0x1B682A
#define SEC2END         0x1B9E2A
#define SEC3OFF         0x1BA13A
#define SEC3END         0x1BA9BE
#define SEC4OFF         0x1BCEE0
#define SEC4END         0x1BD6A0
typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned int   dword;
typedef char           string[256];
typedef struct {
 byte *Name;
 dword Size;
}TRes1;
typedef struct {
 char Name[22];
 byte block[26];
}TRes2;
typedef struct {
 byte block01[67];
 char Name[32];
 byte block02[10];
}TRes3;
typedef struct {
 char Name[32];
}TRes4;
//---------------------------------------------------------------------------
FILE *f;
TRes1 res1[3000];
TRes2 res2[1000];
TRes3 res3[1000];
TRes4 res4[1000];
int res1count=0;
int res2count=0;
int res3count=0;
int res4count=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int i,j=0,k;
 byte c=0;
 AnsiString s="";
 bool eol=false;
 dword curpos;
 if(Button2->Tag==0)
 {
  if(OpenDialog->Execute())
  {
   Log->Lines->Add("Подключение к FALL.EXE ...");
   f=fopen(OpenDialog->FileName.c_str(),"rb+");
   ListBox1->Items->Clear();
   ListBox2->Items->Clear();
   ListBox3->Items->Clear();
   ListBox4->Items->Clear();
   //Чтение секции №1
   i=0;
   Log->Lines->Add("Чтение данных секции №1...");
   fseek(f,SEC1OFF,SEEK_SET);
   while(ftell(f)<SEC1END)
   {
    curpos=ftell(f);
    j=0;
    eol=false;
    while(!eol)
    {
     fread(&c,1,1,f);
     if(c!=0)j++;
     else
     {
      while(c==0){fread(&c,1,1,f);j++;}
      fseek(f,curpos,SEEK_SET);
      eol=true;
     }
    }
    res1[i].Size=j;
    res1[i].Name=new byte[j];
    for(k=0;k<j;k++)res1[i].Name[k]=0;
    fread(res1[i].Name,res1[i].Size,1,f);
    s=(char *)res1[i].Name;
    if(s.Length()>20)
     ListBox1->Items->Add("Запись №"+IntToStr(i)+" ["+s.SubString(1,20)+"...]");
    else
     ListBox1->Items->Add("Запись №"+IntToStr(i)+" ["+s+"]");
    i++;
   }
   res1count=i;
   Log->Lines->Add(IntToStr(res1count)+" записей считано.");
   ListBox1->ItemIndex=0;
   ListBox1Click(NULL);
   //Чтение секции №2
   i=0;
   Log->Lines->Add("Чтение данных секции №2...");
   fseek(f,SEC2OFF,SEEK_SET);
   while(ftell(f)<SEC2END)
   {
    fread(&res2[i],sizeof(res2[i]),1,f);
    ListBox2->Items->Add("Запись №"+IntToStr(i)+" ["+res2[i].Name+"]");
    i++;
   }
   res2count=i;
   Log->Lines->Add(IntToStr(res2count)+" записей считано.");
   ListBox2->ItemIndex=0;
   ListBox2Click(NULL);
   //Чтение секции №3
   i=0;
   Log->Lines->Add("Чтение данных секции №3...");
   fseek(f,SEC3OFF,SEEK_SET);
   while(ftell(f)<SEC3END)
   {
    fread(&res3[i],sizeof(res3[i]),1,f);
    ListBox3->Items->Add("Запись №"+IntToStr(i)+" ["+res3[i].Name+"]");
    i++;
   }
   res3count=i;
   Log->Lines->Add(IntToStr(res3count)+" записей считано.");
   ListBox3->ItemIndex=0;
   ListBox3Click(NULL);
   //Чтение секции №4
   i=0;
   Log->Lines->Add("Чтение данных секции №4...");
   fseek(f,SEC4OFF,SEEK_SET);
   while(ftell(f)<SEC4END)
   {
    fread(&res4[i],sizeof(res4[i]),1,f);
    ListBox4->Items->Add("Запись №"+IntToStr(i)+" ["+res4[i].Name+"]");
    i++;
   }
   res4count=i;
   Log->Lines->Add(IntToStr(res4count)+" записей считано.");
   ListBox4->ItemIndex=0;
   ListBox4Click(NULL);
   //-----------------------
   Button2->Caption="Отключиться от FALL.EXE";
   Button2->Tag=1;
   Log->Lines->Add("Подключение завершено.");
  }
 }else
 {
  Log->Lines->Add("Отключение от FALL.EXE ...");
  fclose(f);
  for(i=0;i<res1count;i++)delete[] res1[i].Name;
  Button2->Caption="Подключиться к FALL.EXE";
  Button2->Tag=0;
  Log->Lines->Add("Отключение завершено.");
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox2Click(TObject *Sender)
{
 int index=ListBox2->ItemIndex;
 Resource2Name->Text=res2[index].Name;
 if(FixBox->Checked)
 {
  SpeedButton24->Tag=0;
  SpeedButton24->Tag=~SpeedButton24->Tag;
  SpeedButton14Click(SpeedButton24);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button23Click(TObject *Sender)
{
 int index=ListBox2->ItemIndex;
 strcpy(res2[index].Name,Resource2Name->Text.c_str());
 res2[index].Name[21]='\0';
 ListBox2->SetFocus();
 ListBox2->ItemIndex++;
 ListBox2Click(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button22Click(TObject *Sender)
{
 //Сохранение секции №2
 Log->Lines->Add("Сохранение секции №2 файла ...");
 fseek(f,SEC2OFF,SEEK_SET);
 for(int i=0;i<res2count;i++)
 {
  fwrite(&res2[i],sizeof(res2[i]),1,f);
 }
 Log->Lines->Add("Сохранение завершено.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox3Click(TObject *Sender)
{
 int index=ListBox3->ItemIndex;
 Resource3Name->Text=res3[index].Name;
 if(FixBox->Checked)
 {
  SpeedButton34->Tag=0;
  SpeedButton34->Tag=~SpeedButton34->Tag;
  SpeedButton14Click(SpeedButton34);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender)
{
 int index=ListBox3->ItemIndex;
 strcpy(res3[index].Name,Resource3Name->Text.c_str());
 res3[index].Name[31]='\0';
 ListBox3->SetFocus();
 ListBox3->ItemIndex++;
 ListBox3Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
 //Сохранение секции №3
 Log->Lines->Add("Сохранение секции №3 файла ...");
 fseek(f,SEC3OFF,SEEK_SET);
 for(int i=0;i<res3count;i++)
 {
  fwrite(&res3[i],sizeof(res3[i]),1,f);
 }
 Log->Lines->Add("Сохранение завершено.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button43Click(TObject *Sender)
{
 int index=ListBox4->ItemIndex;
 strcpy(res4[index].Name,Resource4Name->Text.c_str());
 res4[index].Name[31]='\0';
 ListBox4->SetFocus();
 ListBox4->ItemIndex++;
 ListBox4Click(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox4Click(TObject *Sender)
{
 int index=ListBox4->ItemIndex;
 Resource4Name->Text=res4[index].Name;
 if(FixBox->Checked)
 {
  SpeedButton44->Tag=0;
  SpeedButton44->Tag=~SpeedButton44->Tag;
  SpeedButton14Click(SpeedButton44);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button42Click(TObject *Sender)
{
 //Сохранение секции №4
 Log->Lines->Add("Сохранение секции №4 файла ...");
 fseek(f,SEC4OFF,SEEK_SET);
 for(int i=0;i<res4count;i++)
 {
  fwrite(&res4[i],sizeof(res4[i]),1,f);
 }
 Log->Lines->Add("Сохранение завершено.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
 AnsiString s,d;
 dword i;
 char c;
 int index=ListBox1->ItemIndex;
 Resource1Name->Clear();d="";
 for(i=0;i<res1[index].Size;i++)
 {
  switch(res1[index].Name[i])
  {
   case df0xF8:s=dft0xF8;break;
   case dfOffset:
   {
    s=dftOffset+IntToStr(res1[index].Name[i+1])+">";
    i++;
   }break;
   case df0xFA:
   {
    s=dft0xFA+IntToStr(res1[index].Name[i+1])+">";
    i++;
   }break;
   case dfCRRight:s=dftCRRight;break;
   case dfCRCenter:s=dftCRCenter;break;
   case dfEOB:s=dftEOB;break;
   case dfEOR:s=dftEOR;break;
   default:s=(char)res1[index].Name[i];
  }
  d=d+s;
 }
 Resource1Name->Text=Resource1Name->Text+d;
 Resource1Size->Caption=IntToStr(res1[index].Size-1);
 if(FixBox->Checked)
 {
  SpeedButton14->Tag=0;
  SpeedButton14->Tag=~SpeedButton14->Tag;
  SpeedButton14Click(SpeedButton14);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
 AnsiString f=Resource1Name->Text;
 dword i,j,index=ListBox1->ItemIndex,k;
 dword tsize;
 for(i=0;i<res1[index].Size;i++)res1[index].Name[i]=0;
 tsize=1+f.Length();j=0;
 for(i=1;i<tsize;i++)
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
   res1[index].Name[j]=f[i];j++;
  }else
  {
   if(f.SubString(i,6)==dft0xFA)
   {
    res1[index].Name[j]=df0xFA;
    i+=6;k=i;
    while(f[k]!='>')k++;
    j++;
    res1[index].Name[j]=(char)StrToInt(f.SubString(i,k-i));
    i=k;j++;
   }else
   if(f.SubString(i,6)==dftOffset)
   {
    res1[index].Name[j]=dfOffset;
    i+=6;k=i;
    while(f[k]!='>')k++;
    j++;
    res1[index].Name[j]=(char)StrToInt(f.SubString(i,k-i));
    i=k;j++;
   }else
   {
    if(f.SubString(i,6)==dft0xF8)
     res1[index].Name[j]=df0xF8;
    if(f.SubString(i,6)==dftCRRight)
     res1[index].Name[j]=dfCRRight;
    if(f.SubString(i,6)==dftCRCenter)
     res1[index].Name[j]=dfCRCenter;
    if(f.SubString(i,6)==dftEOB)
     res1[index].Name[j]=dfEOB;
    if(f.SubString(i,6)==dftEOR)
     res1[index].Name[j]=dfEOR;
    i+=5;j++;
   }
  }
  if(j==(res1[index].Size-1))break;
 }
 res1[index].Name[res1[index].Size-1]=0;
 ListBox1->SetFocus();
 ListBox1->ItemIndex++;
 ListBox1Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 //Сохранение секции №1
 Log->Lines->Add("Сохранение секции №1 файла ...");
 fseek(f,SEC1OFF,SEEK_SET);
 for(int i=0;i<res1count;i++)
 {
  fwrite(res1[i].Name,res1[i].Size,1,f);
 }
 Log->Lines->Add("Сохранение завершено.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
 AnsiString f=Resource1Name->Text;
 AnsiString s;
 int i;
 for(i=0;i<res1count;i++)
 {
  s=(char *)res1[i].Name;
  if(s==f)break;
 }
 if(i<res1count)
 {
  ListBox1->ItemIndex=i;
  ListBox1Click(NULL);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton14Click(TObject *Sender)
{
 TSpeedButton *sb=(TSpeedButton *)Sender;
 AnsiString f;
 int i,j,k;
 bool found=false;
 if(sb==SpeedButton14)f=Resource1Name->Text;
 if(sb==SpeedButton24)f=Resource2Name->Text;
 if(sb==SpeedButton34)f=Resource3Name->Text;
 if(sb==SpeedButton44)f=Resource4Name->Text;
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
 if(sb==SpeedButton14)Resource1Name->Text=f;
 if(sb==SpeedButton24)Resource2Name->Text=f;
 if(sb==SpeedButton34)Resource3Name->Text=f;
 if(sb==SpeedButton44)Resource4Name->Text=f;
}
//---------------------------------------------------------------------------



