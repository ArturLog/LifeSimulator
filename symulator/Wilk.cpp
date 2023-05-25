#include "Wilk.h"

Organizm* Wilk::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Wilk* a = new Wilk(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	koment << "Wilki sie rozmnozyly ! Nowy wilk pojawil sie na pozycji - X: " << a->getX() << " Y: " << a->getY() << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	return a;
}