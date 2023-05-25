#include "Czlowiek.h"

using namespace std;

void Czlowiek::akcja()
{
	switch (key)
	{
	case 'd':
		zmienX(xy.getX() + 1);
		break;
	case 's':
		zmienY(xy.getY() + 1);
		break;
	case 'a':
		zmienX(xy.getX() - 1);
		break;
	case 'w':
		zmienY(xy.getY() - 1);
		break;
	case 't':
		tarcza.wlaczUmiejetnosc();
		swiat.dodajKomenatrz("Czlowiek wlaczyl umiejetnosc Tarcza Alzura !");
		break;
	}

	if (tarcza.aktywnosc)
	{
		tarcza.iloscRund--;
		if (tarcza.iloscRund == 0)tarcza.wylaczUmiejetnosc();
	}

}

void Czlowiek::kolizja(Punkt kolizja)
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
				koment << "Czlowiek brutalnie zabil " << swiat.getOrganizm(kolizja)->getNazwa() << " na pozycji - X: " << kolizja.getX() << " Y: " << kolizja.getY() << endl;
				swiat.dodajKomenatrz(koment.str());
				koment.str(" ");
				swiat.getOrganizm(kolizja)->setZycie(false);
			}
			swiat.przestawOrganizm(symbol, kolizja, this);
		}
	}
	else
	{
		koment << "Czlowiek posunal sie za daleko i zginal w walce przeciwko " << swiat.getOrganizm(kolizja)->getNazwa() << " na pozycji - X: " << kolizja.getX() << " Y: " << kolizja.getY() << endl;
		swiat.dodajKomenatrz(koment.str());
		koment.str(" ");
		zyje = false;
	}
}

bool Czlowiek::odbicieAtaku(Organizm* napastnik, Punkt kolizja)
{
	if (tarcza.aktywnosc)
	{
		koment << "Czlowiek odstrasza " << napastnik->getNazwa() << " !" << endl;
		swiat.dodajKomenatrz(koment.str());
		koment.str(" ");
		return true;
	}
	return false;
}

Organizm* Czlowiek::rozmnozenie()
{
	Punkt tmp(getX(), getY());
	Czlowiek* a = new Czlowiek(swiat, losujPozycjeRozmnazanie(tmp, swiat));
	koment << "Ludzie zwiekszaja populacje ! Bobas pojawil sie na pozycji - X: " << a->getX() << " Y: " << a->getY() << endl;
	swiat.dodajKomenatrz(koment.str());
	koment.str(" ");
	return a;
}