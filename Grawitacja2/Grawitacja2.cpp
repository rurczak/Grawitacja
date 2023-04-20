//---------------------------------------------------------------------------

#include <vcl.h>
#include "math.h"
#pragma hdrstop

#include "Grawitacja2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    kanwa = obrazekBMP.kanwa;

}
//---------------------------------------------------------------------------

void TForm1::SrodekCiezkosci()
{
    if(RB2Obiekty->Checked) {v1 = v2*M2/M1; vx1 = -vx2*M2/M1; vy1 = -vy2*M2/M1;}
    else {vx1 = -(vx2*M2 + vx3*M3)/M1; vy1 = -(vy2*M2 + vy3*M3)/M1; v1 = sqrt(vx1*vx1 + vy1*vy1);}
}

//---------------------------------------------------------------------------
void TForm1::Poczatek()
{
    R1 = 70/3;
    R2 = 50/3;
    R3 = 30/3;
    M1 = R1*R1*R1*gestosc;
    M2 = R2*R2*R2*gestosc;
    M3 = R3*R3*R3*gestosc;
    vx2 = -500; vy2 = 1000; v2 = sqrt(vx2*vx2 + vy2*vy2);
    vx3 = 700; vy3 = 600; v3 = sqrt(vx3*vx3 + vy3*vy3);
    if(RB2Obiekty->Checked) {v1 = v2*M2/M1; vx1 = -vx2*M2/M1; vy1 = -vy2*M2/M1;}
    else {vx1 = -(vx2*M2 + vx3*M3)/M1; vy1 = -(vy2*M2 + vy3*M3)/M1; v1 = sqrt(vx1*vx1 + vy1*vy1);}

    xE1=ObszarObrazu->Width/2; yE1=ObszarObrazu->Height/2;
    xE2=ObszarObrazu->Width/2 + 200; yE2=ObszarObrazu->Height/2;
    xE3=ObszarObrazu->Width/2 + 200; yE3=ObszarObrazu->Height/2 + 200;
    xR1 = skalaXY*xE1; yR1 = skalaXY*yE1;
    xR2 = skalaXY*xE2; yR2 = skalaXY*yE2;
    xR3 = skalaXY*xE3; yR3 = skalaXY*yE3;
    Rysuj();
}
//---------------------------------------------------------------------------

