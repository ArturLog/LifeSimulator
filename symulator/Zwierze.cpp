#include "Zwierze.h"

void Zwierze::akcja()
{
	int szansa = rand() % 100;
	if (szansa <= szansaRuchu)
	{
		int kierunek = rand() % 4;
		switch (kierunek)
		{
		case PRAWO:
			zmienX(xy.getX() + zasiegRuchu);
			break;
		case DOL:
			zmienY(xy.getY() + zasiegRuchu);
			break;
		case LEWO:
			zmienX(xy.getX() - zasiegRuchu);
			break;
		case GORA:
			zmienY(xy.getY() - zasiegRuchu);
			break;
		}
	}
	else
	{
		koment << "Niestety " << getNazwa() << " zostaje w miejscu..." << endl;
		swiat.dodajKomenatrz(koment.str());
		koment.str(" ");
	}
}

void Zwierze::kolizja(Punkt kolizja)
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
				koment << this->getNazwa() << " zjadl " << swiat.getOrganizm(kolizja)->getNazwa() << " na pozycji - X: " << kolizja.getX() << " Y: " << kolizja.getY() << endl;
				swiat.dodajKomenatrz(koment.str());
				koment.str(" ");
				swiat.getOrganizm(kolizja)->setZycie(false);
			}
			swiat.przestawOrganizm(symbol, kolizja, this);
		}
	}
	else
	{
		koment << this->getNazwa() << " przegral potyczke z " << swiat.getOrganizm(kolizja)->getNazwa() << " na pozycji - X: " << getX() << " Y: " << getY() << endl;
		swiat.dodajKomenatrz(koment.str());
		koment.str(" ");
		zyje = false;
	}
}

bool Zwierze::odbicieAtaku(Organizm* napastnik, Punkt kolizja)
{
	return false;
}
