//---------------------------------------------------------------------------


#pragma hdrstop

#include "tory.h"

TTor::TTor()
{
    punkty = new TList;
    kolor = clBlue;
}
//-------------------------------------------------------------

TTor::TTor(TTor &tor)
{
    TPoint *pkt;
    punkty = new TList;

    kolor = tor.kolor;
    for ( int i=0; i<tor.punkty->Count; i++ )
    {
        pkt = (TPoint *)tor.punkty->Items[i];
        punkty->Add((void *)pkt);
    }
}
//-------------------------------------------------------------

TTor::~TTor()
{
    if ( punkty )
    {
        punkty->Clear();
        delete punkty;
    }
}
//-------------------------------------------------------------

void TTor::DodajPunkt(TPoint punkt)
{
    TPoint *pkt;

    pkt = new TPoint(punkt);
    punkty->Add((void *)pkt);
}
//---------------------------------------------------------------

void TTor::CzyscPunkty()
{
    if ( punkty )
    {
        punkty->Clear();
    }
}
//--------------------------------------------------------------
void TTor::UstawKolorToru(TColor Akolor)
{
    if ( Akolor>=clMin && Akolor<=clMax )
        kolor = Akolor;
    else
        kolor = clBlue;
}
//--------------------------------------------------------------

void TTor::Rysuj(TCanvas *kanwa, TColor Akolor)
{
    if ( punkty==NULL )
        return;

    if ( punkty->Count==0 )
        return;

    TColor kolor0 = kanwa->Pen->Color;
    TPoint *pkt;
    int i;

    if ( Akolor!=clMin )
    {
        kanwa->Pen->Color = Akolor;
        kolor = Akolor;
    }
    else
        kanwa->Pen->Color = kolor;
    pkt = (TPoint *)punkty->Items[0];
    kanwa->MoveTo(pkt->x, pkt->y);
    for ( i=1; i<punkty->Count; i++ )
    {
        pkt = (TPoint *)punkty->Items[i];
        kanwa->LineTo(pkt->x, pkt->y);
    }

    kanwa->Pen->Color = kolor0;
}
//---------------------------------------------------------------



TTory::TTory()
{
    tory = new TList;
}
//-------------------------------------------------------------

TTory::~TTory()
{
    if ( tory )
    {
        tory->Clear();
        delete tory;
    }
}
//-------------------------------------------------------------

void TTory::DodajTor(TTor &Ator)
{
    TTor *tor;

    tor = new TTor(Ator);
    tory->Add((void *)tor);
}
//---------------------------------------------------------------

void TTory::CzyscTory()
{
    if ( tory )
    {
        tory->Clear();
    }
}
//--------------------------------------------------------------

void TTory::RysujTory(TCanvas *kanwa, int *NumeryTorow, int RozmiarTablicy)
{
    if ( tory==NULL )
        return;

    if ( tory->Count==0 )
        return;

    TTor *tor;
    if ( NumeryTorow!=NULL )
    {
      for ( int i=0; i<RozmiarTablicy; i++ )
      {
          tor = (TTor *)tory->Items[NumeryTorow[i]];
          tor->Rysuj(kanwa);
      }
    }
    else
    {
      for ( int i=0; i<tory->Count; i++ )
      {
          tor = (TTor *)tory->Items[i];
          tor->Rysuj(kanwa);
      }
    }
}
//---------------------------------------------------------------
#pragma package(smart_init)
