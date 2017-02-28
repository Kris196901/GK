object dmCommonData: TdmCommonData
  OldCreateOrder = False
  Height = 381
  Width = 532
  object alMain: TActionList
    Left = 8
    Top = 8
    object actSBarsHelp: TAction
      Category = 'Help'
      Caption = 'actSBarsHelp'
      ImageIndex = 0
      OnExecute = actSBarsHelpExecute
    end
    object actBarsHelp: TAction
      Category = 'Help'
      Caption = 'Express&Bars Help'
      Hint = 'Starts the ExpressBars help system'
      ImageIndex = 0
      OnExecute = actBarsHelpExecute
    end
    object actAbout: TAction
      Category = 'Options'
      Caption = 'actAbout'
      Checked = True
      OnExecute = actAboutExecute
    end
    object actDockingHelp: TAction
      Category = 'Help'
      Caption = 'Express D&ocking Library Help'
      ImageIndex = 0
      OnExecute = actDockingHelpExecute
    end
    object actRateDemo: TAction
      Category = 'Help'
      Caption = #1054#1094#1077#1085#1080#1090#1100' '#1087#1088#1080#1083#1086#1078#1077#1085#1080#1077
      Hint = #1054#1090#1087#1088#1072#1074#1080#1090#1100' '#1086#1094#1077#1085#1082#1091
      ImageIndex = 1
      OnExecute = actRateDemoExecute
    end
    object actMyDX: TAction
      Category = 'Help'
      Caption = 'actMyDX'
      ImageIndex = 2
      OnExecute = actMyDXExecute
    end
    object actDownloads: TAction
      Category = 'Help'
      Caption = 'actDownloads'
      ImageIndex = 2
      OnExecute = actDownloadsExecute
    end
    object actSupport: TAction
      Category = 'Help'
      Caption = 'actSupport'
      ImageIndex = 2
      OnExecute = actSupportExecute
    end
    object actProducts: TAction
      Category = 'Help'
      Caption = 'actProducts'
      ImageIndex = 2
      OnExecute = actProductsExecute
    end
    object actDXOnTheWeb: TAction
      Category = 'Help'
      Caption = 'actDXOnTheWeb'
      ImageIndex = 3
      OnExecute = actDXOnTheWebExecute
    end
  end
end
