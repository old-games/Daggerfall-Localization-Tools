object Form2: TForm2
  Left = 303
  Top = 184
  Width = 658
  Height = 405
  Caption = 'TES2: Daggerfall RSC-files Editor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 650
    Height = 52
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object Button3: TSpeedButton
      Left = 255
      Top = 3
      Width = 115
      Height = 25
      Caption = 'Store Info'
      OnClick = Button3Click
    end
    object SpeedButton1: TSpeedButton
      Left = 119
      Top = 3
      Width = 134
      Height = 25
      Caption = 'Rus -> Eng'
      OnClick = SpeedButton1Click
    end
    object Label1: TLabel
      Left = 336
      Top = 32
      Width = 71
      Height = 13
      Caption = #1044#1083#1080#1085#1072' '#1089#1090#1088#1086#1082#1080
    end
    object Label2: TLabel
      Left = 544
      Top = 32
      Width = 12
      Height = 13
      Caption = #1087#1086
    end
    object Label3: TLabel
      Left = 496
      Top = 32
      Width = 6
      Height = 13
      Caption = 'c'
    end
    object Button1: TButton
      Left = 3
      Top = 3
      Width = 115
      Height = 25
      Caption = #1054#1090#1082#1088#1099#1090#1100' TEXT.RSC'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 371
      Top = 3
      Width = 115
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' TEXT.RSC'
      TabOrder = 1
      OnClick = Button2Click
    end
    object FixBox: TCheckBox
      Left = 132
      Top = 32
      Width = 193
      Height = 15
      Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1074' '#1088#1091#1089#1089#1082#1086#1081' '#1088#1072#1089#1082#1083#1072#1076#1082#1077
      TabOrder = 2
    end
    object SelectBox: TCheckBox
      Left = 8
      Top = 32
      Width = 105
      Height = 15
      Caption = #1074#1099#1076#1077#1083#1103#1090#1100' '#1090#1077#1082#1089#1090
      TabOrder = 3
    end
    object LineWidth: TPanel
      Left = 412
      Top = 29
      Width = 43
      Height = 21
      Alignment = taRightJustify
      BevelOuter = bvNone
      BorderStyle = bsSingle
      Caption = '320'
      Color = clHighlightText
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
    end
    object Button4: TButton
      Left = 488
      Top = 3
      Width = 113
      Height = 25
      Caption = 'Export Text'
      TabOrder = 5
      OnClick = Button4Click
    end
    object Edit1: TEdit
      Left = 508
      Top = 29
      Width = 34
      Height = 21
      TabOrder = 6
      Text = '0'
    end
    object Edit2: TEdit
      Left = 560
      Top = 29
      Width = 34
      Height = 21
      TabOrder = 7
      Text = '0'
    end
  end
  object Log: TMemo
    Left = 0
    Top = 289
    Width = 650
    Height = 89
    Align = alBottom
    Color = clSilver
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 52
    Width = 650
    Height = 237
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Bevel1: TBevel
      Left = 0
      Top = 0
      Width = 650
      Height = 2
      Align = alTop
      Shape = bsTopLine
    end
    object Memo: TMemo
      Left = 138
      Top = 2
      Width = 512
      Height = 235
      Align = alClient
      Color = clSilver
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 0
      OnChange = MemoChange
      OnKeyDown = MemoKeyDown
    end
    object ListBox: TListBox
      Left = 0
      Top = 2
      Width = 138
      Height = 235
      Align = alLeft
      Color = clSilver
      ItemHeight = 13
      TabOrder = 1
      OnClick = ListBoxClick
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'RSC'
    FileName = 'TEXT'
    Filter = 'TES: Daggerfall RSC files|*.RSC'
    InitialDir = '.'
    Left = 56
    Top = 92
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'RSC'
    FileName = 'TEXT'
    Filter = 'TES: Daggerfall RSC files|*.RSC'
    InitialDir = '.'
    Left = 88
    Top = 92
  end
  object ApplicationEvents1: TApplicationEvents
    OnShortCut = ApplicationEvents1ShortCut
    Left = 8
    Top = 60
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 600
    Top = 60
  end
end
