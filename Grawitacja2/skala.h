//---------------------------------------------------------------------------

#ifndef skalaH
#define skalaH

const double epsR=1E-30;

//---------------------------------------------------------------------------
class TSkalowanie
{
private:
    double axE, bxE, ayE, byE;
    double axR, bxR, ayR, byR;
public:
    void Ustaw(double xR0, double yR0, double szerR, double wysR,
        int xE0, int yE0, int szerE, int wysE);

    void PrzeskalujNaEkran(double xR, double yR, int &xE, int &yE);
    void PrzeskalujNaReal(int xE, int yE, double &xR, double &yR);
    TSkalowanie();
};
#endif
