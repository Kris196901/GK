//---------------------------------------------------------------------------


#pragma hdrstop

#include "GKDBDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma resource "*.dfm"
TdmDBData *dmDBData;
//---------------------------------------------------------------------------
__fastcall TdmDBData::TdmDBData(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
