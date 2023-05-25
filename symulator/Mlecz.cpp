#include "Mlecz.h"

void Mlecz::kolizja(Punkt kolizja)
{

}

Organizm* Mlecz::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Mlecz* a = new Mlecz(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	return a;
}