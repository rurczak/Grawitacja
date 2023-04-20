//---------------------------------------------------------------------------

#ifndef toryH
#define toryH

#include <vcl.h>

//enum TColor {clMin=-0x7fffffff-1, clMax=0x7fffffff};
class TTor
{      
    TColor kolor;
public:
    TList *punkty;
    void UstawKolorToru(TColor Akolor);
    void DodajPunkt(TPoint punkt);
    void CzyscPunkty();
    void Rysuj(TCanvas *kanwa, TColor kolor=clMin);

    TTor();
    TTor(TTor &tor);
    ~TTor();
};

class TTory
{
    TList *tory;
public:
    void DodajTor(TTor &Ator);
    void CzyscTory();
    void RysujTory(TCanvas *kanwa, int *NumeryTorow=NULL, int RozmiarTablicy=0);

    TTory();
    ~TTory();
};

//---------------------------------------------------------------------------
#endif
