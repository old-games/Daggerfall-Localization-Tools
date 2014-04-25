//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iLedMatrix.hpp"
#include "iPositionComponent.hpp"
#include "iScaleComponent.hpp"
#include "iSlider.hpp"
#include "iVCLComponent.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TButton *Button2;
        TButton *Button1;
        TPanel *Panel2;
        TiLedMatrix *iLedMatrix;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TMemo *Memo;
        TLabel *Label1;
        TListBox *FontMatrixList;
        TiSlider *iSlider;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FontMatrixListClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall iSliderPositionChange(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall iLedMatrixMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall iLedMatrixMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall iLedMatrixMouseMoveIndicator(int Row, int Col);
        void __fastcall iLedMatrixClickIndicator(int Row, int Col);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
