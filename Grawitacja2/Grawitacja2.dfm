object Form1: TForm1
  Left = 192
  Top = 125
  Width = 979
  Height = 563
  Caption = 'Grawitacja - Filip Jurczak'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 20
  object ObszarObrazu: TPaintBox
    Left = 201
    Top = 0
    Width = 762
    Height = 524
    Align = alClient
    Color = clBlack
    ParentColor = False
    OnMouseDown = ObszarObrazuMouseDown
    OnMouseMove = ObszarObrazuMouseMove
    OnMouseUp = ObszarObrazuMouseUp
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 201
    Height = 524
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 280
      Width = 23
      Height = 20
      Caption = 'm1'
    end
    object Label2: TLabel
      Left = 16
      Top = 344
      Width = 23
      Height = 20
      Caption = 'm2'
    end
    object Label3: TLabel
      Left = 16
      Top = 408
      Width = 23
      Height = 20
      Caption = 'm3'
    end
    object BtnStartStop: TBitBtn
      Left = 40
      Top = 40
      Width = 105
      Height = 65
      Caption = 'START'
      TabOrder = 0
      OnClick = BtnStartStopClick
    end
    object RG1: TRadioGroup
      Left = 8
      Top = 136
      Width = 169
      Height = 105
      Caption = 'Liczba obiekt'#243'w'
      TabOrder = 1
    end
    object RB2Obiekty: TRadioButton
      Left = 24
      Top = 168
      Width = 113
      Height = 17
      Caption = 'Dwa obiekty'
      Checked = True
      TabOrder = 2
      TabStop = True
      OnClick = RB2ObiektyClick
    end
    object RB3Obiekty: TRadioButton
      Left = 24
      Top = 200
      Width = 113
      Height = 17
      Caption = 'Trzy obiekty'
      TabOrder = 3
      OnClick = RB3ObiektyClick
    end
    object TBM1: TTrackBar
      Left = 40
      Top = 280
      Width = 150
      Height = 45
      Max = 100
      Min = 20
      Orientation = trHorizontal
      Frequency = 10
      Position = 70
      SelEnd = 0
      SelStart = 0
      TabOrder = 4
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TBM1Change
    end
    object TBM2: TTrackBar
      Left = 40
      Top = 344
      Width = 150
      Height = 45
      Max = 100
      Min = 20
      Orientation = trHorizontal
      Frequency = 10
      Position = 50
      SelEnd = 0
      SelStart = 0
      TabOrder = 5
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TBM2Change
    end
    object TBM3: TTrackBar
      Left = 40
      Top = 408
      Width = 150
      Height = 45
      Enabled = False
      Max = 100
      Min = 20
      Orientation = trHorizontal
      Frequency = 10
      Position = 30
      SelEnd = 0
      SelStart = 0
      TabOrder = 6
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TBM3Change
    end
    object BtnUstawieniaPoczatkowe: TBitBtn
      Left = 8
      Top = 464
      Width = 185
      Height = 41
      Caption = 'Ustawienia pocz'#261'tkowe'
      TabOrder = 7
      OnClick = BtnUstawieniaPoczatkoweClick
    end
  end
  object TimerRuchu: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerRuchuTimer
    Left = 176
    Top = 24
  end
  object TimerStart: TTimer
    Interval = 10
    OnTimer = TimerStartTimer
    Left = 240
    Top = 40
  end
end
