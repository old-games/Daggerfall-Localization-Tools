//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "DirDialog.hpp"
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TSaveDialog *SaveDialog;
        TOpenDialog *OpenDialog;
        TPanel *Panel2;
        TSpeedButton *Button4;
        TSpeedButton *Button3;
        TButton *Button1;
        TButton *Button2;
        TCheckBox *FixBox;
        TBevel *Bevel1;
        TMemo *Memo;
        TMemo *Log;
        TPanel *Panel1;
        TListBox *ListBox;
        TListBox *QRCList;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TPanel *Panel3;
        TLabel *Label2;
        TLabel *Label1;
        TOpenDialog *DirDlg;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ListBoxClick(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall QRCListClick(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall FixBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
