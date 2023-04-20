//---------------------------------------------------------------------------


#pragma hdrstop
#include <vcl.h>
#include "skala.h"

//---------------------------------------------------------------------------
TSkalowanie::TSkalowanie()
{
    axE=0; bxE=0; ayE=0; byE=0;
    axR=0; bxR=0; ayR=0; byR=0;
}
//---------------------------------------------------------------------------

void TSkalowanie::Ustaw(double xR0, double yR0, double szerR, double wysR,
        int xE0, int yE0, int szerE, int wysE)
{
    if ( szerE<1 || wysE<1 )
    {
        Application->MessageBoxA("Nieprawid³owe rozmiary ekranowe", "Uwaga", MB_OK|MB_ICONEXCLAMATION);
        return;
    }

    if ( szerR<epsR || wysR<epsR )
    {
        Application->MessageBoxA("Nieprawid³owe rozmiary rzeczywiste", "Uwaga", MB_OK|MB_ICONEXCLAMATION);
        return;
    }

    axE = szerE/szerR;
    bxE = xE0 - axE*xR0;

    ayE = -wysE/wysR;
    byE = yE0 + wysE - ayE*yR0;

    axR = 1.0/axE;
    bxR = -bxE/axE;
    ayR = 1.0/ayE;
    byR = -byE/ayE;
}
//---------------------------------------------------------------------------

void TSkalowanie::PrzeskalujNaEkran(double xR, double yR, int &xE, int &yE)
{
    xE = axE*xR + bxE;
    yE = ayE*yR + byE;
}
//---------------------------------------------------------------------------

void TSkalowanie::PrzeskalujNaReal(int xE, int yE, double &xR, double &yR)
{
    xR = axR*xE + bxR;
    yR = ayR*yE + byR;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
