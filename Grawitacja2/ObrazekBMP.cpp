//---------------------------------------------------------------------------


#pragma hdrstop

#include "ObrazekBMP.h"

TObrazekBMP::TObrazekBMP()
{
    BMP = new Graphics::TBitmap();
    kanwa = BMP->Canvas;
    szerokosc = 100;
    wysokosc = 100;
    BMP->Width = szerokosc;
    BMP->Height = wysokosc;
}
//-------------------------------------------------------------------------

TObrazekBMP::~TObrazekBMP()
{
    delete BMP;
}
//--------------------------------------------------------------------------

void TObrazekBMP::Czysc(int Szerokosc, int Wysokosc, TColor kolorTla)
{
    TRect prostokat;

    UstawRozmiar(Szerokosc,Wysokosc);
    prostokat = TRect(0,0,BMP->Width, BMP->Height);
    kanwa->Brush->Color = kolorTla;
    kanwa->FillRect(prostokat);
}
//---------------------------------------------------------------------------

void TObrazekBMP::UstawRozmiar(int Szerokosc, int Wysokosc)
{
    szerokosc = Szerokosc;
    wysokosc = Wysokosc;    
    BMP->Width = szerokosc;
    BMP->Height = wysokosc;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#pragma package(smart_init)
