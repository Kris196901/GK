object dmDBData: TdmDBData
  OldCreateOrder = False
  Height = 468
  Width = 743
  object dbMain: TpFIBDatabase
    DBName = '127.0.0.1/3055:D:\db\PlanningDepartment\PDDATA.FDB'
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=1'
      'lc_ctype=WIN1251')
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'D:\Firebird\Firebird30\fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 8
    Top = 8
  end
  object rtRead: TpFIBTransaction
    DefaultDatabase = dbMain
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 8
    Top = 104
  end
  object trMain: TpFIBTransaction
    DefaultDatabase = dbMain
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 8
    Top = 56
  end
end
