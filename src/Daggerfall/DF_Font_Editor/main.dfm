object Form1: TForm1
  Left = 300
  Top = 110
  BorderStyle = bsDialog
  Caption = 'Form1'
  ClientHeight = 326
  ClientWidth = 348
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 348
    Height = 33
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 164
      Top = 8
      Width = 190
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = 'Label1'
    end
    object Button2: TButton
      Left = 80
      Top = 4
      Width = 75
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button1: TButton
      Left = 4
      Top = 4
      Width = 75
      Height = 25
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 1
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 149
    Top = 33
    Width = 199
    Height = 226
    Align = alClient
    TabOrder = 1
    object iLedMatrix: TiLedMatrix
      Left = 2
      Top = 34
      Width = 554
      Height = 554
      OnMouseDown = iLedMatrixMouseDown
      OnMouseUp = iLedMatrixMouseUp
      ColCount = 16
      RowCount = 16
      IndicatorWidth = 33
      IndicatorHeight = 33
      IndicatorCaptionActiveFont.Charset = DEFAULT_CHARSET
      IndicatorCaptionActiveFont.Color = clWindowText
      IndicatorCaptionActiveFont.Height = -11
      IndicatorCaptionActiveFont.Name = 'MS Sans Serif'
      IndicatorCaptionActiveFont.Style = []
      IndicatorCaptionInactiveFont.Charset = DEFAULT_CHARSET
      IndicatorCaptionInactiveFont.Color = clWhite
      IndicatorCaptionInactiveFont.Height = -11
      IndicatorCaptionInactiveFont.Name = 'MS Sans Serif'
      IndicatorCaptionInactiveFont.Style = []
      SpacingHorizontal = 1
      SpacingVertical = 1
      IndicatorShowReflection = False
      OnMouseMoveIndicator = iLedMatrixMouseMoveIndicator
      OnClickIndicator = iLedMatrixClickIndicator
    end
    object iSlider: TiSlider
      Left = 1
      Top = 6
      Width = 188
      Height = 33
      Position = 1
      PositionMax = 16
      PositionMin = 1
      CurrentMax = 16
      CurrentMin = 1
      OnPositionChange = iSliderPositionChange
      KeyArrowStepSize = 1
      KeyPageStepSize = 10
      MouseWheelStepSize = 1
      Orientation = ioHorizontal
      PointerHeight = 8
      PointerWidth = 8
      TrackStyle = istsBevelLowered
      OffsetX = 1
      TickMajorCount = 16
      TickMinorCount = 3
      TickMinorLength = 1
      TickMargin = 0
      TickLabelMargin = 0
      TickLabelFont.Charset = DEFAULT_CHARSET
      TickLabelFont.Color = clWindowText
      TickLabelFont.Height = -11
      TickLabelFont.Name = 'Arial Narrow'
      TickLabelFont.Style = []
      TabOrder = 1
      PositionMax_2 = 16
      KeyArrowStepSize_2 = 1
      KeyPageStepSize_2 = 10
    end
  end
  object Memo: TMemo
    Left = 0
    Top = 259
    Width = 348
    Height = 67
    Align = alBottom
    Color = clMenu
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object FontMatrixList: TListBox
    Left = 0
    Top = 33
    Width = 149
    Height = 226
    Align = alLeft
    Color = clMenu
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ItemHeight = 16
    ParentFont = False
    TabOrder = 3
    OnClick = FontMatrixListClick
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'FNT'
    FileName = 'FONT0000'
    Filter = 'TES:Daggerfall font files|*.FNT'
    InitialDir = '.'
    Left = 12
    Top = 40
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'FNT'
    FileName = 'FONT0000'
    Filter = 'TES:Daggerfall font files|*.FNT'
    InitialDir = '.'
    Left = 44
    Top = 40
  end
end
