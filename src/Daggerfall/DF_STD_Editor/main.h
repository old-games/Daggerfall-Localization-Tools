//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Log;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TListBox *ListBox;
        TEdit *SpellName;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *SpellCost;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *bdr;
        TEdit *adr;
        TLabel *Label5;
        TEdit *cld;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *bch;
        TLabel *Label8;
        TEdit *ach;
        TLabel *Label9;
        TEdit *clc;
        TLabel *Label10;
        TLabel *Label11;
        TEdit *bm1;
        TLabel *Label12;
        TEdit *bm2;
        TLabel *Label13;
        TEdit *clm;
        TLabel *Label14;
        TLabel *Label15;
        TEdit *am2;
        TLabel *Label16;
        TEdit *am1;
        TPanel *Panel1;
        TSpeedButton *Button3;
        TButton *Button1;
        TButton *Button2;
        TCheckBox *FixBox;
        TBevel *Bevel1;
        TSpeedButton *SpeedButton1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ListBoxClick(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
