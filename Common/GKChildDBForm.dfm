object frmGKChildDB: TfrmGKChildDB
  Left = 0
  Top = 0
  ClientHeight = 586
  ClientWidth = 807
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object bvSpacer4: TBevel
    Left = 801
    Top = 6
    Width = 6
    Height = 574
    Align = alRight
    Shape = bsSpacer
    ExplicitLeft = 629
    ExplicitHeight = 288
  end
  object Bevel1: TBevel
    Left = 0
    Top = 6
    Width = 6
    Height = 574
    Align = alLeft
    Shape = bsSpacer
    ExplicitHeight = 288
  end
  object Bevel2: TBevel
    Left = 0
    Top = 0
    Width = 807
    Height = 6
    Align = alTop
    Shape = bsSpacer
    ExplicitWidth = 635
  end
  object Bevel3: TBevel
    Left = 0
    Top = 580
    Width = 807
    Height = 6
    Align = alBottom
    Shape = bsSpacer
    ExplicitTop = 294
    ExplicitWidth = 635
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'RTF'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist]
    Left = 16
    Top = 16
  end
end
