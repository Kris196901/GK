// ---------------------------------------------------------------------------

#ifndef GKChildDBFormH
#define GKChildDBFormH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxTextEdit.hpp"
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
#include "dxSkinsDefaultPainters.hpp"
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
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxNavigator.hpp"
#include "cxStyles.hpp"
#include "dxSkinscxPCPainter.hpp"
#include <Data.DB.hpp>
// ---------------------------------------------------------------------------

const String sDefaultDocName = "New Document.rtf";
const String RTFFilter = "Rich Text Files (*.RTF)|*.RTF";
const String TXTFilter = "Plain text (*.TXT)|*.TXT";
const int UM_UPDATEUNDO = WM_USER + 1;
// ---------------------------------------------------------------------------

typedef void __fastcall(__closure * TGKAddToRecentList)(TObject * Sender, const String AFileName);
// ---------------------------------------------------------------------------

class TRichEditUndoController {
private:
	TStringList *FActions;
	TcxRichEdit *FEditor;
	Boolean FIsLocked;
	int FLastMessageID;

protected:
	void PopUndo(void);
	void PushUndo(const String AAction);

public:
	__fastcall TRichEditUndoController(TcxRichEdit *AEditor);
	__fastcall ~TRichEditUndoController();
	void AddAction(int AActionID);
	void AnalyseMessage();
	Boolean CanUndo();
	Boolean CanRedo();
	void Redo();
	void Undo(int ACount);
	void Lock();
	void Unlock();

	__property TStringList *Actions = {read = FActions};
};
// ---------------------------------------------------------------------------

class TfrmGKChildDB : public TForm {
__published: // IDE-managed Components
	TBevel *Bevel1;
	TBevel *bvSpacer4;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TSaveDialog *SaveDialog;

	void __fastcall EditorPropertiesChange(TObject *Sender);
	void __fastcall EditorPropertiesSelectionChange(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormCreate(TObject *Sender);

private: // User declarations
	String FFileName;
	Boolean FModified;
	TRichEditUndoController *FUndoController;
	TGKAddToRecentList FOnAddToRecent;

	TNotifyEvent FOnChanged;
	TNotifyEvent FOnUndoListChanged;

	Boolean GetCanEdit();
	Boolean GetCanPaste();
	Boolean GetCanSave();
	Boolean GetLocked();
	void SetLocked(const Boolean AValue);

protected:
	void DoAddToRecent(const String AFileName);
	void DoChanged();
	void DoUndoListChanged();

	Boolean CheckSaveChanges();
	int QuerySaveFile();

	void __fastcall UpdateCaption();
	void UpdateUndo(TMessage &AMessage);

	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(UM_UPDATEUNDO, TMessage, UpdateUndo)
	END_MESSAGE_MAP(TForm)
public : // User declarations
	__fastcall TfrmGKChildDB(TComponent* Owner);
	void OpenFile(const String AFileName);
	Boolean ExportAsPlainText();
	Boolean SaveFile(Boolean ASaveAs);

	__property Boolean CanEdit = {read = GetCanEdit};
	__property Boolean CanPaste = {read = GetCanPaste};
	__property Boolean CanSave = {read = GetCanSave};
	__property String FileName = {read = FFileName};
	__property Boolean Locked = {read = GetLocked, write = SetLocked};
	__property Boolean Modified = {read = FModified, write = FModified};
	__property TRichEditUndoController *UndoController = {read = FUndoController};

	__property TGKAddToRecentList OnAddToRecent = {read = FOnAddToRecent, write = FOnAddToRecent};
	__property TNotifyEvent OnChanged = {read = FOnChanged, write = FOnChanged};
	__property TNotifyEvent OnUndoListChanged = {read = FOnUndoListChanged, write = FOnUndoListChanged};
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrmGKChildDB *frmGKChildDB;
// ---------------------------------------------------------------------------
#endif
