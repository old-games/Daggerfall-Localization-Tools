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
//Map Directory Structure
typedef struct {
 char Name[12];
 word Unknown;
 dword Size;
 dword Position;
}TMapDir;
//---------------------------------------------------------------------------
int MonsterOffsets[43]={0x10BD,0x2A15,0x2A5F,0x2AA9,0x2AF3,0x2B3D,0x2B87,0x2BD1,
                      0x2C1B,0x2C65,0x2CAF,0x2CF9,0x2D43,0x2D8D,0x2DD7,0x2E21,
                      0x2E6B,0x2EB5,0x2EFF,0x2F49,0x2F93,0x2FDD,0x3027,0x3071,
                      0x30BB,0x3105,0x314F,0x3199,0x31E3,0x322D,0x3277,0x32C1,
                      0x330B,0x5D4E,0x5D98,0x5DE2,0x5E2C,0x5E76,0x5EC0,0x5F0A,
                      0x5F54,0x5F9E,0x6138};
//---------------------------------------------------------------------------
FILE *f,*fm;
FILE *fmap;
unsigned int BSAHeader;
TMapDir MapDir[62][4];
int locscount,dungcount;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if(Button2->Tag==0)
 {
  if(OpenDialog->Execute())
  {
   Log->Lines->Add("Подключение к MAPS.BSA ...");
   f=fopen(OpenDialog->FileName.c_str(),"rb+");
   fseek(f,0x1519930,SEEK_SET);
   for(int j=0;j<62;j++)
   {
    for(int i=0;i<4;i++)
    {
     fread(MapDir[j][i].Name,sizeof(MapDir[j][i].Name),1,f);
     fread(&MapDir[j][i].Unknown,sizeof(MapDir[j][i].Unknown),1,f);
     fread(&MapDir[j][i].Size,sizeof(MapDir[j][i].Size),1,f);
     if(j==0)
     {
      if(i==0)
      {
       MapDir[j][i].Position=4;
      }else
      {
       MapDir[j][i].Position=MapDir[j][i-1].Position+MapDir[j][i-1].Size;
      }
     }else
     {
      if(i==0)
      {
       MapDir[j][i].Position=MapDir[j-1][3].Position+MapDir[j-1][3].Size;
      }else
      {
       MapDir[j][i].Position=MapDir[j][i-1].Position+MapDir[j][i-1].Size;
      }
     }
    }
   }
   Button2->Caption="Отключиться от MAPS.BSA";
   Button2->Tag=1;
   Log->Lines->Add("Подключение завершено.");
   RegionsChange(NULL);
   Panel1->Enabled=true;
  }
 }else
 {
  Log->Lines->Add("Отключение от MAPS.BSA ...");
  fclose(f);
  Button2->Caption="Подключиться к MAPS.BSA";
  Button2->Tag=0;
  Log->Lines->Add("Отключение завершено.");
  Panel1->Enabled=false;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 byte *buf;
 int index,mappos,mapsize,i;
 AnsiString mapname;

 for(i=0;i<4;i++)
 {
  Log->Lines->Add("Извлечение файла "+mapname+" ...");
  index=Regions->ItemIndex;
  mapname=MapDir[index][i].Name;
  mappos=MapDir[index][i].Position;
  mapsize=MapDir[index][i].Size;
  fmap=fopen(mapname.c_str(),"wb+");
  if(mapsize>0)
  {
   buf=new byte[mapsize];
   fseek(f,mappos,SEEK_SET);
   fread(buf,mapsize,1,f);
   fwrite(buf,mapsize,1,fmap);
   delete[] buf;
  }
  fclose(fmap);
  Log->Lines->Add("Извлечение файла "+mapname+" завершено. ("+mapsize+" байт)");
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
 Regions->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RegionsChange(TObject *Sender)
{
 int j;
 int index,backup;
 char name[32];
 int point,pointnext;
 int losoffset,lrdoffset;
 int PreRecordCount;
 int LocationType;
 AnsiString tempname;
//---------------------------------------------------------------------------
//               Чтение названий локаций выбранного региона
//---------------------------------------------------------------------------
 Log->Lines->Add("Чтение 'Location Names' региона "+Regions->Text+" ...");
 index=MapDir[Regions->ItemIndex][3].Position;
 LocationList->Clear();
 fseek(f,index,SEEK_SET);
 fread(&locscount,sizeof(locscount),1,f);
 for(int i=0;i<locscount;i++)
 {
  fread(name,32,1,f);
  LocationList->Lines->Add(name);
  if(LocationList->Lines->Strings[i].Length()>32)
   LocationList->Lines->Strings[i]=LocationList->Lines->Strings[i].SubString(1,32);
 }
 LocationList->CaretPos.y=0;
 LocationListClick(NULL);
 Log->Lines->Add("Чтение закончено.");
//---------------------------------------------------------------------------
//               Чтение названий локаций выбранного региона
//---------------------------------------------------------------------------
 Log->Lines->Add("Чтение 'Location Record Data' региона "+Regions->Text+" ...");
 losoffset=MapDir[Regions->ItemIndex][0].Position;
 lrdoffset=losoffset+(4*locscount);
 LocationRecordList->Clear();
 DungeonRecordList->Clear();
 fseek(f,losoffset,SEEK_SET);
 while(ftell(f)<lrdoffset)
 {
  fread(&index,sizeof(index),1,f);
  backup=ftell(f);
  {
   fseek(f,lrdoffset+index,SEEK_SET);
   fread(&PreRecordCount,sizeof(PreRecordCount),1,f);
   fseek(f,PreRecordCount*6,SEEK_CUR);
   fseek(f,19,SEEK_CUR);
   fread(&LocationType,sizeof(LocationType),1,f);
   fseek(f,48,SEEK_CUR);
   fread(name,32,1,f);
   LocationRecordList->Items->Add(name);
   DungeonRecordList->Items->Add("");
   if(LocationRecordList->Items->Strings[LocationRecordList->Items->Count-1].Length()>32)
    LocationRecordList->Items->Strings[LocationRecordList->Items->Count-1]=
     LocationRecordList->Items->Strings[LocationRecordList->Items->Count-1].SubString(1,32);
//   if(LocationType==0x00008000){}
  }
  fseek(f,/*losoffset+*/backup,SEEK_SET);
 }
//---------------------------------------------------------------------------
//               Чтение названий подземелий выбранного региона
//---------------------------------------------------------------------------
 Log->Lines->Add("Чтение 'Dungeon Record Data' региона "+Regions->Text+" ...");
 losoffset=MapDir[Regions->ItemIndex][1].Position;
 fseek(f,losoffset,SEEK_SET);
 fread(&dungcount,sizeof(dungcount),1,f);
 lrdoffset=4+losoffset+(8*dungcount);
 while(ftell(f)<lrdoffset)
 {
  fread(&index,sizeof(index),1,f);
  backup=4+ftell(f);
  {
   fseek(f,lrdoffset+index,SEEK_SET);
   fread(&PreRecordCount,sizeof(PreRecordCount),1,f);
   fseek(f,PreRecordCount*6,SEEK_CUR);
   fseek(f,19,SEEK_CUR);
   fread(&LocationType,sizeof(LocationType),1,f);
   fseek(f,48,SEEK_CUR);
   fread(name,32,1,f);tempname=name;
   for(j=0;j<LocationRecordList->Items->Count;j++)
    if(tempname==LocationRecordList->Items->Strings[j])break;
   DungeonRecordList->Items->Strings[j]=name;
   if(DungeonRecordList->Items->Strings[DungeonRecordList->Items->Count-1].Length()>32)
    DungeonRecordList->Items->Strings[DungeonRecordList->Items->Count-1]=
     DungeonRecordList->Items->Strings[DungeonRecordList->Items->Count-1].SubString(1,32);
  }
  fseek(f,backup,SEEK_SET);
 }
 Log->Lines->Add("Чтение закончено.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 int index=MapDir[Regions->ItemIndex][3].Position;
 int locscount=LocationList->Lines->Count;
 char name[32];
 Log->Lines->Add("Идет запись названий локаций региона "+Regions->Text+" ...");
 fseek(f,index,SEEK_SET);
 fwrite(&locscount,sizeof(locscount),1,f);
 for(int i=0;i<locscount;i++)
 {
  for(int j=0;j<32;j++)name[j]='\0';
  strcpy(name,LocationList->Lines->Strings[i].c_str());
  fwrite(name,32,1,f);
 }
 Log->Lines->Add("Запись закончена.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 Timer1->Enabled=false;
 if(LocationList->Lines->Strings[LocationList->CaretPos.y].Length()>31)
  Edit2->Font->Color=clRed;
 else
  Edit2->Font->Color=clBlack;
 Edit1->Text=IntToStr(LocationList->CaretPos.y);
 Edit2->Text=IntToStr(LocationList->Lines->Strings[LocationList->CaretPos.y].Length());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LocationListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LocationListClick(TObject *Sender)
{
 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 int i;
 Log->Lines->Add("Перенос имен локаций в MAPPITEM...");
 LocationRecordList->Clear();
 for (i=0;i<LocationList->Lines->Count;i++)
  LocationRecordList->Items->Add(LocationList->Lines->Strings[i]);
 Log->Lines->Add("Перенос имен локаций в MAPPITEM завершен.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 int index,backup;
 char name[32];
 int point,pointnext;
 int losoffset,lrdoffset;
 int PreRecordCount;
 int LocationType;
 int current;
//---------------------------------------------------------------------------
//               Запись названий локаций выбранного региона
//---------------------------------------------------------------------------
 Log->Lines->Add("Запись 'Location Record Data' региона "+Regions->Text+" ...");
 losoffset=MapDir[Regions->ItemIndex][0].Position;
 lrdoffset=losoffset+(4*locscount);
 fseek(f,losoffset,SEEK_SET);
 current=0;
 while(ftell(f)<lrdoffset)
 {
  fread(&index,sizeof(index),1,f);
  backup=ftell(f);
  {
   fseek(f,lrdoffset+index,SEEK_SET);
   fread(&PreRecordCount,sizeof(PreRecordCount),1,f);
   fseek(f,PreRecordCount*6,SEEK_CUR);
   fseek(f,19,SEEK_CUR);
   fread(&LocationType,sizeof(LocationType),1,f);
   fseek(f,48,SEEK_CUR);
   strcpy(name,LocationRecordList->Items->Strings[current].c_str());
   fwrite(name,32,1,f);
  }
  fseek(f,backup,SEEK_SET);
  current++;
 }
 Log->Lines->Add("Запись закончена.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LocationListKeyPress(TObject *Sender, char &Key)
{
 if(Key!='\b')
  if(LocationList->Lines->Strings[Edit1->Text.ToInt()].Length()>30)
   Key='\0';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 LocationList->Lines->SaveToFile("Region"+IntToStr(Regions->ItemIndex)+".map");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
 char name[24];
 if(Button8->Tag==0)
 {
  if(OpenDialog->Execute())
  {
   Log->Lines->Add("Подключение к MONSTER.BSA ...");
   fm=fopen(OpenDialog->FileName.c_str(),"rb+");
   MonstersList->Clear();
   for(int j=0;j<43;j++)
   {
    fseek(fm,MonsterOffsets[j],SEEK_SET);
    fread(name,24,1,fm);
    MonstersList->Lines->Add(name);
   }
   Button8->Caption="Отключиться от MONSTER.BSA";
   Button8->Tag=1;
   Log->Lines->Add("Подключение завершено.");
  }
 }else
 {
  Log->Lines->Add("Отключение от MONSTER.BSA ...");
  fclose(fm);
  Button8->Caption="Подключиться к MONSTER.BSA";
  Button8->Tag=0;
  Log->Lines->Add("Отключение завершено.");
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)
{
 char name[24];
 Log->Lines->Add("Идет запись названий монстров ...");
 for(int i=0;i<43;i++)
 {
  for(int j=0;j<24;j++)name[j]='\0';
  strcpy(name,MonstersList->Lines->Strings[i].c_str());
  fseek(fm,MonsterOffsets[i],SEEK_SET);
  fwrite(name,24,1,fm);
 }
 Log->Lines->Add("Запись закончена.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
 int i;
 Log->Lines->Add("Перенос имен локаций в MAPDITEM...");
 for(i=0;i<LocationList->Lines->Count;i++)
  if(DungeonRecordList->Items->Strings[i].Length()!=0)
   DungeonRecordList->Items->Strings[i]=LocationList->Lines->Strings[i];
 Log->Lines->Add("Перенос имен локаций в MAPDITEM завершен.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 int index,backup;
 char name[32];
 int point,pointnext;
 int losoffset,lrdoffset;
 int PreRecordCount;
 int LocationType;
 int current;
//---------------------------------------------------------------------------
//               Запись названий локаций выбранного региона
//---------------------------------------------------------------------------
 Log->Lines->Add("Запись 'Dungeon Record Data' региона "+Regions->Text+" ...");
 losoffset=MapDir[Regions->ItemIndex][1].Position;
 fseek(f,losoffset,SEEK_SET);
 fread(&dungcount,sizeof(dungcount),1,f);
 lrdoffset=4+losoffset+(8*dungcount);
 current=0;
 while(ftell(f)<lrdoffset)
 {
  fread(&index,sizeof(index),1,f);
  backup=4+ftell(f);
  {
   fseek(f,lrdoffset+index,SEEK_SET);
   fread(&PreRecordCount,sizeof(PreRecordCount),1,f);
   fseek(f,PreRecordCount*6,SEEK_CUR);
   fseek(f,19,SEEK_CUR);
   fread(&LocationType,sizeof(LocationType),1,f);
   fseek(f,48,SEEK_CUR);
   while(DungeonRecordList->Items->Strings[current].Length()==0)current++;
   strcpy(name,DungeonRecordList->Items->Strings[current].c_str());
   fwrite(name,32,1,f);
  }
  fseek(f,backup,SEEK_SET);
  current++;
  Application->ProcessMessages();
 }
 Log->Lines->Add("Запись закончена.");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button13Click(TObject *Sender)
{
 TButton *sb=(TButton *)Sender;
 AnsiString f;
 int i,j,k;
 bool found=false;
 f=LocationList->Text;
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
 LocationList->Text=f;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
 TButton *sb=(TButton *)Sender;
 AnsiString f;
 int i,j,k;
 bool found=false;
 f=MonstersList->Text;
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
 MonstersList->Text=f;
}
//---------------------------------------------------------------------------

