//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Log;
        TButton *Button2;
        TTimer *Timer1;
        TOpenDialog *OpenDialog;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TPanel *Panel1;
        TLabel *Label1;
        TBevel *Bevel1;
        TBevel *Bevel2;
        TButton *Button1;
        TComboBox *Regions;
        TPageControl *PageControl2;
        TTabSheet *TabSheet3;
        TLabel *Label3;
        TListBox *LocationRecordList;
        TTabSheet *TabSheet4;
        TTabSheet *TabSheet5;
        TTabSheet *TabSheet6;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label5;
        TButton *Button3;
        TMemo *LocationList;
        TEdit *Edit1;
        TEdit *Edit2;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TMemo *MonstersList;
        TButton *Button10;
        TListBox *DungeonRecordList;
        TLabel *Label6;
        TButton *Button11;
        TButton *Button12;
        TButton *Button13;
        TButton *Button14;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall RegionsChange(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall LocationListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall LocationListClick(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall LocationListKeyPress(TObject *Sender, char &Key);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
