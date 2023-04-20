//---------------------------------------------------------------------------

#ifndef WektoryH

class TWektor
{
private:
//wspó³rzêdne rzeczywiste
    double x,y;
    double r, fi;
//wspó³rzêdne ekranowe
    int xE,yE;
//d³ugosc ekranowa
    int rE;
//punkt zaczepienia na ekranie
    int xE0, yE0;
    int grubosc;
    TColor kolor;
    double skala;
    void WyLiczKatFi();                             
public:
    double Dlugosc();
    void UstawWspolrzedneXY(double AxR, double AyR);
    void UstawWspolrzedneRFi(double Ar, double Afi);
    void Rysuj(TCanvas *Kanwa, TColor AKolor=clMin, int x0=-1, int y0=1, double Askala=-1, int AGrubosc=1);
    static void Obrot(double alfa, double &x, double &y);

    TWektor();
    TWektor(double Ax, double Ay, double ASkala=1);
};

#define WektoryH
//---------------------------------------------------------------------------
#endif
