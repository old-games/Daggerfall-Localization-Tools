object Form1: TForm1
  Left = 330
  Top = 154
  Width = 553
  Height = 446
  Caption = 'TES2: Daggerfall. {FALL.EXE} Explorer'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 49
    Width = 545
    Height = 3
    Align = alTop
    Shape = bsBottomLine
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 545
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Button2: TButton
      Left = 156
      Top = 4
      Width = 200
      Height = 25
      Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100#1089#1103' '#1082' FALL.EXE'
      TabOrder = 0
      OnClick = Button2Click
    end
    object FixBox: TCheckBox
      Left = 160
      Top = 31
      Width = 193
      Height = 15
      Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1074' '#1088#1091#1089#1089#1082#1086#1081' '#1088#1072#1089#1082#1083#1072#1076#1082#1077
      TabOrder = 1
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 52
    Width = 545
    Height = 278
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Text Resource #1'
      object ListBox1: TListBox
        Left = 0
        Top = 0
        Width = 205
        Height = 250
        Align = alLeft
        ItemHeight = 13
        TabOrder = 0
        OnClick = ListBox1Click
      end
      object Panel2: TPanel
        Left = 205
        Top = 0
        Width = 332
        Height = 250
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 1
        object Button13: TSpeedButton
          Left = 53
          Top = 192
          Width = 115
          Height = 25
          Caption = 'Store Info'
          OnClick = Button13Click
        end
        object Label1: TLabel
          Left = 15
          Top = 224
          Width = 149
          Height = 13
          Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1076#1083#1080#1085#1072' '#1079#1072#1087#1080#1089#1080
        end
        object Button12: TSpeedButton
          Left = 168
          Top = 192
          Width = 115
          Height = 25
          Caption = 'Save info to file'
          OnClick = Button12Click
        end
        object Button11: TSpeedButton
          Left = 108
          Top = 128
          Width = 115
          Height = 25
          Caption = 'Search'
          OnClick = Button11Click
        end
        object SpeedButton14: TSpeedButton
          Left = 53
          Top = 166
          Width = 115
          Height = 25
          Caption = 'NewRus -> NewEng'
          OnClick = SpeedButton14Click
        end
        object Resource1Name: TMemo
          Left = 0
          Top = 0
          Width = 332
          Height = 125
          Align = alTop
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Courier New'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object Resource1Size: TPanel
          Left = 182
          Top = 219
          Width = 102
          Height = 24
          BevelOuter = bvNone
          BorderStyle = bsSingle
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Courier New'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Text Resource #2'
      ImageIndex = 1
      object Button23: TSpeedButton
        Left = 314
        Top = 164
        Width = 115
        Height = 25
        Caption = 'Store Info'
        OnClick = Button23Click
      end
      object Button22: TSpeedButton
        Left = 314
        Top = 192
        Width = 115
        Height = 25
        Caption = 'Save info to file'
        OnClick = Button22Click
      end
      object SpeedButton24: TSpeedButton
        Left = 314
        Top = 136
        Width = 115
        Height = 25
        Caption = 'NewRus -> NewEng'
        OnClick = SpeedButton14Click
      end
      object ListBox2: TListBox
        Left = 0
        Top = 0
        Width = 205
        Height = 250
        Align = alLeft
        ItemHeight = 13
        TabOrder = 0
        OnClick = ListBox2Click
      end
      object Resource2Name: TEdit
        Left = 227
        Top = 8
        Width = 290
        Height = 24
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        MaxLength = 22
        ParentFont = False
        TabOrder = 1
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Text Resource #3'
      ImageIndex = 2
      object Button33: TSpeedButton
        Left = 314
        Top = 164
        Width = 115
        Height = 25
        Caption = 'Store Info'
        OnClick = Button33Click
      end
      object Button32: TSpeedButton
        Left = 314
        Top = 192
        Width = 115
        Height = 25
        Caption = 'Save info to file'
        OnClick = Button32Click
      end
      object SpeedButton34: TSpeedButton
        Left = 314
        Top = 136
        Width = 115
        Height = 25
        Caption = 'NewRus -> NewEng'
        OnClick = SpeedButton14Click
      end
      object ListBox3: TListBox
        Left = 0
        Top = 0
        Width = 205
        Height = 250
        Align = alLeft
        ItemHeight = 13
        TabOrder = 0
        OnClick = ListBox3Click
      end
      object Resource3Name: TEdit
        Left = 227
        Top = 8
        Width = 290
        Height = 24
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        MaxLength = 32
        ParentFont = False
        TabOrder = 1
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Text Resource #4'
      ImageIndex = 3
      object Button43: TSpeedButton
        Left = 314
        Top = 164
        Width = 115
        Height = 25
        Caption = 'Store Info'
        OnClick = Button43Click
      end
      object Button42: TSpeedButton
        Left = 314
        Top = 192
        Width = 115
        Height = 25
        Caption = 'Save info to file'
        OnClick = Button42Click
      end
      object SpeedButton44: TSpeedButton
        Left = 314
        Top = 136
        Width = 115
        Height = 25
        Caption = 'NewRus -> NewEng'
        OnClick = SpeedButton14Click
      end
      object ListBox4: TListBox
        Left = 0
        Top = 0
        Width = 205
        Height = 250
        Align = alLeft
        ItemHeight = 13
        TabOrder = 0
        OnClick = ListBox4Click
      end
      object Resource4Name: TEdit
        Left = 227
        Top = 8
        Width = 290
        Height = 24
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        MaxLength = 32
        ParentFont = False
        TabOrder = 1
      end
    end
  end
  object Log: TMemo
    Left = 0
    Top = 330
    Width = 545
    Height = 89
    Align = alBottom
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'EXE'
    FileName = 'FALL'
    Filter = 'TES2: Daggerfall EXE files|*.EXE'
    InitialDir = '.'
    Left = 12
    Top = 8
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'EXE'
    FileName = 'FALL'
    Filter = 'TES2: Daggerfall EXE files|*.EXE'
    InitialDir = '.'
    Left = 44
    Top = 8
  end
end
