#include "Antylopa.h"

void Antylopa::kolizja(Punkt kolizja)
{
	if (this->getSymbol() == swiat.getOrganizm(kolizja)->getSymbol())
	{
		if (swiat.czyIstniejePozycjaRozmnazanie(kolizja))
		{
			swiat.dodajOrganizm(rozmnozenie());
		}
		return;
	}
	else if (this->sila >= swiat.getOrganizm(kolizja)->getSila())
	{
		if (!swiat.getOrganizm(kolizja)->odbicieAtaku(this, kolizja))
		{
			if (swiat.getOrganizm(kolizja)->czyZyje())
			{
				koment << "Antylopa pokonala " << swiat.getOrganizm(kolizja)->getNazwa() << " na pozycji - X: " << kolizja.getX() << " Y: " << kolizja.getY() << endl;
				swiat.dodajKomenatrz(koment.str());
				koment.str(" ");
				swiat.getOrganizm(kolizja)->setZycie(false);
			}
			swiat.przestawOrganizm(symbol, kolizja, this);
		}
	}
	else
	{
		if (!odbicieAtaku(swiat.getOrganizm(kolizja), kolizja))
		{
			koment << "Niestety tym razem Antylopa nie uciekla przed " << swiat.getOrganizm(kolizja)->getNazwa() << " na pozycji - X: " << getX() << " Y: " << getY() << endl;
			swiat.dodajKomenatrz(koment.str());
			koment.str(" ");
			zyje = false;
		}
	}
}

bool Antylopa::odbicieAtaku(Organizm* napastnik, Punkt kolizja)
{
	int szansa = rand() % 100;
	if (szansa < 50)
	{
		koment << "Antylopa ucieka przed atakiem " << napastnik->getNazwa() << " !" << endl;
		swiat.dodajKomenatrz(koment.str());
		koment.str(" ");
		Punkt tmp(getX(), getY());
		swiat.przestawOrganizm(symbol, losujPozycjeRozmnazanie(tmp, swiat), this);
		swiat.przestawOrganizm(symbol, kolizja, napastnik);
		return true;
	}
	else return false;
}

Organizm* Antylopa::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Antylopa* a = new Antylopa(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	koment << "Antylopy sie rozmnozyly na pozycji - X: " << a->getX() << " Y: " << a->getY() << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	return a;
}