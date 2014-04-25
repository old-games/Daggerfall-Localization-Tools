object Form1: TForm1
  Left = 317
  Top = 136
  BorderStyle = bsSingle
  Caption = 'TES: Daggerfall '#39'MAPS.BSA'#39' Editor'
  ClientHeight = 464
  ClientWidth = 545
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
  object Log: TMemo
    Left = 0
    Top = 375
    Width = 545
    Height = 89
    Align = alBottom
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Button2: TButton
    Left = 68
    Top = 4
    Width = 159
    Height = 25
    Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100#1089#1103' '#1082' MAPS.BSA'
    TabOrder = 0
    OnClick = Button2Click
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 36
    Width = 545
    Height = 339
    ActivePage = TabSheet2
    Align = alBottom
    TabIndex = 1
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = 'MAPS.BSA'
      object Panel1: TPanel
        Left = 0
        Top = 3
        Width = 537
        Height = 308
        Align = alBottom
        BevelOuter = bvNone
        Caption = 'Panel1'
        Enabled = False
        TabOrder = 0
        object Label1: TLabel
          Left = 200
          Top = 4
          Width = 142
          Height = 13
          Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1077#1075#1080#1086#1085' '#1058#1072#1084#1088#1080#1101#1083#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object Bevel1: TBevel
          Left = 0
          Top = 0
          Width = 537
          Height = 2
          Align = alTop
          Shape = bsTopLine
        end
        object Bevel2: TBevel
          Left = 0
          Top = 78
          Width = 537
          Height = 2
          Align = alBottom
          Shape = bsBottomLine
        end
        object Button1: TButton
          Left = 176
          Top = 47
          Width = 189
          Height = 25
          Caption = #1069#1082#1089#1087#1086#1088#1090' '#1092#1072#1081#1083#1086#1074' '#1088#1077#1075#1080#1086#1085#1072
          TabOrder = 1
          OnClick = Button1Click
        end
        object Regions: TComboBox
          Left = 132
          Top = 23
          Width = 273
          Height = 21
          Style = csDropDownList
          DropDownCount = 20
          ItemHeight = 13
          TabOrder = 0
          OnChange = RegionsChange
          Items.Strings = (
            '00 = Alik'#39'r Desert'
            '01 = Dragontail Mountains'
            '02 = Glenpoint Foothills*'
            '03 = Daggerfall Bluffs*'
            '04 = Yeorth Burrowland*'
            '05 = Dwynnen'
            '06 = Ravennian Forest*'
            '07 = Devilrock*'
            '08 = Malekna Forest*'
            '09 = Isle of Balfiera'
            '10 = Bantha*'
            '11 = Dak'#39'fron'
            '12 = Islands in the Western Iliac Bay*'
            '13 = Tamarilyn Point*'
            '14 = Lainlyn Cliffs*'
            '15 = Bjoulsae River*'
            '16 = Wrothgarian Mountains'
            '17 = Daggerfall'
            '18 = Glenpoint'
            '19 = Betony'
            '20 = Sentinel'
            '21 = Anticlere'
            '22 = Lainlyn'
            '23 = Wayrest'
            '24 = Gen Tem High Rock village*'
            '25 = Gen Rai Hammerfell village*'
            '26 = Orsinium Area'
            '27 = Skeffington Wood*'
            '28 = Hammerfell bay coast*'
            '29 = Hammerfell sea coast*'
            '30 = High Rock bay coast*'
            '31 = High Rock sea coast'
            '32 = Northmoor'
            '33 = Menevia'
            '34 = Alcaire'
            '35 = Koegria'
            '36 = Bhoriane'
            '37 = Kambria'
            '38 = Phrygias'
            '39 = Urvaius'
            '40 = Ykalon'
            '41 = Daenia'
            '42 = Shalgora'
            '43 = Abibon-Gora'
            '44 = Kairou'
            '45 = Pothago'
            '46 = Myrkwasa'
            '47 = Ayasofya'
            '48 = Tigonus'
            '49 = Kozanset'
            '50 = Satakalaam'
            '51 = Totambu'
            '52 = Mournoth'
            '53 = Ephesus'
            '54 = Santaki'
            '55 = Antiphyllos'
            '56 = Bergama'
            '57 = Gavaudon'
            '58 = Tulune'
            '59 = Glenumbra Moors'
            '60 = Ilessan Hills'
            '61 = Cybiades')
        end
        object PageControl2: TPageControl
          Left = 0
          Top = 80
          Width = 537
          Height = 228
          ActivePage = TabSheet6
          Align = alBottom
          TabIndex = 3
          TabOrder = 2
          object TabSheet3: TTabSheet
            Caption = 'MAPPITEM'
            DesignSize = (
              529
              200)
            object Label3: TLabel
              Left = 340
              Top = 0
              Width = 95
              Height = 13
              Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1083#1086#1082#1072#1094#1080#1080
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsUnderline]
              ParentFont = False
            end
            object LocationRecordList: TListBox
              Left = 245
              Top = 16
              Width = 289
              Height = 182
              Anchors = [akLeft, akTop, akRight, akBottom]
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Courier New'
              Font.Style = [fsBold]
              ItemHeight = 16
              ParentFont = False
              TabOrder = 0
            end
          end
          object TabSheet4: TTabSheet
            Caption = 'MAPDITEM'
            ImageIndex = 1
            DesignSize = (
              529
              200)
            object Label6: TLabel
              Left = 340
              Top = 0
              Width = 95
              Height = 13
              Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1083#1086#1082#1072#1094#1080#1080
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsUnderline]
              ParentFont = False
            end
            object DungeonRecordList: TListBox
              Left = 240
              Top = 16
              Width = 289
              Height = 182
              Anchors = [akLeft, akTop, akRight, akBottom]
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Courier New'
              Font.Style = [fsBold]
              ItemHeight = 16
              ParentFont = False
              TabOrder = 0
            end
          end
          object TabSheet5: TTabSheet
            Caption = 'MAPTABLE'
            ImageIndex = 2
          end
          object TabSheet6: TTabSheet
            Caption = 'MAPNAMES'
            ImageIndex = 3
            object Label2: TLabel
              Left = 340
              Top = 0
              Width = 95
              Height = 13
              Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1083#1086#1082#1072#1094#1080#1080
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsUnderline]
              ParentFont = False
            end
            object Label4: TLabel
              Left = 32
              Top = 172
              Width = 36
              Height = 13
              Caption = #1057#1090#1088#1086#1082#1072
            end
            object Label5: TLabel
              Left = 124
              Top = 172
              Width = 33
              Height = 13
              Caption = #1044#1083#1080#1085#1072
            end
            object Button3: TButton
              Left = 0
              Top = 72
              Width = 244
              Height = 25
              Caption = #1047#1072#1087#1086#1084#1085#1080#1090#1100' '#1080#1084#1077#1085#1072' '#1083#1086#1082#1072#1094#1080#1081
              TabOrder = 0
              OnClick = Button3Click
            end
            object LocationList: TMemo
              Left = 246
              Top = 15
              Width = 280
              Height = 183
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Courier New'
              Font.Style = [fsBold]
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 1
              OnClick = LocationListClick
              OnKeyDown = LocationListKeyDown
              OnKeyPress = LocationListKeyPress
            end
            object Edit1: TEdit
              Left = 71
              Top = 169
              Width = 50
              Height = 21
              TabOrder = 2
            end
            object Edit2: TEdit
              Left = 163
              Top = 169
              Width = 50
              Height = 21
              TabOrder = 3
            end
            object Button5: TButton
              Left = 0
              Top = 44
              Width = 120
              Height = 25
              Caption = 'MAPPITEM <-'
              TabOrder = 4
              OnClick = Button5Click
            end
            object Button6: TButton
              Left = 0
              Top = 100
              Width = 120
              Height = 25
              Caption = #1089#1086#1093#1088#1072#1085#1080#1090#1100' MAPPITEM'
              TabOrder = 5
              OnClick = Button6Click
            end
            object Button7: TButton
              Left = 0
              Top = 128
              Width = 243
              Height = 25
              Caption = #1057#1087#1080#1089#1086#1082' '#1080#1084#1077#1085' '#1074' '#1092#1072#1081#1083
              TabOrder = 6
              OnClick = Button7Click
            end
            object Button11: TButton
              Left = 124
              Top = 44
              Width = 120
              Height = 25
              Caption = 'MAPDITEM <-'
              TabOrder = 7
              OnClick = Button11Click
            end
            object Button12: TButton
              Left = 124
              Top = 100
              Width = 120
              Height = 25
              Caption = #1089#1086#1093#1088#1072#1085#1080#1090#1100' MAPDITEM'
              TabOrder = 8
              OnClick = Button12Click
            end
            object Button13: TButton
              Left = 124
              Top = 16
              Width = 119
              Height = 25
              Caption = 'NewRus -> NewEng'
              TabOrder = 9
              OnClick = Button13Click
            end
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'MONSTER.BSA'
      ImageIndex = 1
      object MonstersList: TMemo
        Left = 210
        Top = 28
        Width = 280
        Height = 246
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object Button10: TButton
        Left = 8
        Top = 172
        Width = 189
        Height = 25
        Caption = #1047#1072#1087#1086#1084#1085#1080#1090#1100' '#1080#1084#1077#1085#1072' '#1084#1086#1085#1089#1090#1088#1086#1074
        TabOrder = 1
        OnClick = Button10Click
      end
      object Button14: TButton
        Left = 84
        Top = 144
        Width = 113
        Height = 25
        Caption = 'NewRus -> NewEng'
        TabOrder = 2
        OnClick = Button14Click
      end
    end
  end
  object Button8: TButton
    Left = 236
    Top = 4
    Width = 181
    Height = 25
    Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100#1089#1103' '#1082' MONSTER.BSA'
    TabOrder = 3
    OnClick = Button8Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer1Timer
    Left = 12
    Top = 336
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'BSA'
    FileName = 'MAPS'
    Filter = 'TES: Daggerfall BSA files|*.BSA'
    InitialDir = '.'
    Left = 4
    Top = 4
  end
end
