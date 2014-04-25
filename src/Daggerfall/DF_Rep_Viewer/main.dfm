object Form1: TForm1
  Left = 312
  Top = 150
  Width = 553
  Height = 487
  Caption = 'TES2: Daggerfall - Программа просмотра репутации'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 545
    Height = 64
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label4: TLabel
      Left = 1
      Top = 8
      Width = 540
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = 'Укажите путь к текущему местоположению игры'
    end
    object Edit1: TEdit
      Left = 2
      Top = 36
      Width = 505
      Height = 21
      Enabled = False
      ReadOnly = True
      TabOrder = 0
      Text = 'C:\GAMES\DAGGER\'
    end
    object Button2: TButton
      Left = 509
      Top = 36
      Width = 33
      Height = 21
      Caption = '...'
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 64
    Width = 545
    Height = 396
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    Visible = False
    object Label1: TLabel
      Left = 8
      Top = 12
      Width = 202
      Height = 13
      Caption = 'Выберите требуемую сохраненную игру'
    end
    object Button1: TButton
      Left = 378
      Top = 8
      Width = 163
      Height = 21
      Caption = 'Просмотр репутации...'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Memo: TMemo
      Left = 0
      Top = 60
      Width = 545
      Height = 336
      Align = alBottom
      Color = clBlack
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 1
    end
    object cbSaveGame: TComboBox
      Left = 216
      Top = 8
      Width = 145
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 2
      Items.Strings = (
        'SAVE0'
        'SAVE1'
        'SAVE2'
        'SAVE3'
        'SAVE4'
        'SAVE5')
    end
    object cbEng: TCheckBox
      Left = 62
      Top = 36
      Width = 407
      Height = 17
      Caption = 
        'Английская версия игры (если '#39'птичку'#39' не ставить, значит русская' +
        ' версия)'
      TabOrder = 3
    end
  end
  object OpenDialog: TOpenDialog
    FileName = 'Зайдите в папку и нажмите '#39'Открыть'#39'...'
    InitialDir = '.'
    Title = 'Выберите местонахождение игры'
    Left = 20
    Top = 197
  end
end
