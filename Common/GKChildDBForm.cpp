//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GKChildDBForm.h"
#include "GKDBDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxTextEdit"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxNavigator"
#pragma link "cxStyles"
#pragma link "dxSkinscxPCPainter"
#pragma resource "*.dfm"
TfrmGKChildDB *frmGKChildDB;
//---------------------------------------------------------------------------

__fastcall TRichEditUndoController::TRichEditUndoController(TcxRichEdit *AEditor)
{
  FEditor = AEditor;
  FActions = new TStringList;
}
//---------------------------------------------------------------------------
__fastcall TRichEditUndoController::~TRichEditUndoController()
{
  delete FActions;
}
//---------------------------------------------------------------------------
void TRichEditUndoController::AddAction(int AActionID)
{
  String ARichEditAction[7] = {"Unknown", "Typing", "Delete", "Drag And Drop", "Cut", "Paste", "Color Change"};
  if ((AActionID != 6) || (FEditor->SelLength != 0))
	PushUndo(ARichEditAction[AActionID]);
  FLastMessageID = AActionID;
}
//---------------------------------------------------------------------------
void TRichEditUndoController::AnalyseMessage()
{
  int AMessageID;
  if (FIsLocked)
	return;
  AMessageID = SendMessage(FEditor->InnerControl->Handle, EM_GETUNDONAME, 0, 0);
  if ((AMessageID > 1) || (AMessageID == 1) && (AMessageID != FLastMessageID))
	AddAction(AMessageID);
}
//---------------------------------------------------------------------------
Boolean TRichEditUndoController::CanRedo()
{
  return SendMessage(FEditor->InnerControl->Handle, EM_CANREDO, 0, 0) != 0;
}
//---------------------------------------------------------------------------
Boolean TRichEditUndoController::CanUndo()
{
  return (SendMessage(FEditor->InnerControl->Handle, EM_CANUNDO, 0, 0) != 0) && (Actions->Count > 0);
}
//---------------------------------------------------------------------------
void TRichEditUndoController::Lock()
{
  FIsLocked = True;
  FLastMessageID = 0;
}
//---------------------------------------------------------------------------
void TRichEditUndoController::PopUndo(void)
{
  if (Actions->Count > 0)
	Actions->Delete(0);
}
//---------------------------------------------------------------------------
void TRichEditUndoController::PushUndo(const String AAction)
{
  Actions->Insert(0, AAction);
}
//---------------------------------------------------------------------------
void TRichEditUndoController::Redo()
{
  SendMessage(FEditor->InnerControl->Handle, EM_REDO, 0, 0);
}
//---------------------------------------------------------------------------
void TRichEditUndoController::Undo(int ACount)
{
  Lock();
  try
  {
	while (ACount > 0)
	{
	  if (CanUndo())
	  {
		PopUndo();
		SendMessage(FEditor->InnerControl->Handle, EM_UNDO, 0, 0);
	  }
	  else
		break;

	  ACount--;
	}
  }
  __finally
  {
	Unlock();
  }
}
//---------------------------------------------------------------------------
void TRichEditUndoController::Unlock()
{
  FIsLocked = False;
}
//---------------------------------------------------------------------------

