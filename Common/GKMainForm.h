//---------------------------------------------------------------------------

#ifndef GKMainFormH
#define GKMainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxClasses.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxPC.hpp"
#include "dxBar.hpp"
#include "dxBarBuiltInMenu.hpp"
#include "dxColorDialog.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinscxPCPainter.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinsdxBarPainter.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "dxTabbedMDI.hpp"
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ImgList.hpp>

#include "dxSkinChooserGallery.hpp"
#include "cxBarEditItem.hpp"
#include "cxDropDownEdit.hpp"
#include "cxFontNameComboBox.hpp"
#include "dxRibbonGallery.hpp"

#include "GKChildForm.h"

int __fastcall Round(double const AVal);

class TRecentDocumentsController : public TObject
{
protected:
  virtual void DoLoad(TCustomIniFile *AConfig);
  virtual void DoSave(TCustomIniFile *AConfig);
public:
  virtual void Add(const String AFileName);
  virtual void SetCurrentFileName(const String AFileName);

  void LoadFromIniFile(const String AFileName);
  void SaveToIniFile(const String AFileName);
};

//---------------------------------------------------------------------------
class TfrmGKMain : public TdxRibbonForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog;
	TActionList *alActions;
	TcxImageList *cxSmallImages;
	TcxImageList *cxLargeImages;
	TcxLookAndFeelController *cxLookAndFeelController;
	TPrintDialog *PrintDialog1;
	TFontDialog *FontDialog1;
	TReplaceDialog *ReplaceDialog;
	TdxColorDialog *ColorDialog1;
	TFindDialog *FindDialog;
	TdxTabbedMDIManager *dxTabbedMDIManager1;
	TdxBarManager *dxBarManager;
	TdxBarButton *bbCursorColumn;
	TdxBarButton *bbCursorLine;
	TdxBarButton *bbLocked;
	TdxBarButton *bbModified;
	TcxBarEditItem *beFontName;
	TcxBarEditItem *beFontSize;
	TdxSkinChooserGalleryItem *scgiLookAndFeel;
	TAction *acNew;
	TAction *acExit;
	TAction *acOpen;
	TAction *acSave;
	TAction *acSaveAs;
	TAction *acCut;
	TAction *acCopy;
	TAction *acPaste;
	TAction *acClear;
	TAction *acSelectAll;
	TAction *acPrint;
	TAction *acFont;
	TAction *acBold;
	TAction *acItalic;
	TAction *acUnderline;
	TAction *acAlignLeft;
	TAction *acAlignCenter;
	TAction *acAlignRight;
	TAction *acBullets;
	TAction *acFontColor;
	TAction *acFind;
	TAction *acReplace;
	TAction *acUndo;
	TAction *acRedo;
	TReplaceDialog *ReplaceDialog1;


	void __fastcall FormCreate(TObject *Sender);
	void __fastcall acExitExecute(TObject *Sender);
	void __fastcall acAlignExecute(TObject *Sender);
	void __fastcall acSaveAsExecute(TObject *Sender);
	void __fastcall acNewExecute(TObject *Sender);
	void __fastcall acOpenExecute(TObject *Sender);
	void __fastcall acSaveExecute(TObject *Sender);
	void __fastcall acCutExecute(TObject *Sender);
	void __fastcall acCopyExecute(TObject *Sender);
	void __fastcall acPasteExecute(TObject *Sender);
	void __fastcall acClearExecute(TObject *Sender);
	void __fastcall acSelectAllExecute(TObject *Sender);
	void __fastcall acFontExecute(TObject *Sender);
	void __fastcall acBoldExecute(TObject *Sender);
	void __fastcall acItalicExecute(TObject *Sender);
	void __fastcall acUnderlineExecute(TObject *Sender);
	void __fastcall acBulletsExecute(TObject *Sender);
	void __fastcall acFontColorExecute(TObject *Sender);
	void __fastcall acFindExecute(TObject *Sender);
	void __fastcall acReplaceExecute(TObject *Sender);
	void __fastcall acUndoExecute(TObject *Sender);
	void __fastcall acRedoExecute(TObject *Sender);
	void __fastcall FindDialogFind(TObject *Sender);
	void __fastcall ReplaceDialogReplace(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall scgiLookAndFeelSkinChanged(TObject *Sender, const UnicodeString ASkinName);
	void __fastcall bbLockedClick(TObject *Sender);
	void __fastcall beFontNameChange(TObject *Sender);
	void __fastcall beFontSizeChange(TObject *Sender);
	void __fastcall dxTabbedMDIManager1GetTabHint(TdxTabbedMDIManager *Sender, TdxTabbedMDIPage *APage, UnicodeString &AHint, bool &ACanShow);
	void __fastcall acPrintExecute(TObject *Sender);


private:	// User declarations
	TRecentDocumentsController *FRecentDocumentsController;
	TfrmGKChild* GetActiveChild();
	TcxRichEdit* GetEditor();

	void __fastcall EditorAddToRecentListHandler(TObject* Sender, const String AFileName);
	void __fastcall EditorChangeHandler(TObject *Sender);
	void __fastcall EditorUndoListChangeHandler(TObject *Sender);
	void __fastcall MDIStateChanged(TObject *Sender, const void *AEventArgs);
	virtual void SetSkin(TdxSkinChooserGalleryGroupItem *ASkinItem);
protected:
	Integer FUpdatingControls;
	virtual TRecentDocumentsController* CreateRecentDocumentsController();
	virtual void DoUpdateControls(TfrmGKChild *AActiveChild);
	virtual void InitializeLookAndFeel();
	TfrmGKChild* CreateChildForm();
	void UpdateControls();
	void UpdateUndoRelatedControls();
public:		// User declarations
	__fastcall TfrmGKMain(TComponent* Owner);
	TfrmGKChild* CreateNewChild();
	TfrmGKChild* FindChild(const String AFileName);
	TfrmGKChild* OpenFile(const String AFileName);
	Boolean OpenFile();


	__property TfrmGKChild *ActiveChild = {read = GetActiveChild};
	__property TcxRichEdit *Editor = {read = GetEditor};
	__property TRecentDocumentsController *RecentDocumentsController = {read = FRecentDocumentsController};
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGKMain *frmGKMain;
//---------------------------------------------------------------------------
#endif
