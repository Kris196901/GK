//---------------------------------------------------------------------------

#ifndef EBarsDemoRatingH
#define EBarsDemoRatingH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TEBarsDemoRatingForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TMemo *memRateDescrip;
	TButton *btnSend;
	TRadioGroup *rgRate;
	void __fastcall rgRateChanged(TObject *Sender);
	void __fastcall btnSendClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TEBarsDemoRatingForm(TComponent* Owner);
	void __fastcall AdjustMessageBody(String &ABody, String ASearchStr, String AReplaceStr);
};
//---------------------------------------------------------------------------
extern PACKAGE TEBarsDemoRatingForm *EBarsDemoRatingForm;
//---------------------------------------------------------------------------
#endif