__fastcall TfrmGKChildDB::TfrmGKChildDB(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmGKChildDB::CheckSaveChanges()
{
  if (Modified)
	switch(QuerySaveFile())
	{
	  case ID_YES:
		return SaveFile(False);
	  case ID_CANCEL:
		return False;
	}
  return True;
}
//---------------------------------------------------------------------------
void TfrmGKChildDB::DoAddToRecent(const String AFileName)
{
  if (OnAddToRecent)
	OnAddToRecent(this, AFileName);;
}
//---------------------------------------------------------------------------
void TfrmGKChildDB::DoChanged()
{
  dxCallNotify(OnChanged, this);
}
//---------------------------------------------------------------------------
void TfrmGKChildDB::DoUndoListChanged()
{
  dxCallNotify(OnUndoListChanged, this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKChildDB::EditorPropertiesChange(TObject *Sender)
{
  Modified = True;
  DoChanged();
  PostMessage(Handle, UM_UPDATEUNDO, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKChildDB::EditorPropertiesSelectionChange(TObject *Sender)
{
  DoChanged();
}
//---------------------------------------------------------------------------
Boolean TfrmGKChildDB::ExportAsPlainText()
{
  Boolean AResult;
  SaveDialog->FileName = ChangeFileExt(ExtractFileName(FileName), "");
  SaveDialog->Filter = TXTFilter;
  AResult = SaveDialog->Execute();
  if (AResult)
  {
//	Editor->ActiveProperties->PlainText = True;
//	Editor->Lines->SaveToFile(SaveDialog->FileName);
//	Editor->ActiveProperties->PlainText = False;
  }
  return AResult;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKChildDB::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKChildDB::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  CanClose = CheckSaveChanges();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKChildDB::FormCreate(TObject *Sender)
{
//  FUndoController = new TRichEditUndoController(Editor);
  SaveDialog->InitialDir = ExtractFilePath(Application->ExeName);
  UpdateCaption();
}
//---------------------------------------------------------------------------
Boolean TfrmGKChildDB::GetCanEdit()
{
  return !Locked;
}
//---------------------------------------------------------------------------
Boolean TfrmGKChildDB::GetCanPaste()
{
//  return SendMessage(Editor->InnerControl->Handle, EM_CANPASTE, 0, 0) != 0;
return NULL;
}
//---------------------------------------------------------------------------
Boolean TfrmGKChildDB::GetCanSave()
{
  return Modified | (FileName == "");
}
//---------------------------------------------------------------------------
Boolean TfrmGKChildDB::GetLocked()
{
//  return Editor->Properties->ReadOnly;
return NULL;
}
//---------------------------------------------------------------------------
void TfrmGKChildDB::OpenFile(const String AFileName)
{
  FFileName = AFileName;
//  Editor->Lines->LoadFromFile(FileName);
  DoAddToRecent(FileName);
  FModified = False;
  UpdateCaption();
  DoChanged();
}
//---------------------------------------------------------------------------
int TfrmGKChildDB::QuerySaveFile()
{
  const String FormatTextMessage = "Do you want to save the changes you made to '%s'?";
  TVarRec V[] = {Caption};
  PChar AMessage, ACaption;
  AMessage = (Application->Title).c_str();
  ACaption = Format(FormatTextMessage, V, 1).c_str();
  return Application->MessageBox(ACaption, AMessage, MB_ICONQUESTION | MB_YESNOCANCEL);
}
//---------------------------------------------------------------------------
Boolean TfrmGKChildDB::SaveFile(Boolean ASaveAs)
{
  Boolean AResult;
  AResult = !ASaveAs & (FileName != "");
  if (!AResult)
  {
	SaveDialog->FileName = ChangeFileExt(ExtractFileName(FileName), "");
	SaveDialog->Filter = RTFFilter;
	AResult = SaveDialog->Execute();
	if (AResult)
	{
	  FFileName = SaveDialog->FileName;
	  DoAddToRecent(FileName);
	  UpdateCaption();
	}
  }

  if (AResult)
  {
//	Editor->Lines->SaveToFile(FileName);
	FModified = False;
	DoChanged();
  }
  return AResult;
}
//---------------------------------------------------------------------------
void TfrmGKChildDB::SetLocked(const Boolean AValue)
{
  if (Locked != AValue)
  {
//	Editor->Properties->ReadOnly = AValue;
	DoChanged();
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKChildDB::UpdateCaption()
{
  if (FileName != "")
	Caption = ExtractFileName(FileName);
  else
	Caption = sDefaultDocName;
}
//---------------------------------------------------------------------------
void TfrmGKChildDB::UpdateUndo(TMessage &AMessage)
{
  UndoController->AnalyseMessage();
  DoUndoListChanged();
}
//---------------------------------------------------------------------------

