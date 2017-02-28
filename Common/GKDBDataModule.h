//---------------------------------------------------------------------------

#ifndef GKDBDataModuleH
#define GKDBDataModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
//---------------------------------------------------------------------------
class TdmDBData : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDatabase *dbMain;
	TpFIBTransaction *rtRead;
	TpFIBTransaction *trMain;
private:	// User declarations
public:		// User declarations
	__fastcall TdmDBData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdmDBData *dmDBData;
//---------------------------------------------------------------------------
#endif
