//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GKMainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxPC"
#pragma link "dxBar"
#pragma link "dxBarBuiltInMenu"
#pragma link "dxColorDialog"
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
#pragma link "dxSkinscxPCPainter"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinsdxBarPainter"
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
#pragma link "dxTabbedMDI"
#pragma link "cxBarEditItem"
#pragma link "cxDropDownEdit"
#pragma link "cxFontNameComboBox"
#pragma link "dxRibbonGallery"
#pragma resource "*.dfm"
TfrmGKMain *frmGKMain;

const String sRichEditFoundResultCaption = "Information";
const String sRichEditTextNotFound = "The search text is not found.";
const String sRichEditReplaceAllResult = "Replaced %d occurrences.";

int __fastcall Round(double const AVal)
{
  int res;
  if (AVal > 0)
	res = AVal + 0.5;
  else
	res = AVal - 0.5;
  return res;
}
//---------------------------------------------------------------------------

// Получить имя ini файла настроек внешнего вида
String GetBarsLayoutFileName()
{
  return ExtractFilePath(Application->ExeName) + "BarsLayout.ini";
}
//---------------------------------------------------------------------------

// Получить имя ini файла последних открытых документов
String GetRecentDocumentsFileName()
{
  return ExtractFilePath(Application->ExeName) + "RecentDocuments.ini";
}
//---------------------------------------------------------------------------

void TRecentDocumentsController::DoLoad(TCustomIniFile *AConfig)
{
  // do nothing
}
//---------------------------------------------------------------------------

void TRecentDocumentsController::DoSave(TCustomIniFile *AConfig)
{
  // do nothing
}
//---------------------------------------------------------------------------

void TRecentDocumentsController::Add(const String AFileName)
{
  // do nothing
}
//---------------------------------------------------------------------------

void TRecentDocumentsController::SetCurrentFileName(const String AFileName)
{
  // do nothing
}

//---------------------------------------------------------------------------
void TRecentDocumentsController::LoadFromIniFile(const String AFileName)
{
  TIniFile *AIniFile;
  AIniFile = new TIniFile(AFileName);
  try
  {
	DoLoad(AIniFile);
  }
  __finally
  {
	delete AIniFile;
  }
}

//---------------------------------------------------------------------------
void TRecentDocumentsController::SaveToIniFile(const String AFileName)
{
  TIniFile *AIniFile;
  AIniFile = new TIniFile(AFileName);
  try
  {
	DoSave(AIniFile);
  }
  __finally
  {
	delete AIniFile;
  }
}
//---------------------------------------------------------------------------


