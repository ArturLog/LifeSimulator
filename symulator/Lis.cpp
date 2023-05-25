#include "Lis.h"

void Lis::kolizja(Punkt kolizja)
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
				koment << "Chytry lis zjadl " << swiat.getOrganizm(kolizja)->getNazwa() << " na pozycji - X: " << kolizja.getX() << " Y: " << kolizja.getY() << endl;
				swiat.dodajKomenatrz(koment.str());
				koment.str(" ");
				swiat.getOrganizm(kolizja)->setZycie(false);
			}
			swiat.przestawOrganizm(symbol, kolizja, this);
		}
	}
	else if (swiat.czyIstniejePozycjaRozmnazanie(xy))
	{
		koment << "Lis uzywa swojego dobrego wechu by uniknac silniejszego przeciwnika !" << endl;
		swiat.dodajKomenatrz(koment.str());
		koment.str(" ");
		Punkt tmp(this->getX(), this->getY());
		swiat.przestawOrganizm(symbol, losujPozycjeRozmnazanie(tmp, swiat), this);
	}
	else
	{
		koment << "Lis nie mial gdzie uciec przed " << swiat.getOrganizm(kolizja)->getNazwa() << " na pozycji - X: " << getX() << " Y: " << getY() << endl;
		swiat.dodajKomenatrz(koment.str());
		koment.str(" ");
		zyje = false;
	}
}

Organizm* Lis::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Lis* a = new Lis(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	koment << "Pora chowac kury ! Lisy sie rozmnozyly na pozycji - X: " << a->getX() << " Y: " << a->getY() << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	return a;
}