#include "BarszczSosnowskiego.h"

void BarszczSosnowskiego::kolizja(Punkt kolizja)
{

}

void BarszczSosnowskiego::akcja()
{
	Punkt tmp;
	for (int i = (getX() - 1); i <= (getX() + 1); i++)
	{
		for (int j = (getY() - 1); j <= (getY() + 1); j++)
		{
			tmp.setX(i);
			tmp.setY(j);
			if (i >= 0 && j >= 0 && i < swiat.getX() && j < swiat.getY() && swiat.getOrganizm(tmp) != NULL && swiat.getOrganizm(tmp)->czyZyje() && swiat.getOrganizm(tmp)->getNazwa() != "BarszczSosnowskiego")
			{
				koment << "Barszcz zabija wszystko w otoczeniu.. " << swiat.getOrganizm(tmp)->getNazwa() << " umiera." << endl;
				swiat.dodajKomenatrz(koment.str());
				koment.str(" ");
				swiat.getOrganizm(tmp)->setZycie(false);
			}
		}
	}

	int szansa;
	tmp.setX(getX());
	tmp.setY(getY());
	for (int i = 0; i < iloscProbRozsiania; i++)
	{
		if (swiat.czyIstniejePozycjaRozmnazanie(tmp))
		{
			szansa = rand() % 100;
			if (szansa <= szansaRozsiania)
			{
				koment << getNazwa() << " rozsiewa sie wraz z powiewem wiatru !" << endl;
				swiat.dodajKomenatrz(koment.str());
				koment.str(" ");
				swiat.dodajOrganizm(rozmnozenie());
			}
		}
	}
}

Organizm* BarszczSosnowskiego::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	BarszczSosnowskiego* a = new BarszczSosnowskiego(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	return a;
}

bool BarszczSosnowskiego::odbicieAtaku(Organizm* napastnik, Punkt kolizja)
{
	koment << napastnik->getNazwa() << " wlasnie zjadl Barszcz Sosnowskiego, smierc nadchodzi ..." << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	swiat.getOrganizm(napastnik->getPunkt())->setZycie(false);
	return false;
}