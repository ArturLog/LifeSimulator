#include "Roslina.h"

bool Roslina::odbicieAtaku(Organizm* napastnik, Punkt kolizja)
{
	return false;
}

void Roslina::kolizja(Punkt kolizja)
{
}

void Roslina::akcja()
{
	int szansa;
	Punkt tmp(getX(), getY());
	for (int i = 0; i < iloscProbRozsiania; i++)
	{
		if (swiat.czyIstniejePozycjaRozmnazanie(tmp))
		{
			szansa = rand() % 100;
			if (szansa <= szansaRozsiania)
			{
				koment << this->getNazwa() << " rozsiewa sie wraz z powiewem wiatru !" << endl;
				swiat.dodajKomenatrz(koment.str());
				koment.str(" ");
				swiat.dodajOrganizm(this->rozmnozenie());
			}
		}
	}
}