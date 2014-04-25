//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>
#include "CSPIN.h"
//#include "iComponent.hpp"
//#include "iCustomComponent.hpp"
//#include "iGradient.hpp"
//#include "iVCLComponent.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TPanel *Panel2;
        TButton *Button5;
        TButton *Button6;
        TPanel *Panel1;
        TPanel *Panel3;
        TPanel *Panel4;
        TMemo *Memo;
        TPanel *Panel5;
        TMemo *Log;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TPanel *CP;
        TLabel *Label1;
        TPanel *PC;
        TLabel *Label2;
        TTimer *Timer;
        TSpeedButton *SpeedButton4;
        TBevel *Bevel1;
        TMemo *Memo1;
        TSpeedButton *SpeedButton5;
        TLabel *Label3;
        TPanel *LC;
        TCSpinEdit *PCMax;
        TEdit *Title;
        TEdit *Author;
        TLabel *Label4;
        TLabel *Label5;
        TButton *Button2;
        TButton *Button4;
        TBevel *Bevel2;
        TLabel *Label6;
        TBevel *Bevel3;
        TLabel *Label7;
        TButton *Button8;
        TBevel *Bevel4;
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall TimerTimer(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall MemoChange(TObject *Sender);
        void __fastcall PCMaxChange(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
