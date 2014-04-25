//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Common Files\\types.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iLedMatrix"
#pragma link "iPositionComponent"
#pragma link "iScaleComponent"
#pragma link "iSlider"
#pragma link "iVCLComponent"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct{
 word High,Low;
}TLetterMatrix;

typedef struct{
 word Position;
 word Code;
 TLetterMatrix LetterMatrix[16];
 word Width;
}TFontMatrix;

const int FMMax=239;

FILE *df;
TFontMatrix FontMatrix[240];
word FontHeight;
word FontWidth;
byte Buf[8193];
int BytesReaded;
int LMMax;
bool AllowDraw;
bool MouseKeyPressed;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 int i,j;
 if(OpenDialog->Execute())
 {
  if((df=fopen(OpenDialog->FileName.c_str(),"rb+"))==NULL)
   Memo->Lines->Add("Ошибка открытия файла шрифта!");
  else
  {
   Memo->Lines->Add("Загрузка шрифта...");
   fread(&FontWidth,sizeof(FontWidth),1,df);
   fread(&FontHeight,sizeof(FontHeight),1,df);
   Label1->Caption="Размерность шрифта "+IntToStr(FontWidth)+"x"+IntToStr(FontHeight);
   FontMatrixList->Items->Clear();
   for(i=0;i<=FMMax;i++)
   {
    fread(&FontMatrix[i].Position,sizeof(FontMatrix[i].Position),1,df);
    fread(&FontMatrix[i].Width,sizeof(FontMatrix[i].Width),1,df);
    FontMatrix[i].Code=33+i;
   }
   LMMax=(FontMatrix[1].Position-FontMatrix[0].Position-1) >> 1;
   for(i=0;i<=FMMax;i++)
   {
    fseek(df,FontMatrix[i].Position,SEEK_SET);
    for(j=0;j<=LMMax;j++)
    {
     fread(&FontMatrix[i].LetterMatrix[j].High,sizeof(FontMatrix[i].LetterMatrix[j].High),1,df);
    }
    FontMatrixList->Items->Add(
      "Символ №"+IntToStr(33+i)+" '"+(char)(FontMatrix[i].Code & 0x00FF)+"'");
   }
   BytesReaded=fread(Buf,sizeof(Buf),1,df);
   Memo->Lines->Add("Загрузка шрифта завершена.");
   fclose(df);
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FontMatrixListClick(TObject *Sender)
{
 int index;
 int i,j;

 for(j=0;j<iLedMatrix->RowCount;j++)
   for(i=0;i<iLedMatrix->ColCount;i++)
     iLedMatrix->IndicatorActive[j][i]=false;
 index=FontMatrixList->ItemIndex;
 iSlider->Position=FontMatrix[index].Width;
 for(j=0;j<=LMMax;j++)
 {
  iLedMatrix->IndicatorActive[j][ 0]=((FontMatrix[index].LetterMatrix[j].High & 0x8000)!=0);
  iLedMatrix->IndicatorActive[j][ 1]=((FontMatrix[index].LetterMatrix[j].High & 0x4000)!=0);
  iLedMatrix->IndicatorActive[j][ 2]=((FontMatrix[index].LetterMatrix[j].High & 0x2000)!=0);
  iLedMatrix->IndicatorActive[j][ 3]=((FontMatrix[index].LetterMatrix[j].High & 0x1000)!=0);
  iLedMatrix->IndicatorActive[j][ 4]=((FontMatrix[index].LetterMatrix[j].High & 0x0800)!=0);
  iLedMatrix->IndicatorActive[j][ 5]=((FontMatrix[index].LetterMatrix[j].High & 0x0400)!=0);
  iLedMatrix->IndicatorActive[j][ 6]=((FontMatrix[index].LetterMatrix[j].High & 0x0200)!=0);
  iLedMatrix->IndicatorActive[j][ 7]=((FontMatrix[index].LetterMatrix[j].High & 0x0100)!=0);
  iLedMatrix->IndicatorActive[j][ 8]=((FontMatrix[index].LetterMatrix[j].High & 0x0080)!=0);
  iLedMatrix->IndicatorActive[j][ 9]=((FontMatrix[index].LetterMatrix[j].High & 0x0040)!=0);
  iLedMatrix->IndicatorActive[j][10]=((FontMatrix[index].LetterMatrix[j].High & 0x0020)!=0);
  iLedMatrix->IndicatorActive[j][11]=((FontMatrix[index].LetterMatrix[j].High & 0x0010)!=0);
  iLedMatrix->IndicatorActive[j][12]=((FontMatrix[index].LetterMatrix[j].High & 0x0008)!=0);
  iLedMatrix->IndicatorActive[j][13]=((FontMatrix[index].LetterMatrix[j].High & 0x0004)!=0);
  iLedMatrix->IndicatorActive[j][14]=((FontMatrix[index].LetterMatrix[j].High & 0x0002)!=0);
  iLedMatrix->IndicatorActive[j][15]=((FontMatrix[index].LetterMatrix[j].High & 0x0001)!=0);

/*  iLedMatrix->IndicatorActive[j][16]=((FontMatrix[index].LetterMatrix[j].sHigh & 0x80)!=0);
  iLedMatrix->IndicatorActive[j][17]=((FontMatrix[index].LetterMatrix[j].sHigh & 0x40)!=0);
  iLedMatrix->IndicatorActive[j][18]=((FontMatrix[index].LetterMatrix[j].sHigh & 0x20)!=0);
  iLedMatrix->IndicatorActive[j][19]=((FontMatrix[index].LetterMatrix[j].sHigh & 0x10)!=0);
  iLedMatrix->IndicatorActive[j][20]=((FontMatrix[index].LetterMatrix[j].sHigh & 0x08)!=0);
  iLedMatrix->IndicatorActive[j][21]=((FontMatrix[index].LetterMatrix[j].sHigh & 0x04)!=0);
  iLedMatrix->IndicatorActive[j][22]=((FontMatrix[index].LetterMatrix[j].sHigh & 0x02)!=0);
  iLedMatrix->IndicatorActive[j][23]=((FontMatrix[index].LetterMatrix[j].sHigh & 0x01)!=0);
  iLedMatrix->IndicatorActive[j][24]=((FontMatrix[index].LetterMatrix[j].sLow & 0x80)!=0);
  iLedMatrix->IndicatorActive[j][25]=((FontMatrix[index].LetterMatrix[j].sLow & 0x40)!=0);
  iLedMatrix->IndicatorActive[j][26]=((FontMatrix[index].LetterMatrix[j].sLow & 0x20)!=0);
  iLedMatrix->IndicatorActive[j][27]=((FontMatrix[index].LetterMatrix[j].sLow & 0x10)!=0);
  iLedMatrix->IndicatorActive[j][28]=((FontMatrix[index].LetterMatrix[j].sLow & 0x08)!=0);
  iLedMatrix->IndicatorActive[j][29]=((FontMatrix[index].LetterMatrix[j].sLow & 0x04)!=0);
  iLedMatrix->IndicatorActive[j][30]=((FontMatrix[index].LetterMatrix[j].sLow & 0x02)!=0);
  iLedMatrix->IndicatorActive[j][31]=((FontMatrix[index].LetterMatrix[j].sLow & 0x01)!=0);
  */
 };
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
 iLedMatrix->IndicatorHeight=10;
 iLedMatrix->IndicatorWidth=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::iSliderPositionChange(TObject *Sender)
{
//  Label2->Caption="Разрешенная ширина символа:"+IntToStr((int)iSlider->Position);
  FontMatrix[FontMatrixList->ItemIndex].Width=(int)iSlider->Position;
  iSlider->Position=(int)iSlider->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int i,j;

 if(SaveDialog->Execute())
 {
  Memo->Lines->Add("Сохранение шрифта...");
  df=fopen(SaveDialog->FileName.c_str(),"wb+");
  fwrite(&FontWidth,sizeof(FontWidth),1,df);
  fwrite(&FontHeight,sizeof(FontHeight),1,df);
  for(i=0;i<=FMMax;i++)
  {
   fwrite(&FontMatrix[i].Position,sizeof(FontMatrix[i].Position),1,df);
   fwrite(&FontMatrix[i].Width,sizeof(FontMatrix[i].Width),1,df);
  }
  for(i=0;i<=FMMax;i++)
   for(j=0;j<=LMMax;j++)
    fwrite(&FontMatrix[i].LetterMatrix[j].High,sizeof(FontMatrix[i].LetterMatrix[j].High),1,df);
  fwrite(Buf,BytesReaded,1,df);
  fclose(df);
  Memo->Lines->Add("Сохранение шрифта завершено.");
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::iLedMatrixMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 MouseKeyPressed=true;
 if(Button==mbLeft)AllowDraw=true;
 if(Button==mbRight)AllowDraw=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::iLedMatrixMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 MouseKeyPressed=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::iLedMatrixMouseMoveIndicator(int Row, int Col)
{
 if(MouseKeyPressed)
 {
  iLedMatrix->IndicatorActive[Row][Col]=AllowDraw;
  FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=0x0000;
//High
 if(iLedMatrix->IndicatorActive[Row][0])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x8000;
 if(iLedMatrix->IndicatorActive[Row][1])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x4000;
 if(iLedMatrix->IndicatorActive[Row][2])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x2000;
 if(iLedMatrix->IndicatorActive[Row][3])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x1000;
 if(iLedMatrix->IndicatorActive[Row][4])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0800;
 if(iLedMatrix->IndicatorActive[Row][5])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0400;
 if(iLedMatrix->IndicatorActive[Row][6])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0200;
 if(iLedMatrix->IndicatorActive[Row][7])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0100;
 if(iLedMatrix->IndicatorActive[Row][8])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0080;
 if(iLedMatrix->IndicatorActive[Row][9])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0040;
 if(iLedMatrix->IndicatorActive[Row][10])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0020;
 if(iLedMatrix->IndicatorActive[Row][11])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0010;
 if(iLedMatrix->IndicatorActive[Row][12])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0008;
 if(iLedMatrix->IndicatorActive[Row][13])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0004;
 if(iLedMatrix->IndicatorActive[Row][14])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0002;
 if(iLedMatrix->IndicatorActive[Row][15])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0001;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::iLedMatrixClickIndicator(int Row, int Col)
{
 iLedMatrix->IndicatorActive[Row][Col]=AllowDraw;
 FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=0x0000;
//High
 if(iLedMatrix->IndicatorActive[Row][0])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x8000;
 if(iLedMatrix->IndicatorActive[Row][1])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x4000;
 if(iLedMatrix->IndicatorActive[Row][2])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x2000;
 if(iLedMatrix->IndicatorActive[Row][3])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x1000;
 if(iLedMatrix->IndicatorActive[Row][4])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0800;
 if(iLedMatrix->IndicatorActive[Row][5])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0400;
 if(iLedMatrix->IndicatorActive[Row][6])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0200;
 if(iLedMatrix->IndicatorActive[Row][7])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0100;
 if(iLedMatrix->IndicatorActive[Row][8])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0080;
 if(iLedMatrix->IndicatorActive[Row][9])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0040;
 if(iLedMatrix->IndicatorActive[Row][10])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0020;
 if(iLedMatrix->IndicatorActive[Row][11])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0010;
 if(iLedMatrix->IndicatorActive[Row][12])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0008;
 if(iLedMatrix->IndicatorActive[Row][13])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0004;
 if(iLedMatrix->IndicatorActive[Row][14])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0002;
 if(iLedMatrix->IndicatorActive[Row][15])
   FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High=
     FontMatrix[FontMatrixList->ItemIndex].LetterMatrix[Row].High + 0x0001;
}
//---------------------------------------------------------------------------

