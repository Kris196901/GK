//---------------------------------------------------------------------------

#ifndef AboutDemoFormH
#define AboutDemoFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "cxControls.hpp"
//---------------------------------------------------------------------------
class TformAboutDemo : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *redDescription;
private:	// User declarations
	void __fastcall AssignBounds();
public:		// User declarations
	__fastcall TformAboutDemo(TComponent* Owner);
};

void ShowAboutDemoForm();
//---------------------------------------------------------------------------
#endif
