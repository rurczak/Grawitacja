//---------------------------------------------------------------------------

#ifndef Grawitacja2H
#define Grawitacja2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>

#include "ObrazekBMP.h"
#include "skala.h"
#include "Tory.h"
#include "Wektory.h"
#include <math.h>
#include <ComCtrls.hpp>
const double G = 1000;
const double skalaV = 0.1;
const double skalaXY = 10;
const double gestosc = 500;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TBitBtn *BtnStartStop;
    TPaintBox *ObszarObrazu;
    TRadioGroup *RG1;
    TRadioButton *RB2Obiekty;
    TRadioButton *RB3Obiekty;
    TTrackBar *TBM1;
    TTrackBar *TBM2;
    TTrackBar *TBM3;
    TTimer *TimerRuchu;
    TTimer *TimerStart;
        TBitBtn *BtnUstawieniaPoczatkowe;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
    void __fastcall BtnStartStopClick(TObject *Sender);
    void __fastcall TimerStartTimer(TObject *Sender);
    void __fastcall RB2ObiektyClick(TObject *Sender);
    void __fastcall RB3ObiektyClick(TObject *Sender);
    void __fastcall TimerRuchuTimer(TObject *Sender);
    void __fastcall TBM1Change(TObject *Sender);
    void __fastcall TBM2Change(TObject *Sender);
    void __fastcall TBM3Change(TObject *Sender);
    void __fastcall ObszarObrazuMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ObszarObrazuMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall ObszarObrazuMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall BtnUstawieniaPoczatkoweClick(TObject *Sender);
private:	// User declarations
    TObrazekBMP obrazekBMP;
    TSkalowanie skala;
    TTor tor1, tor2, tor3;
    double xR1, yR1, xR2, yR2, xR3, yR3;
    int xE1, yE1, xE2, yE2, xE3, yE3;
    int tPoprz,t, fPoprzX1, fPoprzY1,fPoprzX2, fPoprzY2,fPoprzX3, fPoprzY3;
    double M1, M2, M3;
    double R1,R2,R3;
    double vx1,vy1,vx2,vy2,vx3,vy3,v1,v2,v3;
    double ax1, ay1,ax2,ay2,ax3,ay3;
    void Rysuj();
    void SrodekCiezkosci();
    void Poczatek();
    TCanvas *kanwa;
    bool przesuwaj2, zmieniajV2, przesuwaj1, przesuwaj3, zmieniajV3;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
