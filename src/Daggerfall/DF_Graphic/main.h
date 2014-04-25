//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *DirDlg;
        TMemo *Log;
        TPanel *Panel2;
        TSpeedButton *SpeedButton2;
        TBevel *Bevel1;
        TListBox *IMGList;
        TPanel *Panel1;
        TScrollBox *ScrollBox1;
        TImage *Image;
        TPanel *Panel3;
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall IMGListClick(TObject *Sender);
        void __fastcall cseChange(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