__fastcall TfrmGKMain::TfrmGKMain(TComponent* Owner)
	: TdxRibbonForm(Owner)
{
}
//---------------------------------------------------------------------------
TfrmGKChild* TfrmGKMain::CreateChildForm()
{
  return new TfrmGKChild(this);
}
//---------------------------------------------------------------------------
TfrmGKChild* TfrmGKMain::CreateNewChild()
{
  TfrmGKChild* AResult;
  AResult = CreateChildForm();
  AResult->OnChanged = EditorChangeHandler;
  AResult->OnAddToRecent = EditorAddToRecentListHandler;
  AResult->OnUndoListChanged = EditorUndoListChangeHandler;
  return AResult;
}
//---------------------------------------------------------------------------
TRecentDocumentsController* TfrmGKMain::CreateRecentDocumentsController()
{
  return new TRecentDocumentsController();
}
//---------------------------------------------------------------------------
void TfrmGKMain::DoUpdateControls(TfrmGKChild *AActiveChild)
{
  TPoint ACursorPos;
  acAlignCenter->Enabled = AActiveChild != NULL;
  acAlignLeft->Enabled = AActiveChild != NULL;
  acAlignRight->Enabled = AActiveChild != NULL;
  acBold->Enabled = AActiveChild != NULL;
  acBullets->Enabled = AActiveChild != NULL;
  acClear->Enabled = AActiveChild != NULL;
  acFind->Enabled = AActiveChild != NULL;
  acFont->Enabled = AActiveChild != NULL;
  acFont->Enabled = AActiveChild != NULL;
  acFontColor->Enabled = AActiveChild != NULL;
  acItalic->Enabled = AActiveChild != NULL;
  acPrint->Enabled = AActiveChild != NULL;
  acReplace->Enabled = AActiveChild != NULL;
  acSave->Enabled = AActiveChild != NULL && AActiveChild->CanSave;
  acSaveAs->Enabled = AActiveChild != NULL;
  acSelectAll->Enabled = AActiveChild != NULL;
  acUnderline->Enabled = AActiveChild != NULL;

  acCopy->Enabled = (AActiveChild != NULL) && (AActiveChild->Editor->SelLength > 0);
  acPaste->Enabled = AActiveChild != NULL && AActiveChild->CanPaste;
  acClear->Enabled = acCopy->Enabled && AActiveChild->CanEdit;
  acCut->Enabled = acCopy->Enabled && AActiveChild->CanEdit;

  beFontName->Enabled = AActiveChild != NULL;
  beFontSize->Enabled = AActiveChild != NULL;

  bbLocked->Visible = VisibleTodxBarVisible(AActiveChild != NULL);
  bbCursorColumn->Visible = VisibleTodxBarVisible(AActiveChild != NULL);
  bbCursorLine->Visible = VisibleTodxBarVisible(AActiveChild != NULL);
  bbModified->Visible = VisibleTodxBarVisible(AActiveChild != NULL && AActiveChild->Modified);

  if (AActiveChild != NULL)
  {
	ACursorPos.y = SendMessage(Editor->InnerControl->Handle, EM_LINEFROMCHAR, Editor->SelStart, 0);
	ACursorPos.x = Editor->SelStart - SendMessage(Editor->InnerControl->Handle, EM_LINEINDEX, ACursorPos.y, 0);
	TVarRec V[] = {1 + ACursorPos.y};
	String AFormatTextMessage = " Line: %3d ";
	bbCursorLine->Caption = Format(AFormatTextMessage, V, 1);
	V[0] = 1 + ACursorPos.x;
	AFormatTextMessage = " Position: %3d ";
	bbCursorColumn->Caption = Format(AFormatTextMessage, V, 1);
	bbLocked->Down = AActiveChild->Locked;

	beFontSize->EditValue = IntToStr(Editor->SelAttributes->Size);
	beFontName->EditValue = Editor->SelAttributes->Name;

	acBold->Checked = Editor->SelAttributes->Style.Contains(fsBold);
	acItalic->Checked = Editor->SelAttributes->Style.Contains(fsItalic);
	acUnderline->Checked = Editor->SelAttributes->Style.Contains(fsUnderline);

	acBullets->Checked = Editor->Paragraph->Numbering != nsNone;

	acAlignCenter->Checked = False;
	acAlignLeft->Checked = False;
	acAlignRight->Checked = False;
	switch (int (Editor->Paragraph->Alignment))
	{
	  case 0:
		acAlignLeft->Checked = True; break;
	  case 1:
		acAlignRight->Checked = True; break;
	  case 2:
		acAlignCenter->Checked = True; break;
	}
  }
  else
  {
	acAlignCenter->Checked = False;
	acAlignLeft->Checked = False;
	acAlignRight->Checked = False;

	acBold->Checked = False;
	acBullets->Checked = False;
	acItalic->Checked = False;
	acUnderline->Checked = False;
  }

  if ((ActiveChild != NULL) && ActiveChild->Locked)
	bbLocked->Hint = "Editing protection: Read only. Click for editing->";
  else
	bbLocked->Hint = "Editing protection: Writable. Click for read-only mode->";
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::EditorAddToRecentListHandler(TObject *Sender, const String AFileName)
{
  RecentDocumentsController->Add(AFileName);
  if (Sender == ActiveMDIChild)
	RecentDocumentsController->SetCurrentFileName(ActiveChild->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::EditorChangeHandler(TObject *Sender)
{
  if (Sender == ActiveMDIChild)
	UpdateControls();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::EditorUndoListChangeHandler(TObject *Sender)
{
  if (Sender == ActiveMDIChild)
	UpdateUndoRelatedControls();
}
//---------------------------------------------------------------------------
TfrmGKChild* TfrmGKMain::FindChild(const String AFileName)
{
  TForm *AForm;
  for (int I = 0; I <= MDIChildCount - 1; I++)
	if (SameText(AFileName, ((TfrmGKChild*)MDIChildren[I])->FileName))
	  return (TfrmGKChild*)MDIChildren[I];
  return NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::FindDialogFind(TObject *Sender)
{
  TRect ACaretR, R, AIntersectR;
  TFindDialog *AFindDialog;
  int AFindLength;
  TSearchTypes AFlags;
  int AFoundAt;
  int AStartPos;
  TPoint P;

  AFindDialog = (TFindDialog*)Sender;

  AStartPos = Editor->SelStart + Editor->SelLength;
  AFindLength = Editor->Text.Length() - AStartPos;

  AFlags.Clear();
  if (AFindDialog->Options.Contains(frMatchCase))
	AFlags = AFlags << stMatchCase;
  if (AFindDialog->Options.Contains(frWholeWord))
	AFlags = AFlags << stWholeWord;

  Screen->Cursor = crHourGlass;
  AFoundAt = Editor->FindTexT(AFindDialog->FindText, AStartPos, AFindLength, AFlags);
  if (!AFindDialog->Options.Contains(frReplaceAll))
	Screen->Cursor = crDefault;

  if (AFoundAt < 0)
  {
	if (!AFindDialog->Options.Contains(frReplaceAll))
	  Application->MessageBox(sRichEditTextNotFound.w_str(), sRichEditFoundResultCaption.w_str(), MB_ICONINFORMATION);
  }
  else
	if (AFindDialog->Options.Contains(frReplaceAll))
	{
	  Editor->SelStart = AFoundAt;
	  Editor->SelLength = AFindDialog->FindText.Length();
	}
	else
	{
	  Editor->SetFocus();
	  Editor->SelStart = AFoundAt;
	  Editor->SelLength = AFindDialog->FindText.Length();

	  GetCaretPos(&P);
	  P = ClientToScreen(P);
	  ACaretR = Rect(P.x, P.y, P.x + 2, P.y + 20);
	  GetWindowRect(Handle, &R);
	  if (IntersectRect(AIntersectR, ACaretR, R))
	  {
		if (P.y < div(Screen->Height, 2).quot)
		  AFindDialog->Top = P.y + 40;
		else
		  AFindDialog->Top = P.y - (R.Bottom - R.Top + 20);
	  }
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::FormCreate(TObject *Sender)
{
  FRecentDocumentsController = CreateRecentDocumentsController();
  FRecentDocumentsController->LoadFromIniFile(GetRecentDocumentsFileName());
  dxBarManager->LoadFromIniFile(GetBarsLayoutFileName());
#ifdef EXPRESSSKINS
  TdxSkinController->Create(this);
#endif
  OpenDialog->Filter = RTFFilter;
  OpenDialog->InitialDir = ExtractFilePath(Application->ExeName);
  InitializeLookAndFeel();
  UpdateControls();
  dxBarManager->MDIStateChangedHandlers->Add(MDIStateChanged);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::FormDestroy(TObject *Sender)
{
  dxBarManager->SaveToIniFile(GetBarsLayoutFileName());
  FRecentDocumentsController->SaveToIniFile(GetRecentDocumentsFileName());
  delete FRecentDocumentsController;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::FormShow(TObject *Sender)
{
  String ADefaultDocument;
  ADefaultDocument = ExtractFilePath(Application->ExeName) + "Document1.rtf";
  if (FileExists(ADefaultDocument))
	OpenFile(ADefaultDocument);
  else
	CreateNewChild();
}
//---------------------------------------------------------------------------
TfrmGKChild* TfrmGKMain::GetActiveChild()
{
  if (ActiveMDIChild != NULL)
	return (TfrmGKChild*)ActiveMDIChild;
  else
	return NULL;
}
//---------------------------------------------------------------------------
TcxRichEdit* TfrmGKMain::GetEditor()
{
  return ActiveChild->Editor;
}
//---------------------------------------------------------------------------
void TfrmGKMain::InitializeLookAndFeel()
{
  cxLookAndFeelController->NativeStyle = False;
  cxLookAndFeelController->SkinName = "DevExpressStyle";
  scgiLookAndFeel->SelectedSkinName = RootLookAndFeel()->Painter->LookAndFeelName();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::MDIStateChanged(TObject *Sender, const void* AEventArgs)
{
  TdxBarMDIStateChangeEventData *AEventData;
  AEventData = (TdxBarMDIStateChangeEventData*)AEventArgs;
  if (AEventData->Change == scChildActivated)
  {
	if (ActiveChild != NULL)
	  RecentDocumentsController->SetCurrentFileName(ActiveChild->FileName);
	UpdateControls();
  }
}
//---------------------------------------------------------------------------
Boolean TfrmGKMain::OpenFile()
{
  Boolean AResult;
  OpenDialog->FileName = "";
  AResult = OpenDialog->Execute();
  if (AResult != NULL)
	OpenFile(OpenDialog->FileName);
  return AResult;
}
//---------------------------------------------------------------------------
TfrmGKChild* TfrmGKMain::OpenFile(const String AFileName)
{
  TfrmGKChild* AResult;
  AResult = FindChild(AFileName);
  if (AResult == NULL)
  {
	AResult = CreateNewChild();
	AResult->OpenFile(AFileName);
  }
  AResult->Show();
  return AResult;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::ReplaceDialogReplace(TObject *Sender)
{
  int AOldSelStart;
  int APrevSelStart;
  int AReplacedCount;
  TReplaceDialog *AReplaceDialog;
  String S;

  AReplacedCount = 0;
  AReplaceDialog = (TReplaceDialog*)Sender;

  AOldSelStart = Editor->SelStart;
  if (AReplaceDialog->Options.Contains(frReplaceAll))
	Screen->Cursor = crHourGlass;

  do
  {
	if (Editor->SelLength > 0)
	{
	  if (((Editor->SelText == AReplaceDialog->FindText) || !(AReplaceDialog->Options.Contains(frMatchCase))) &
		(AnsiUpperCase(Editor->SelText) == AnsiUpperCase(AReplaceDialog->FindText)))
	  {
//		Editor->SelText = AReplaceDialog->ReplaceTextA;
		AReplacedCount++;
	  }
	}
	APrevSelStart = Editor->SelStart;
	FindDialogFind(Sender);
  }
  while (AReplaceDialog->Options.Contains(frReplaceAll) | (Editor->SelStart == APrevSelStart) & (Editor->SelLength == 0));

  if (AReplaceDialog->Options.Contains(frReplaceAll))
  {
	Screen->Cursor = crDefault;
	if (AReplacedCount == 0)
	  S = sRichEditTextNotFound;
	else
	{
	  Editor->SelStart = AOldSelStart;
	  TVarRec V[] = {AReplacedCount};
	  S = Format(sRichEditReplaceAllResult, V, 1);
	}
	Application->MessageBox(S.w_str(), sRichEditFoundResultCaption.w_str(), MB_ICONINFORMATION);
  }
}
//---------------------------------------------------------------------------
void TfrmGKMain::SetSkin(TdxSkinChooserGalleryGroupItem *ASkinItem)
{
  ASkinItem->ApplyToRootLookAndFeel();
}
//---------------------------------------------------------------------------
void TfrmGKMain::UpdateControls()
{
  FUpdatingControls++;
  try
  {
	DoUpdateControls(ActiveChild);
	UpdateUndoRelatedControls();
  }
  __finally
  {
	FUpdatingControls--;
  }
}
//---------------------------------------------------------------------------
void TfrmGKMain::UpdateUndoRelatedControls()
{
  acRedo->Enabled = ActiveChild != NULL && ActiveChild->UndoController->CanRedo();
  acUndo->Enabled = ActiveChild != NULL && ActiveChild->UndoController->CanUndo();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acAlignExecute(TObject *Sender)
{
  Editor->Paragraph->Alignment = (TAlignment)(((TAction*)Sender)->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acBoldExecute(TObject *Sender)
{
  if (acBold->Checked)
	Editor->SelAttributes->Style = Editor->SelAttributes->Style << fsBold;
  else
	Editor->SelAttributes->Style = Editor->SelAttributes->Style >> fsBold;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acBulletsExecute(TObject *Sender)
{
  Editor->Paragraph->Numbering = (TNumberingStyle)(acBullets->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acClearExecute(TObject *Sender)
{
  Editor->ClearSelection();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acCopyExecute(TObject *Sender)
{
  Editor->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acCutExecute(TObject *Sender)
{
  Editor->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acExitExecute(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acFindExecute(TObject *Sender)
{
  Editor->SelLength = 0;
  FindDialog->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acFontExecute(TObject *Sender)
{
  FontDialog1->Font->Assign(Editor->SelAttributes);
  if (FontDialog1->Execute())
	Editor->SelAttributes->Assign(FontDialog1->Font);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acFontColorExecute(TObject *Sender)
{
  ColorDialog1->Color = dxColorToAlphaColor(Editor->SelAttributes->Color);
  if (ColorDialog1->Execute())
	Editor->SelAttributes->Color = dxAlphaColorToColor(ColorDialog1->Color);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acItalicExecute(TObject *Sender)
{
  if (acItalic->Checked)
	Editor->SelAttributes->Style = Editor->SelAttributes->Style << fsItalic;
  else
	Editor->SelAttributes->Style = Editor->SelAttributes->Style >> fsItalic;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acNewExecute(TObject *Sender)
{
  CreateNewChild();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acOpenExecute(TObject *Sender)
{
  OpenFile();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acPasteExecute(TObject *Sender)
{
  Editor->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acPrintExecute(TObject *Sender)
{
  if (PrintDialog1->Execute())
	Editor->Print(ActiveChild->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acRedoExecute(TObject *Sender)
{
  ActiveChild->UndoController->Redo();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acReplaceExecute(TObject *Sender)
{
  Editor->SelLength = 0;
  ReplaceDialog->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acSaveExecute(TObject *Sender)
{
  ActiveChild->SaveFile(False);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acSaveAsExecute(TObject *Sender)
{
  ActiveChild->SaveFile(True);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acSelectAllExecute(TObject *Sender)
{
  Editor->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acUnderlineExecute(TObject *Sender)
{
  if (acUnderline->Checked)
	Editor->SelAttributes->Style = Editor->SelAttributes->Style << fsUnderline;
  else
	Editor->SelAttributes->Style = Editor->SelAttributes->Style >> fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::acUndoExecute(TObject *Sender)
{
  ActiveChild->UndoController->Undo(1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::bbLockedClick(TObject *Sender)
{
  ActiveChild->Locked = bbLocked->Down;
  UpdateControls();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::beFontNameChange(TObject *Sender)
{
  if (FUpdatingControls == 0)
	Editor->SelAttributes->Name = beFontName->EditValue;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::beFontSizeChange(TObject *Sender)
{
  if (FUpdatingControls == 0)
	Editor->SelAttributes->Size = StrToInt(beFontSize->EditValue);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::dxTabbedMDIManager1GetTabHint(TdxTabbedMDIManager *Sender, TdxTabbedMDIPage *APage, UnicodeString &AHint,
		  bool &ACanShow)
{
  AHint = ((TfrmGKChild*)(APage->MDIChild))->FileName;
  ACanShow = AHint != "";
}
//---------------------------------------------------------------------------
void __fastcall TfrmGKMain::scgiLookAndFeelSkinChanged(TObject *Sender, const UnicodeString ASkinName)
{
  SetSkin(scgiLookAndFeel->SelectedGroupItem);
}
//---------------------------------------------------------------------------


