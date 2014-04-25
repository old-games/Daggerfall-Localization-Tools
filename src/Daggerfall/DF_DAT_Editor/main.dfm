object Form3: TForm3
  Left = 284
  Top = 152
  Width = 662
  Height = 449
  Caption = 'TES2: Daggerfall. DAT-files editor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Log: TMemo
    Left = 0
    Top = 333
    Width = 654
    Height = 89
    Align = alBottom
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 654
    Height = 54
    Align = alTop
    TabOrder = 1
    object Button1: TButton
      Left = 7
      Top = 8
      Width = 125
      Height = 25
      Caption = #1054#1090#1082#1088#1099#1090#1100' DAT-'#1092#1072#1081#1083
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 331
      Top = 8
      Width = 125
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' DAT-'#1092#1072#1081#1083
      TabOrder = 1
      OnClick = Button2Click
    end
    object FixBox: TCheckBox
      Left = 132
      Top = 36
      Width = 197
      Height = 15
      Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1074' '#1088#1091#1089#1089#1082#1086#1081' '#1088#1072#1089#1082#1083#1072#1076#1082#1077
      TabOrder = 2
    end
    object Button3: TButton
      Left = 134
      Top = 8
      Width = 195
      Height = 25
      Caption = 'NewRus -> NewEng'
      TabOrder = 3
      OnClick = Button3Click
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 54
    Width = 654
    Height = 279
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = 'NAMEGEN.DAT'
      object ParticlesList: TMemo
        Left = 366
        Top = 0
        Width = 280
        Height = 251
        Align = alRight
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'DAT'
    Filter = 'TES2:Daggerfall DAT files|*.DAT'
    InitialDir = '.'
    Left = 12
    Top = 108
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'DAT'
    Filter = 'TES2:Daggerfall DAT files|*.DAT'
    InitialDir = '.'
    Left = 48
    Top = 108
  end
end
