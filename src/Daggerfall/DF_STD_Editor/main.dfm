object Form1: TForm1
  Left = 322
  Top = 220
  Width = 558
  Height = 380
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 212
    Top = 60
    Width = 34
    Height = 13
    Caption = #1057#1087#1077#1083#1083':'
  end
  object Label2: TLabel
    Left = 212
    Top = 96
    Width = 29
    Height = 13
    Caption = #1062#1077#1085#1072':'
  end
  object Label3: TLabel
    Left = 212
    Top = 140
    Width = 76
    Height = 13
    Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100':'
  end
  object Label4: TLabel
    Left = 364
    Top = 140
    Width = 12
    Height = 13
    Caption = ' + '
  end
  object Label5: TLabel
    Left = 452
    Top = 140
    Width = 12
    Height = 13
    Caption = #1085#1072
  end
  object Label6: TLabel
    Left = 504
    Top = 140
    Width = 41
    Height = 13
    Caption = #1091#1088#1086#1074#1085#1077#1081
  end
  object Label7: TLabel
    Left = 212
    Top = 164
    Width = 30
    Height = 13
    Caption = #1064#1072#1085#1089':'
  end
  object Label8: TLabel
    Left = 364
    Top = 164
    Width = 12
    Height = 13
    Caption = ' + '
  end
  object Label9: TLabel
    Left = 452
    Top = 164
    Width = 12
    Height = 13
    Caption = #1085#1072
  end
  object Label10: TLabel
    Left = 504
    Top = 164
    Width = 41
    Height = 13
    Caption = #1091#1088#1086#1074#1085#1077#1081
  end
  object Label11: TLabel
    Left = 212
    Top = 188
    Width = 51
    Height = 13
    Caption = #1042#1077#1083#1080#1095#1080#1085#1072':'
  end
  object Label12: TLabel
    Left = 320
    Top = 188
    Width = 9
    Height = 13
    Caption = ' - '
  end
  object Label13: TLabel
    Left = 452
    Top = 188
    Width = 12
    Height = 13
    Caption = #1085#1072
  end
  object Label14: TLabel
    Left = 504
    Top = 188
    Width = 41
    Height = 13
    Caption = #1091#1088#1086#1074#1085#1077#1081
  end
  object Label15: TLabel
    Left = 364
    Top = 188
    Width = 12
    Height = 13
    Caption = ' + '
  end
  object Label16: TLabel
    Left = 408
    Top = 188
    Width = 9
    Height = 13
    Caption = ' - '
  end
  object Bevel1: TBevel
    Left = 0
    Top = 49
    Width = 550
    Height = 3
    Align = alTop
    Shape = bsBottomLine
  end
  object Log: TMemo
    Left = 0
    Top = 264
    Width = 550
    Height = 89
    Align = alBottom
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object ListBox: TListBox
    Left = 0
    Top = 52
    Width = 205
    Height = 212
    Align = alLeft
    ItemHeight = 13
    TabOrder = 1
    OnClick = ListBoxClick
  end
  object SpellName: TEdit
    Left = 252
    Top = 56
    Width = 290
    Height = 24
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    MaxLength = 25
    ParentFont = False
    TabOrder = 2
  end
  object SpellCost: TEdit
    Left = 252
    Top = 92
    Width = 290
    Height = 24
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    MaxLength = 25
    ParentFont = False
    TabOrder = 3
  end
  object bdr: TEdit
    Left = 311
    Top = 137
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 4
  end
  object adr: TEdit
    Left = 398
    Top = 137
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 5
  end
  object cld: TEdit
    Left = 468
    Top = 137
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 6
  end
  object bch: TEdit
    Left = 311
    Top = 161
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 7
  end
  object ach: TEdit
    Left = 398
    Top = 161
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 8
  end
  object clc: TEdit
    Left = 468
    Top = 161
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 9
  end
  object bm1: TEdit
    Left = 292
    Top = 185
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 10
  end
  object bm2: TEdit
    Left = 328
    Top = 185
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 11
  end
  object clm: TEdit
    Left = 468
    Top = 185
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 12
  end
  object am2: TEdit
    Left = 416
    Top = 185
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 13
  end
  object am1: TEdit
    Left = 380
    Top = 185
    Width = 30
    Height = 21
    MaxLength = 25
    TabOrder = 14
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 550
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 15
    object Button3: TSpeedButton
      Left = 258
      Top = 4
      Width = 125
      Height = 25
      Caption = 'Store Info'
      OnClick = Button3Click
    end
    object SpeedButton1: TSpeedButton
      Left = 131
      Top = 4
      Width = 125
      Height = 25
      Caption = 'Rus -> Eng'
      OnClick = SpeedButton1Click
    end
    object Button1: TButton
      Left = 4
      Top = 4
      Width = 125
      Height = 25
      Caption = #1054#1090#1082#1088#1099#1090#1100' SPELLS.STD'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 385
      Top = 4
      Width = 125
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' SPELLS.STD'
      TabOrder = 1
      OnClick = Button2Click
    end
    object FixBox: TCheckBox
      Left = 136
      Top = 31
      Width = 197
      Height = 15
      Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1074' '#1088#1091#1089#1089#1082#1086#1081' '#1088#1072#1089#1082#1083#1072#1076#1082#1077
      TabOrder = 2
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'STD'
    FileName = 'SPELLS'
    Filter = 'TES: Daggerfall STD files|*.STD'
    InitialDir = '.'
    Left = 56
    Top = 92
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'STD'
    FileName = 'SPELLS'
    Filter = 'TES: Daggerfall STD files|*.STD'
    InitialDir = '.'
    Left = 88
    Top = 92
  end
end
