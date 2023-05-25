#include "Zolw.h"

bool Zolw::odbicieAtaku(Organizm* napastnik, Punkt kolizja)
{
	if (napastnik->getSila() < 5)
	{
		koment << "Zolw odbija atak ! " << napastnik->getNazwa() << " jest w szoku !" << endl;
		swiat.dodajKomenatrz(koment.str());
		koment.str(" ");
		return true;
	}
	else return false;
}

Organizm* Zolw::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Zolw* a = new Zolw(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	koment << "Pojawila sie kolejna skorupa na mapie na pozycji - X: " << a->getX() << " Y: " << a->getY() << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	return a;
}