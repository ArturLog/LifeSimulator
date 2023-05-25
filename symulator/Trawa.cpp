#include "Trawa.h"

void Trawa::kolizja(Punkt kolizja)
{

}

Organizm* Trawa::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Trawa* a = new Trawa(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	return a;
}