void TForm1::Rysuj()
{
    TWektor v2(vx2,vy2,skalaV);
    TWektor v1(vx1,vy1,skalaV);
    obrazekBMP.Czysc(ObszarObrazu->Width,ObszarObrazu->Height,clBlack);
    kanwa->Pen->Color = clSilver;
    kanwa->Brush->Color = clSilver;
    kanwa->Ellipse(xE1-R1,yE1-R1,xE1+R1,yE1+R1);

    kanwa->Pen->Color = clGray;
    kanwa->Brush->Color = clGray;
    kanwa->Ellipse(xE2-R2,yE2-R2,xE2+R2,yE2+R2);
    tor1.Rysuj(kanwa,clGreen);
    tor2.Rysuj(kanwa,clBlue);
    if(RB3Obiekty->Checked) tor3.Rysuj(kanwa,clBlue);
    v1.Rysuj(kanwa,clGreen,xE1,yE1,skalaV,3);
    v2.Rysuj(kanwa,clBlue,xE2,yE2,skalaV,3);

    if(RB3Obiekty->Checked)
    {
    TWektor v3(vx3,vy3,skalaV);
    kanwa->Pen->Color = clGray;
    kanwa->Brush->Color = clGray;
    kanwa->Ellipse(xE3-R3,yE3-R3,xE3+R3,yE3+R3);
    v3.Rysuj(kanwa,clBlue,xE3,yE3,skalaV,3);
    }


    ObszarObrazu->Canvas->Draw(0,0,obrazekBMP.BMP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnStartStopClick(TObject *Sender)
{
    Rysuj();
    RB2Obiekty->Enabled = !RB2Obiekty->Enabled;
    RB3Obiekty->Enabled = !RB3Obiekty->Enabled;
    TimerRuchu->Enabled = !TimerRuchu->Enabled;
    TBM1->Enabled = !TBM1->Enabled;
    TBM2->Enabled = !TBM2->Enabled;
    TBM3->Enabled = !TBM3->Enabled;
    BtnUstawieniaPoczatkowe->Enabled = !BtnUstawieniaPoczatkowe->Enabled;

    if(BtnStartStop->Caption == "START")
    {
    BtnStartStop->Caption = "STOP";
    tPoprz = GetTickCount();
    }
    else {
        BtnStartStop->Caption = "START";
        tor1.CzyscPunkty();
        tor2.CzyscPunkty();
        tor3.CzyscPunkty();
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TimerStartTimer(TObject *Sender)
{
    TimerStart->Enabled = false;
    Poczatek();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RB2ObiektyClick(TObject *Sender)
{
    TBM3->Enabled = !TBM3->Enabled;
    SrodekCiezkosci();
    Rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RB3ObiektyClick(TObject *Sender)
{
    TBM3->Enabled = !TBM3->Enabled;
    SrodekCiezkosci();
    Rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerRuchuTimer(TObject *Sender)
{
    int tAkt = GetTickCount();
    double dt, dtN;
    int N=100;
    double fAktX1,fAktY1,fAktX2,fAktY2,fAktX3,fAktY3;
    double R12,R13,R23;

    dt = (tAkt-tPoprz)/1000.0;
    tPoprz = tAkt;
    t += dt;

    dtN = dt/N;
    if(RB2Obiekty->Checked){
    for(int i = 0;i<N;i++)
    {
        xR1 += (vx1 + (fPoprzX1/2)*dtN)*dtN;
        yR1 -= (vy1 + (fPoprzY1/2)*dtN)*dtN;
        xR2 += (vx2 + (fPoprzX2/2)*dtN)*dtN;
        yR2 -= (vy2 + (fPoprzY2/2)*dtN)*dtN;
        if(sqrt((xR1-xR2)*(xR1-xR2) + (yR1-yR2)*(yR1-yR2))<(R1+R2)*skalaXY)
        {
            TimerRuchu->Enabled = false;
            BtnStartStop->Caption = "START";
            RB2Obiekty->Enabled = true;
            RB3Obiekty->Enabled = true;
            TBM1->Enabled = true;
            TBM2->Enabled = true;
            TBM3->Enabled = true;
            BtnUstawieniaPoczatkowe->Enabled = true;
            break;
        }
        R12 = sqrt((xR1-xR2)*(xR1-xR2) + (yR1-yR2)*(yR1-yR2));
        fAktX1 = G*M2/R12/R12/R12*(xR2-xR1);
        fAktY1 = G*M2/R12/R12/R12*(yR2-yR1);
        fAktX2 = -G*M1/R12/R12/R12*(xR2-xR1);
        fAktY2 = -G*M1/R12/R12/R12*(yR2-yR1);
        vx1 += ((fPoprzX1 + fAktX1)/2)*dtN;
        vy1 -= ((fPoprzY1 + fAktY1)/2)*dtN;
        vx2 += ((fPoprzX2 + fAktX2)/2)*dtN;
        vy2 -= ((fPoprzY2 + fAktY2)/2)*dtN;
    }
    }
    else
    for(int i = 0;i<N;i++)
    {
        xR1 += (vx1 + (fPoprzX1/2)*dtN)*dtN;
        yR1 -= (vy1 + (fPoprzY1/2)*dtN)*dtN;
        xR2 += (vx2 + (fPoprzX2/2)*dtN)*dtN;
        yR2 -= (vy2 + (fPoprzY2/2)*dtN)*dtN;
        xR3 += (vx3 + (fPoprzX3/2)*dtN)*dtN;
        yR3 -= (vy3 + (fPoprzY3/2)*dtN)*dtN;
        if(sqrt((xR1-xR2)*(xR1-xR2) + (yR1-yR2)*(yR1-yR2))<(R1+R2)*skalaXY/2
        || sqrt((xR1-xR3)*(xR1-xR3) + (yR1-yR3)*(yR1-yR3))<(R1+R3)*skalaXY/2
        || sqrt((xR2-xR3)*(xR2-xR3) + (yR2-yR3)*(yR2-yR3))<(R2+R3)*skalaXY/2)
        {
            TimerRuchu->Enabled = false;
            BtnStartStop->Caption = "START";
            RB2Obiekty->Enabled = true;
            RB3Obiekty->Enabled = true;
            TBM1->Enabled = true;
            TBM2->Enabled = true;
            TBM3->Enabled = true;
            BtnUstawieniaPoczatkowe->Enabled = true;
            break;
        }
        R12 = sqrt((xR1-xR2)*(xR1-xR2) + (yR1-yR2)*(yR1-yR2));
        R13 = sqrt((xR1-xR3)*(xR1-xR3) + (yR1-yR3)*(yR1-yR3));
        R23 = sqrt((xR2-xR3)*(xR2-xR3) + (yR2-yR3)*(yR2-yR3));
        fAktX1 = G*M2/R12/R12/R12*(xR2-xR1) + G*M3/R13/R13/R13*(xR3-xR1);
        fAktY1 = G*M2/R12/R12/R12*(yR2-yR1) + G*M3/R13/R13/R13*(yR3-yR1);
        fAktX2 = G*M1/R12/R12/R12*(xR1-xR2) + G*M3/R23/R23/R23*(xR3-xR2);
        fAktY2 = G*M1/R12/R12/R12*(yR1-yR2) + G*M3/R23/R23/R23*(yR3-yR2);
        fAktX3 = G*M1/R13/R13/R13*(xR1-xR3) + G*M2/R23/R23/R23*(xR2-xR3);
        fAktY3 = G*M1/R13/R13/R13*(yR1-yR3) + G*M2/R23/R23/R23*(yR2-yR3);
        vx1 += ((fPoprzX1 + fAktX1)/2)*dtN;
        vy1 -= ((fPoprzY1 + fAktY1)/2)*dtN;
        vx2 += ((fPoprzX2 + fAktX2)/2)*dtN;
        vy2 -= ((fPoprzY2 + fAktY2)/2)*dtN;
        vx3 += ((fPoprzX3 + fAktX3)/2)*dtN;
        vy3 -= ((fPoprzY3 + fAktY3)/2)*dtN;
    }

    xE1 = xR1/skalaXY; yE1=yR1/skalaXY;
    xE2 = xR2/skalaXY; yE2=yR2/skalaXY;
    xE3 = xR3/skalaXY; yE3=yR3/skalaXY;
    tor1.DodajPunkt(TPoint(xE1,yE1));
    tor2.DodajPunkt(TPoint(xE2,yE2));
    if(RB3Obiekty->Checked) tor3.DodajPunkt(TPoint(xE3,yE3));
    if(!TimerRuchu->Enabled)
    {
        tor1.CzyscPunkty();
        tor2.CzyscPunkty();
        tor3.CzyscPunkty();
    }
    Rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TBM1Change(TObject *Sender)
{
    R1 = TBM1->Position/3;
    M1 = R1*R1*R1*gestosc;
    SrodekCiezkosci();
    Rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TBM2Change(TObject *Sender)
{
    R2 = TBM2->Position/3;
    M2 = R2*R2*R2*gestosc;
    SrodekCiezkosci();
    Rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TBM3Change(TObject *Sender)
{
    R3 = TBM3->Position/3;
    M3 = R3*R3*R3*gestosc;
    vx1 = -(vx2*M2 + vx3*M3)/M1; vy1 = -(vy2*M2 + vy3*M3)/M1; v1 = sqrt(vx1*vx1 + vy1*vy1);
    Rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ObszarObrazuMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(TimerRuchu->Enabled)
    {
    przesuwaj2 = false;
    zmieniajV2 = false;
    przesuwaj1 = false;
    przesuwaj3 = false;
    zmieniajV3 = false;
    return;
    }
    else
    if(fabs(X-xE2)<R2 && fabs(Y-yE2)<R2)
    {
        przesuwaj2 = true;
        zmieniajV2 = false;
        przesuwaj1 = false;
        przesuwaj3 = false;
        zmieniajV3 = false;
    }
    else
    if(fabs(X-xE1)<R1 && fabs(Y-yE1)<R1)
    {
        przesuwaj2 = false;
        zmieniajV2 = false;
        przesuwaj1 = true;
        przesuwaj3 = false;
        zmieniajV3 = false;
    }
    else
    if(fabs(X-(xE2+vx2*skalaV))<R2 && fabs(Y-(yE2-vy2*skalaV))<R2 )
    {
        przesuwaj2 = false;
        zmieniajV2 = true;
        przesuwaj1 = false;
        przesuwaj3 = false;
        zmieniajV3 = false;
    }
    else
    if(RB3Obiekty->Checked){
    if(fabs(X-xE3)<R3 && fabs(Y-yE3)<R3)
    {
        przesuwaj2 = false;
        zmieniajV2 = false;
        przesuwaj1 = false;
        przesuwaj3 = true;
        zmieniajV3 = false;
    }
    else
    if(fabs(X-(xE3+vx3*skalaV))<R3 && fabs(Y-(yE3-vy3*skalaV))<R3 )
    {
        przesuwaj2 = false;
        zmieniajV2 = false;
        przesuwaj1 = false;
        przesuwaj3 = false;
        zmieniajV3 = true;
    }
    }
    else
    {
    przesuwaj2 = false;
    zmieniajV2 = false;
    przesuwaj1 = false;
    przesuwaj3 = false;
    zmieniajV3 = false;
    }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ObszarObrazuMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if(przesuwaj2)
    {
        xE2 = X; yE2 = Y;
        xR2 = skalaXY*xE2; yR2 = skalaXY*yE2;
        Rysuj();
    }
    if(zmieniajV2)
    {
        vx2 = (X - xE2)/skalaV;
        vy2 = -(Y - yE2)/skalaV;
        SrodekCiezkosci();
        Rysuj();
    }
    if(przesuwaj3)
    {
        xE3 = X; yE3 = Y;
        xR3 = skalaXY*xE3; yR3 = skalaXY*yE3;
        Rysuj();
    }
    if(zmieniajV3)
    {
        vx3 = (X - xE3)/skalaV;
        vy3 = -(Y - yE3)/skalaV;
        SrodekCiezkosci();
        Rysuj();
    }
    if(przesuwaj1)
    {
        xE1 = X; yE1 = Y;
        xR1 = skalaXY*xE1; yR1 = skalaXY*yE1;
        Rysuj();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ObszarObrazuMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    przesuwaj2 = false;
    zmieniajV2 = false;
    przesuwaj1 = false;
    przesuwaj3 = false;
    zmieniajV3 = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BtnUstawieniaPoczatkoweClick(TObject *Sender)
{
    TBM1->Position = 70;
    TBM2->Position = 50;
    TBM3->Position = 30;
    Poczatek();
}
//---------------------------------------------------------------------------

