object Form1: TForm1
  Left = 294
  Top = 124
  Width = 587
  Height = 411
  Caption = 
    'The Elder Scrolls 2: Daggerfall - Fast Configurator by VorteX Dr' +
    'AgON'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 579
    Height = 74
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label4: TLabel
      Left = 4
      Top = 16
      Width = 569
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = 
        'Укажите путь к текущему местоположению игры и выберите файл конф' +
        'игурации Z.CFG'
    end
    object Button1: TButton
      Left = 536
      Top = 36
      Width = 33
      Height = 21
      Caption = '...'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 12
      Top = 36
      Width = 521
      Height = 21
      ReadOnly = True
      TabOrder = 1
      Text = 'C:\GAMES\DAGGER\'
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 74
    Width = 579
    Height = 310
    ActivePage = TabSheet3
    Align = alClient
    TabOrder = 1
    Visible = False
    object TabSheet1: TTabSheet
      Caption = 'Конфигурация'
      object Label1: TLabel
        Left = 1
        Top = 40
        Width = 106
        Height = 20
        Caption = 'Путь к ресурсам'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 1
        Top = 68
        Width = 63
        Height = 20
        Caption = 'Путь к CD'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 0
        Top = 92
        Width = 565
        Height = 21
        Alignment = taCenter
        AutoSize = False
        Caption = 
          '!!! для запуска без компакт-диска путь к CD должен быть равен пу' +
          'ти к игре!!!'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
      end
      object cb1: TCheckBox
        Left = 140
        Top = 168
        Width = 300
        Height = 17
        Caption = 'Чинить магические вещи'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = cb1Click
      end
      object cb2: TCheckBox
        Left = 140
        Top = 196
        Width = 300
        Height = 17
        Caption = 'Режим чит-кодов'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = cb2Click
      end
      object Edit2: TEdit
        Left = 112
        Top = 36
        Width = 449
        Height = 26
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnChange = Edit2Change
      end
      object Edit3: TEdit
        Left = 112
        Top = 64
        Width = 449
        Height = 26
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnChange = Edit3Change
      end
      object Button2: TButton
        Left = 156
        Top = 116
        Width = 260
        Height = 25
        Caption = 'Отучить игру от CD'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 152
        Top = 4
        Width = 269
        Height = 25
        Caption = 'Получить текущий путь к ресурсам'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 16
        Top = 244
        Width = 265
        Height = 25
        Caption = 'Сохранить изменения и выйти'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 292
        Top = 244
        Width = 265
        Height = 25
        Caption = 'Выйти без сохранения изменений'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
        OnClick = Button5Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Просмотр содержимого Z.CFG'
      ImageIndex = 1
      object Memo: TMemo
        Left = 0
        Top = 0
        Width = 571
        Height = 282
        Align = alClient
        Color = clTeal
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clAqua
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Рекомендации по запуску игры под Windows XP'
      ImageIndex = 2
      object Label5: TLabel
        Left = 0
        Top = 8
        Width = 565
        Height = 21
        AutoSize = False
        Caption = 
          '   -   для запуска игры под Windows XP необходимо запускать файл' +
          ' '#39'FALL.EXE'#39' с параметром '#39'Z.CFG'#39' ;'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 0
        Top = 32
        Width = 565
        Height = 21
        AutoSize = False
        Caption = 
          '   -   для упрощения запуска рекомендуется создать пакетный файл' +
          ' со строкой запуска '#39'@fall.exe z.cfg'#39
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 0
        Top = 56
        Width = 565
        Height = 21
        AutoSize = False
        Caption = 
          '   -   для звука в игре в setup.exe выбирайте '#39'Sound Blaster Pro' +
          #39
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label8: TLabel
        Left = 0
        Top = 80
        Width = 565
        Height = 21
        AutoSize = False
        Caption = '   -   для музыки в игре в setup.exe выбирайте '#39'MPU-401'#39
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label9: TLabel
        Left = 0
        Top = 104
        Width = 565
        Height = 21
        AutoSize = False
        Caption = 
          '   -   если звук и музыка так и не появились, используйте пакет ' +
          'VDM Sound'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label10: TLabel
        Left = 0
        Top = 128
        Width = 565
        Height = 21
        AutoSize = False
        Caption = 
          '   -   проверьте наличие папок '#39'SAVE0'#39', ... , '#39'SAVE5'#39' в папке с ' +
          'игрой. Создайте их, если они отсутствуют.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '*.CFG'
    FileName = 'Z.CFG'
    Filter = 'Daggerfall Config Files|*.CFG'
    InitialDir = '.'
    Title = 'Выберите местонахождение игры'
    Left = 12
    Top = 341
  end
end
