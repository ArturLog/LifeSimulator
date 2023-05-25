#include "Guarana.h"

void Guarana::kolizja(Punkt kolizja)
{

}

Organizm* Guarana::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Guarana* a = new Guarana(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	return a;
}

bool Guarana::odbicieAtaku(Organizm* napastnik, Punkt kolizja)
{
	napastnik->setSila(napastnik->getSila()+3);
	koment << napastnik->getNazwa() << " zyskal 3 punkty sily. Aktualna sila: " << napastnik->getSila() << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	return false;
}