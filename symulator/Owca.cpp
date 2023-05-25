#include "Owca.h"

Organizm* Owca::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Owca* a = new Owca(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	koment << "Owce sie rozmnozyly ! Nowa owieczka pojawila sie na pozycji - X: " << a->getX() << " Y: " << a->getY() << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	return a;
}