//---------------------------------------------------------------------------

#ifndef EBarsUtilsH
#define EBarsUtilsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include "AboutDemoForm.h"
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"

//---------------------------------------------------------------------------
enum dxSitePage { spDownloads, spSupport, spStart, spProducts, spMyDX };
//---------------------------------------------------------------------------
const
  PCHAR
	dxDownloadURL = "http://www.devexpress.com/downloads",
	dxSupportURL = "http://www.devexpress.com/Support/Center",
	dxStartURL = "http://www.devexpress.com",
	dxProductsURL = "http://www.devexpress.com/products",
	dxMyDXURL = "https://www.devexpress.com/ClientCenter";
//---------------------------------------------------------------------------
class TdmCommonData : public TDataModule
{
__published:	// IDE-managed Components
	TActionList *alMain;
	TAction *actBarsHelp;
	TAction *actDockingHelp;
	TAction *actRateDemo;
	TAction *actDownloads;
	TAction *actSBarsHelp;
	TAction *actAbout;
	TAction *actMyDX;
	TAction *actSupport;
	TAction *actProducts;
	TAction *actDXOnTheWeb;
	void __fastcall actSBarsHelpExecute(TObject *Sender);
	void __fastcall actBarsHelpExecute(TObject *Sender);
	void __fastcall actDockingHelpExecute(TObject *Sender);
	void __fastcall actRateDemoExecute(TObject *Sender);
	void __fastcall actMyDXExecute(TObject *Sender);
	void __fastcall actDownloadsExecute(TObject *Sender);
	void __fastcall actSupportExecute(TObject *Sender);
	void __fastcall actDXOnTheWebExecute(TObject *Sender);
	void __fastcall actProductsExecute(TObject *Sender);
	void __fastcall actAboutExecute(TObject *Sender);
private:	// User declarations
	TMetaClass* FAboutFormClass;
public:		// User declarations
	__fastcall TdmCommonData(TComponent* Owner);
	__property TMetaClass* AboutFormClass = {read=FAboutFormClass, write=FAboutFormClass, nodefault};
};
//---------------------------------------------------------------------------
extern PACKAGE TdmCommonData *dmCommonData;
//---------------------------------------------------------------------------
void Browse(dxSitePage ASitePage);
//---------------------------------------------------------------------------
#endif



