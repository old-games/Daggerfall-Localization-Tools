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
        TMemo *Memo;
        TSaveDialog *SaveDialog;
        TPanel *Panel2;
        TButton *Button1;
        TButton *Button2;
        TSpeedButton *Button3;
        TCheckBox *FixBox;
        TApplicationEvents *ApplicationEvents1;
        TCheckBox *SelectBox;
        TListBox *ListBox;
        TSpeedButton *SpeedButton1;
        TTimer *Timer1;
        TPanel *LineWidth;
        TLabel *Label1;
        TButton *Button4;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit1;
        TEdit *Edit2;
        void __fastcall ListBoxClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ApplicationEvents1ShortCut(TWMKey &Msg,
          bool &Handled);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall MemoChange(TObject *Sender);
        void __fastcall MemoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
