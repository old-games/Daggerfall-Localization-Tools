object Form2: TForm2
  Left = 303
  Top = 184
  BorderStyle = bsSingle
  Caption = 'TES2: Daggerfall DEF-files Editor'
  ClientHeight = 378
  ClientWidth = 536
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 536
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object Button1: TButton
      Left = 151
      Top = 3
      Width = 120
      Height = 20
      Caption = #1054#1090#1082#1088#1099#1090#1100' MAGIC.DEF'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 275
      Top = 3
      Width = 120
      Height = 20
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' MAGIC.DEF'
      TabOrder = 1
      OnClick = Button2Click
    end
    object FixBox: TCheckBox
      Left = 132
      Top = 24
      Width = 193
      Height = 15
      Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1074' '#1088#1091#1089#1089#1082#1086#1081' '#1088#1072#1089#1082#1083#1072#1076#1082#1077
      TabOrder = 2
    end
    object SelectBox: TCheckBox
      Left = 8
      Top = 24
      Width = 105
      Height = 15
      Caption = #1074#1099#1076#1077#1083#1103#1090#1100' '#1090#1077#1082#1089#1090
      TabOrder = 3
    end
  end
  object Log: TMemo
    Left = 0
    Top = 289
    Width = 536
    Height = 89
    Align = alBottom
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 41
    Width = 536
    Height = 248
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Bevel1: TBevel
      Left = 0
      Top = 0
      Width = 536
      Height = 2
      Align = alTop
      Shape = bsTopLine
    end
    object Button3: TSpeedButton
      Left = 291
      Top = 97
      Width = 115
      Height = 25
      Caption = 'Store Info'
      OnClick = Button3Click
    end
    object SpeedButton1: TSpeedButton
      Left = 291
      Top = 69
      Width = 115
      Height = 25
      Caption = 'Rus -> Eng'
      OnClick = SpeedButton1Click
    end
    object ListBox: TListBox
      Left = 0
      Top = 2
      Width = 183
      Height = 246
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      OnClick = ListBoxClick
    end
    object ItemName: TEdit
      Left = 188
      Top = 8
      Width = 341
      Height = 24
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      MaxLength = 31
      ParentFont = False
      TabOrder = 1
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'RSC'
    FileName = 'MAGIC'
    Filter = 'TES: Daggerfall DEF files|*.DEF'
    InitialDir = '.'
    Left = 56
    Top = 92
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'RSC'
    FileName = 'MAGIC'
    Filter = 'TES: Daggerfall DEF files|*.DEF'
    InitialDir = '.'
    Left = 88
    Top = 92
  end
  object ApplicationEvents1: TApplicationEvents
    OnShortCut = ApplicationEvents1ShortCut
    Left = 496
    Top = 8
  end
end
