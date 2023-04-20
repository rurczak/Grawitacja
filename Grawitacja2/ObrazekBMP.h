//---------------------------------------------------------------------------

#ifndef ObrazekBMPH
#define ObrazekBMPH

#include <vcl.h>

class TObrazekBMP
{
public:
    Graphics::TBitmap *BMP;
    TCanvas *kanwa;
    int szerokosc, wysokosc;

    void Czysc(int Szerokosc, int Wysokosc, TColor kolorTla=clWhite);
    void UstawRozmiar(int Szerokosc, int Wysokosc);

    TObrazekBMP();
    ~TObrazekBMP();
};
//---------------------------------------------------------------------------
#endif
