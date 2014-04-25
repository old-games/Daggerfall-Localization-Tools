//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TButton *Button2;
        TCheckBox *FixBox;
        TBevel *Bevel1;
        TPageControl *PageControl1;
        TMemo *Log;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TSpeedButton *Button43;
        TSpeedButton *Button33;
        TSpeedButton *Button23;
        TListBox *ListBox2;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TListBox *ListBox1;
        TListBox *ListBox3;
        TListBox *ListBox4;
        TEdit *Resource2Name;
        TSpeedButton *Button22;
        TEdit *Resource3Name;
        TSpeedButton *Button32;
        TEdit *Resource4Name;
        TSpeedButton *Button42;
        TPanel *Panel2;
        TMemo *Resource1Name;
        TSpeedButton *Button13;
        TLabel *Label1;
        TPanel *Resource1Size;
        TSpeedButton *Button12;
        TSpeedButton *Button11;
        TSpeedButton *SpeedButton14;
        TSpeedButton *SpeedButton24;
        TSpeedButton *SpeedButton34;
        TSpeedButton *SpeedButton44;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ListBox2Click(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall ListBox3Click(TObject *Sender);
        void __fastcall Button33Click(TObject *Sender);
        void __fastcall Button32Click(TObject *Sender);
        void __fastcall Button43Click(TObject *Sender);
        void __fastcall ListBox4Click(TObject *Sender);
        void __fastcall Button42Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall SpeedButton14Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
