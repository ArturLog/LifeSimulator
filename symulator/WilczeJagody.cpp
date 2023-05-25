#include "WilczeJagody.h"

void WilczeJagody::kolizja(Punkt kolizja)
{

}

Organizm* WilczeJagody::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	WilczeJagody* a = new WilczeJagody(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	return a;
}

bool WilczeJagody::odbicieAtaku(Organizm* napastnik, Punkt kolizja)
{
	koment << napastnik->getNazwa() << " wlasnie zjadl Wilcze Jagody, smierc nadchodzi ..." << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	return false;
}