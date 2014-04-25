//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "..\\..\\common files\\types.h"
#include "..\\..\\common files\\letters.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct {
  dword FileSize;
  bool PalAvail;
  bool Header;
  word XOffset;
  word YOffset;
  word Width;
  word Height;
  byte Format;
  byte Flags;
  word ImageSize;
  byte *ImageData;
  byte Palette[256][3];
}TDFImage;
//---------------------------------------------------------------------------
TDFImage DFImage;
FILE *f, *fpal;
AnsiString default_img="";
AnsiString default_path=".";
AnsiString root_path=".";
TSearchRec fsrc;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 root_path=GetCurrentDir();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
 DirDlg->FileName="Select directory...";
 if(DirDlg->Execute() && GetCurrentDir()/*DirDlg->Directory*/!=default_path)
 {
  default_path=GetCurrentDir();//DirDlg->Directory;
  IMGList->Items->Clear();
  if(FindFirst(default_path+"\\*.img",faAnyFile,fsrc)==0)
  {
   do
   {
    IMGList->Items->Add(fsrc.Name);
   }while(FindNext(fsrc)==0);
   FindClose(fsrc);
   IMGList->ItemIndex=0;IMGListClick(NULL);
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IMGListClick(TObject *Sender)
{
 AnsiString cd;
 int i,j,k,l;
 TColor pixel_color;//0x00BBGGRR
 if(default_img!=IMGList->Items->Strings[IMGList->ItemIndex])
 {
  cd=GetCurrentDir()+"\\";
  default_img=IMGList->Items->Strings[IMGList->ItemIndex];
  Log->Clear();
  Log->Lines->Add("Подключение к "+default_img+" ...");
  fclose(f);
  f=fopen((default_path+"\\"+default_img).c_str(),"rb+");
  fseek(f,0,SEEK_END);
  DFImage.FileSize=ftell(f);
  fseek(f,0,SEEK_SET);
  Log->Lines->Add("Размер файла: "+IntToStr(DFImage.FileSize)+" байт");
  Log->Lines->Add("Чтение заголовка ...");
//  DFImage.XOffset=0;
//  DFImage.YOffset=0;
//  DFImage.Width=320;
//  DFImage.Height=200;
//  DFImage.ImageSize=64000;
  switch(DFImage.FileSize)
  {
   case 720:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=9;
    DFImage.Height=80;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 990:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=45;
    DFImage.Height=22;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 1720:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=43;
    DFImage.Height=40;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 2140:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=107;
    DFImage.Height=20;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 2916:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=81;
    DFImage.Height=36;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 3200:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=40;
    DFImage.Height=80;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 3938:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=179;
    DFImage.Height=22;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 4280:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=107;
    DFImage.Height=40;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 4508:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=322;
    DFImage.Height=14;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 20480:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=320;
    DFImage.Height=64;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 26496:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=184;
    DFImage.Height=144;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 64000:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=320;
    DFImage.Height=200;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 64768:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=320;
    DFImage.Height=200;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=true;
    DFImage.Header=false;
   }break;
   case 68800:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=320;
    DFImage.Height=215;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   case 112128:
   {
    DFImage.XOffset=0;
    DFImage.YOffset=0;
    DFImage.Width=512;
    DFImage.Height=219;
    DFImage.ImageSize=DFImage.Width*DFImage.Height;
    DFImage.PalAvail=false;
    DFImage.Header=false;
   }break;
   default:
   {
    fread(&DFImage.XOffset,sizeof(DFImage.XOffset),1,f);
    fread(&DFImage.YOffset,sizeof(DFImage.YOffset),1,f);
    fread(&DFImage.Width,sizeof(DFImage.Width),1,f);
    fread(&DFImage.Height,sizeof(DFImage.Height),1,f);
    fread(&DFImage.Format,sizeof(DFImage.Format),1,f);
    fread(&DFImage.Flags,sizeof(DFImage.Flags),1,f);
    fread(&DFImage.ImageSize,sizeof(DFImage.ImageSize),1,f);
    DFImage.PalAvail=false;
    DFImage.Header=true;
   }
  }
  delete []DFImage.ImageData;
  DFImage.ImageData=new byte[DFImage.ImageSize];
  Log->Lines->Add("Чтение данных ...");
  fread(DFImage.ImageData,DFImage.ImageSize,1,f);
  if(DFImage.PalAvail){
   fread(DFImage.Palette,256*3,1,f);
  }else
  {
   fpal=fopen((root_path+"\\map.pal").c_str(),"rb+");
//   fseek(fpal,SEEK_SET,8);
   fread(DFImage.Palette,256*3,1,fpal);
   fclose(fpal);
  }
  fclose(f);
  Log->Lines->Add("Подключение завершено.");
  Form1->Caption="TES2:Daggerfall IMG-files Editor { "+default_img+" }";
  Application->Title="{ "+default_img+" }";
  Image->Height=2*DFImage.Height;
  Image->Width=2*DFImage.Width;
  k=0;
  for(j=0;j<Image->Height;j+=2)
  {
   for(i=0;i<Image->Width;i+=2)
   {
//    for(l=0;l<256;l++)if(DFImage.ImageData[k]==l)break;
     pixel_color=(TColor)RGB(DFImage.Palette[DFImage.ImageData[k]][0] << 2,
                             DFImage.Palette[DFImage.ImageData[k]][1] << 2,
                             DFImage.Palette[DFImage.ImageData[k]][2] << 2);
    Image->Canvas->Pixels[i][j]=pixel_color;
    Image->Canvas->Pixels[i+1][j]=pixel_color;
    Image->Canvas->Pixels[i][j+1]=pixel_color;
    Image->Canvas->Pixels[i+1][j+1]=pixel_color;
    k++;
   }
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cseChange(TObject *Sender)
{
 IMGListClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
 Form1->WindowState=wsMaximized;        
}
//---------------------------------------------------------------------------

