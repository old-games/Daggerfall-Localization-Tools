object Form1: TForm1
  Left = 280
  Top = 152
  Width = 569
  Height = 459
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 59
    Width = 561
    Height = 3
    Align = alTop
    Shape = bsTopLine
  end
  object Log: TMemo
    Left = 0
    Top = 343
    Width = 561
    Height = 89
    TabStop = False
    Align = alBottom
    Color = clSilver
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 561
    Height = 59
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object SpeedButton2: TSpeedButton
      Left = 11
      Top = 15
      Width = 118
      Height = 25
      Caption = #1055#1091#1090#1100' '#1082' QRC-'#1092#1072#1081#1083#1072#1084'...'
      OnClick = SpeedButton2Click
    end
  end
  object IMGList: TListBox
    Left = 0
    Top = 62
    Width = 128
    Height = 281
    Align = alLeft
    Color = clSilver
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ItemHeight = 16
    ParentFont = False
    TabOrder = 2
    OnClick = IMGListClick
  end
  object Panel1: TPanel
    Left = 128
    Top = 62
    Width = 433
    Height = 281
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 3
    object ScrollBox1: TScrollBox
      Left = 0
      Top = 0
      Width = 433
      Height = 240
      VertScrollBar.Tracking = True
      Align = alClient
      TabOrder = 0
      object Image: TImage
        Left = 0
        Top = 0
        Width = 337
        Height = 209
      end
    end
    object Panel3: TPanel
      Left = 0
      Top = 240
      Width = 433
      Height = 41
      Align = alBottom
      BevelOuter = bvNone
      BorderStyle = bsSingle
      TabOrder = 1
    end
  end
  object DirDlg: TOpenDialog
    FileName = 'Select directory...'
    InitialDir = '.'
    Left = 12
    Top = 52
  end
end
