object EBarsDemoRatingForm: TEBarsDemoRatingForm
  Left = 0
  Top = 220
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Demo rating '
  ClientHeight = 254
  ClientWidth = 306
  Color = 15921902
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 254
    Height = 13
    Caption = 'How would you rate the quality of this demo?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 22
    Height = 13
    Caption = 'Poor'
  end
  object Label3: TLabel
    Left = 252
    Top = 48
    Width = 43
    Height = 13
    Caption = 'Excellent'
  end
  object Label4: TLabel
    Left = 8
    Top = 80
    Width = 263
    Height = 13
    Caption = 'Tell us your opinion about this demo (optional)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object btnSend: TButton
    Left = 223
    Top = 221
    Width = 75
    Height = 25
    Caption = 'Email...'
    Enabled = False
    TabOrder = 0
    OnClick = btnSendClick
  end
  object memRateDescrip: TMemo
    Left = 8
    Top = 96
    Width = 289
    Height = 121
    Color = 15921902
    Lines.Strings = (
      'memRateDescrip')
    TabOrder = 1
  end
  object rgRate: TRadioGroup
    Left = 44
    Top = 32
    Width = 201
    Height = 45
    Columns = 5
    Ctl3D = True
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5')
    ParentCtl3D = False
    TabOrder = 2
    OnClick = rgRateChanged
  end
end
