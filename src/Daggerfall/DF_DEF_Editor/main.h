//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog;
        TMemo *Log;
        TPanel *Panel1;
        TBevel *Bevel1;
        TSaveDialog *SaveDialog;
        TPanel *Panel2;
        TButton *Button1;
        TButton *Button2;
        TCheckBox *FixBox;
        TApplicationEvents *ApplicationEvents1;
        TCheckBox *SelectBox;
        TListBox *ListBox;
        TEdit *ItemName;
        TSpeedButton *Button3;
        TSpeedButton *SpeedButton1;
        void __fastcall ListBoxClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall ApplicationEvents1ShortCut(TWMKey &Msg,
          bool &Handled);
        void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
