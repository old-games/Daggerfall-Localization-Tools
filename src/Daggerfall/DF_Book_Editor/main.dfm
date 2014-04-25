object Form1: TForm1
  Left = 315
  Top = 123
  BorderStyle = bsSingle
  Caption = 'TES: Daggerfall Book Editor'
  ClientHeight = 450
  ClientWidth = 565
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 474
    Top = 0
    Width = 91
    Height = 450
    Align = alRight
    TabOrder = 0
    DesignSize = (
      91
      450)
    object Bevel3: TBevel
      Left = 1
      Top = 1
      Width = 89
      Height = 152
      Align = alTop
      Shape = bsBottomLine
    end
    object Bevel2: TBevel
      Left = 1
      Top = 227
      Width = 89
      Height = 74
      Align = alTop
      Shape = bsBottomLine
    end
    object Bevel4: TBevel
      Left = 1
      Top = 153
      Width = 89
      Height = 74
      Align = alTop
      Shape = bsBottomLine
    end
    object SpeedButton1: TSpeedButton
      Left = 3
      Top = 352
      Width = 23
      Height = 22
      Anchors = [akLeft, akBottom]
      Caption = '<'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Layout = blGlyphBottom
      ParentFont = False
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 65
      Top = 352
      Width = 23
      Height = 22
      Anchors = [akLeft, akBottom]
      Caption = '>'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Layout = blGlyphBottom
      ParentFont = False
      OnClick = SpeedButton2Click
    end
    object SpeedButton3: TSpeedButton
      Left = 27
      Top = 352
      Width = 37
      Height = 22
      Anchors = [akLeft, akBottom]
      Caption = '|'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Layout = blGlyphBottom
      ParentFont = False
      OnClick = SpeedButton3Click
    end
    object Label1: TLabel
      Left = 20
      Top = 374
      Width = 50
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = #1057#1090#1088#1072#1085#1080#1094#1099
    end
    object Label2: TLabel
      Left = 38
      Top = 394
      Width = 12
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = #1080#1079
    end
    object SpeedButton5: TSpeedButton
      Left = 3
      Top = 328
      Width = 85
      Height = 22
      Anchors = [akLeft, akBottom]
      Caption = 'Add Font Tag'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Layout = blGlyphBottom
      ParentFont = False
      OnClick = SpeedButton5Click
    end
    object Label3: TLabel
      Left = 30
      Top = 410
      Width = 30
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = #1057#1090#1088#1086#1082
    end
    object Label6: TLabel
      Left = 10
      Top = 156
      Width = 70
      Height = 13
      Caption = 'FACTION.TXT'
    end
    object Label7: TLabel
      Left = 6
      Top = 229
      Width = 78
      Height = 13
      Caption = 'BIOGXXXX.TXT'
    end
    object SpeedButton4: TSpeedButton
      Left = 5
      Top = 120
      Width = 80
      Height = 25
      Caption = 'Store Page'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Layout = blGlyphBottom
      ParentFont = False
      OnClick = SpeedButton4Click
    end
    object Button5: TButton
      Left = 5
      Top = 8
      Width = 80
      Height = 25
      Caption = 'Load TXT'
      TabOrder = 0
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 5
      Top = 36
      Width = 80
      Height = 25
      Caption = 'Save TXT'
      TabOrder = 1
      OnClick = Button6Click
    end
    object CP: TPanel
      Left = 4
      Top = 390
      Width = 33
      Height = 21
      Anchors = [akLeft, akBottom]
      BevelOuter = bvNone
      BorderStyle = bsSingle
      Caption = '1'
      TabOrder = 2
    end
    object PC: TPanel
      Left = 52
      Top = 390
      Width = 33
      Height = 21
      Anchors = [akLeft, akBottom]
      BevelOuter = bvNone
      BorderStyle = bsSingle
      Caption = '100'
      TabOrder = 3
    end
    object LC: TPanel
      Left = 29
      Top = 423
      Width = 33
      Height = 21
      Anchors = [akLeft, akBottom]
      BevelOuter = bvNone
      BorderStyle = bsSingle
      Caption = '1'
      TabOrder = 4
    end
    object PCMax: TCSpinEdit
      Left = 24
      Top = 304
      Width = 42
      Height = 22
      Anchors = [akLeft, akBottom]
      MaxValue = 100
      MinValue = 1
      TabOrder = 5
      Value = 1
      OnChange = PCMaxChange
    end
    object Button4: TButton
      Left = 5
      Top = 182
      Width = 80
      Height = 25
      Caption = 'Rus -> Eng'
      TabOrder = 7
      OnClick = Button4Click
    end
    object Button8: TButton
      Left = 5
      Top = 255
      Width = 80
      Height = 25
      Caption = 'Rus -> Eng'
      TabOrder = 8
      OnClick = Button8Click
    end
    object Button2: TButton
      Left = 5
      Top = 92
      Width = 80
      Height = 25
      Caption = 'Rus -> Eng'
      TabOrder = 6
      OnClick = Button2Click
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 474
    Height = 450
    Align = alClient
    TabOrder = 1
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 472
      Height = 448
      Align = alClient
      TabOrder = 0
      object Memo: TMemo
        Left = 21
        Top = 61
        Width = 450
        Height = 309
        Align = alClient
        Color = clMenu
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
        OnChange = MemoChange
      end
      object Panel4: TPanel
        Left = 1
        Top = 1
        Width = 470
        Height = 60
        Align = alTop
        TabOrder = 0
        object Bevel1: TBevel
          Left = 1
          Top = 1
          Width = 441
          Height = 58
          Align = alLeft
          Shape = bsRightLine
        end
        object Label4: TLabel
          Left = 5
          Top = 11
          Width = 50
          Height = 13
          Caption = #1053#1072#1079#1074#1072#1085#1080#1077
        end
        object Label5: TLabel
          Left = 25
          Top = 35
          Width = 30
          Height = 13
          Caption = #1040#1074#1090#1086#1088
        end
        object Title: TEdit
          Left = 61
          Top = 8
          Width = 368
          Height = 21
          MaxLength = 64
          TabOrder = 0
        end
        object Author: TEdit
          Left = 61
          Top = 32
          Width = 368
          Height = 21
          MaxLength = 160
          TabOrder = 1
        end
      end
      object Panel5: TPanel
        Left = 1
        Top = 370
        Width = 470
        Height = 77
        Align = alBottom
        TabOrder = 2
        object Log: TMemo
          Left = 1
          Top = 1
          Width = 468
          Height = 75
          Align = alClient
          Color = clMenu
          ScrollBars = ssVertical
          TabOrder = 0
        end
      end
      object Memo1: TMemo
        Left = 1
        Top = 61
        Width = 20
        Height = 309
        Align = alLeft
        Color = clMenu
        Enabled = False
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        Lines.Strings = (
          '01'
          '02'
          '03'
          '04'
          '05'
          '06'
          '07'
          '08'
          '09'
          '10'
          '11'
          '12'
          '13'
          '14'
          '15'
          '16'
          '17'
          '18'
          '19'
          '20'
          '21'
          '22'
          '23'
          '24'
          '25'
          '26'
          '27'
          '28'
          '29'
          '30'
          '31'
          '32'
          '33'
          '34'
          '35'
          '36'
          '37'
          '38'
          '39'
          '40')
        ParentFont = False
        TabOrder = 3
      end
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'TXT'
    Filter = 'TES:Daggerfall book files|*.TXT'
    InitialDir = '.'
    Left = 12
    Top = 384
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'TXT'
    Filter = 'TES:Daggerfall book files|*.TXT'
    InitialDir = '.'
    Left = 48
    Top = 384
  end
  object Timer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = TimerTimer
    Left = 85
    Top = 384
  end
end
