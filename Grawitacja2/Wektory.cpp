//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Wektory.h"
//---------------------------------------------------------------------------

TWektor::TWektor()
{
    x=1; y=0;
    fi = 0;
    skala = 1;
    r = Dlugosc();
    xE = x*skala;
    yE = y*skala;
    rE = r*skala;
//punkt zaczepienia
    xE0 = yE0 = 0;
    grubosc = 1;
    kolor = clBlue;
}
//--------------------------------------------------------------------------
TWektor::TWektor(double AxR, double AyR, double ASkala)
{
    x = AxR;
    y = AyR;
    WyLiczKatFi();
    skala = ASkala;
    r = Dlugosc();
    xE = x*skala;
    yE = y*skala;
    rE = r*skala;
    xE0 = yE0 = 100;
    grubosc = 1;
    kolor = clBlue;
}
//--------------------------------------------------------------------------

void TWektor::UstawWspolrzedneXY(double AxR, double AyR)
{
    x = AxR;
    y = AyR;
    WyLiczKatFi();
    skala = skala;
    r = Dlugosc();
    xE = x*skala;
    yE = y*skala;
    rE = r*skala;
}
//--------------------------------------------------------------------------

void TWektor::UstawWspolrzedneRFi(double Ar, double Afi)
{
    r = Ar;
    fi = Afi;
    x = r*cos(fi);
    y = r*sin(fi);
    xE = x*skala;
    yE = y*skala;
    rE = r*skala;
}
//--------------------------------------------------------------------------

void TWektor::Obrot(double alfa, double &Ax, double &Ay)
{
    double x1,y1;

    x1 = Ax*cos(alfa) - Ay*sin(alfa);
    y1 = Ax*sin(alfa) + Ay*cos(alfa);

    Ax = x1;
    Ay = y1;
}
//--------------------------------------------------------------------------

void TWektor::Rysuj(TCanvas *Kanwa, TColor AKolor, int x0, int y0, double ASkala, int AGrubosc)
{
    double sk;
    double xs,ys;
    int x1,y1;
    TColor kolor0 = Kanwa->Pen->Color;
    int grubosc0 = Kanwa->Pen->Width;

    if ( ASkala!=-1 )
        sk = ASkala;
    else
        sk = skala;

    if ( r*sk<=2 )
        return;

    if ( x0==-1 )
        x0 = xE0;
    if ( y0==-1 )
        y0 = yE0;
    if ( AKolor==clMin )
        AKolor = kolor;

    xE = x*sk;
    yE = y*sk;
    rE = r*sk;

    Kanwa->Pen->Color = AKolor;
    Kanwa->Pen->Width = AGrubosc;
    Kanwa->MoveTo(x0,y0);
    Kanwa->LineTo(x0+xE,y0-yE);

    xs = -7;
    ys = -4;
    Obrot(-fi,xs,ys);
    x1 = ceil(xs);
    y1 = ceil(ys);
    Kanwa->MoveTo(x0+xE+x1,y0-yE+y1);
    Kanwa->LineTo(x0+xE,y0-yE);
    xs = -7;
    ys = 4;
    Obrot(-fi,xs,ys);
    x1 = ceil(xs);
    y1 = ceil(ys);
    Kanwa->LineTo(x0+xE+x1,y0-yE+y1);

    Kanwa->Pen->Color = kolor0;
    Kanwa->Pen->Width = grubosc0;
}
//--------------------------------------------------------------------------

double TWektor::Dlugosc()
{
    return sqrt(x*x+y*y);
}
//--------------------------------------------------------------------------
void TWektor::WyLiczKatFi()
{
    if ( fabs(x)<1E-38 )
    {
        if ( y>0 )
            fi = M_PI/2;
        else
            fi = 3*M_PI/2;
        return;
    }

    fi = atan(fabs(y)/fabs(x));
    if ( x<0 && y>=0 )
        fi = M_PI - fi;
    else
    if ( x<0 && y<0 )
        fi = M_PI + fi;
    if ( x>0 && y<0 )
        fi = 2*M_PI - fi;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
