object Form1: TForm1
  Left = 274
  Top = 153
  Width = 633
  Height = 467
  Caption = 'TES2: Daggerfall QRC Editor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 59
    Width = 625
    Height = 3
    Align = alTop
    Shape = bsTopLine
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 625
    Height = 59
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Button4: TSpeedButton
      Left = 123
      Top = 3
      Width = 115
      Height = 25
      Caption = 'Rus -> Eng'
      OnClick = Button4Click
    end
    object Button3: TSpeedButton
      Left = 240
      Top = 3
      Width = 115
      Height = 25
      Caption = 'Store Info'
      OnClick = Button3Click
    end
    object SpeedButton1: TSpeedButton
      Left = 357
      Top = 3
      Width = 118
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' QRC-'#1092#1072#1081#1083
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 3
      Top = 3
      Width = 118
      Height = 25
      Caption = #1055#1091#1090#1100' '#1082' QRC-'#1092#1072#1081#1083#1072#1084'...'
      OnClick = SpeedButton2Click
    end
    object SpeedButton3: TSpeedButton
      Left = 477
      Top = 3
      Width = 115
      Height = 25
      Caption = #1069#1082#1089#1087#1086#1088#1090' '#1074' TXT'
      OnClick = SpeedButton3Click
    end
    object Button1: TButton
      Left = 477
      Top = 31
      Width = 115
      Height = 25
      Caption = #1054#1090#1082#1088#1099#1090#1100' QRC-'#1092#1072#1081#1083
      TabOrder = 0
      Visible = False
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 361
      Top = 31
      Width = 115
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' QRC-'#1092#1072#1081#1083
      Enabled = False
      TabOrder = 1
      Visible = False
      OnClick = Button2Click
    end
    object FixBox: TCheckBox
      Left = 124
      Top = 32
      Width = 193
      Height = 15
      Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1074' '#1088#1091#1089#1089#1082#1086#1081' '#1088#1072#1089#1082#1083#1072#1076#1082#1077
      TabOrder = 2
      OnClick = FixBoxClick
    end
  end
  object Memo: TMemo
    Left = 248
    Top = 62
    Width = 377
    Height = 289
    Align = alClient
    Color = clSilver
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Log: TMemo
    Left = 0
    Top = 351
    Width = 625
    Height = 89
    TabStop = False
    Align = alBottom
    Color = clSilver
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 62
    Width = 248
    Height = 289
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
    object ListBox: TListBox
      Left = 128
      Top = 19
      Width = 120
      Height = 270
      Align = alClient
      Color = clSilver
      ItemHeight = 13
      TabOrder = 1
      OnClick = ListBoxClick
    end
    object QRCList: TListBox
      Left = 0
      Top = 19
      Width = 128
      Height = 270
      Align = alLeft
      Color = clSilver
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ItemHeight = 16
      ParentFont = False
      TabOrder = 0
      OnClick = QRCListClick
    end
    object Panel3: TPanel
      Left = 0
      Top = 0
      Width = 248
      Height = 19
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 2
      object Label2: TLabel
        Left = 132
        Top = 4
        Width = 109
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = #1058#1077#1082#1089#1090#1086#1074#1099#1077' '#1089#1077#1082#1094#1080#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 4
        Top = 4
        Width = 121
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = #1060#1072#1081#1083#1099
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'QRC'
    Filter = 'TES2:Daggerfall quest files|*.QRC'
    InitialDir = '.'
    Left = 48
    Top = 108
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'QRC'
    Filter = 'TES2:Daggerfall quest files|*.QRC'
    InitialDir = '.'
    Left = 12
    Top = 108
  end
  object DirDlg: TOpenDialog
    FileName = 'Select directory...'
    InitialDir = '.'
    Left = 12
    Top = 140
  end
end
