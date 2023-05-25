#include "Organizm.h"

void Organizm::setX(int x)
{
	xy.setX(x);
}

void Organizm::setY(int y)
{
	xy.setY(y);
}
void Organizm::setSila(int a)
{
	sila = a;
}
void Organizm::setZycie(bool a)
{
	zyje = a;
}

void Organizm::setKey(char key)
{
	this->key = key;
}

char Organizm::getSymbol() const
{
	return symbol;
}

Punkt Organizm::getPunkt()
{
	return xy;
}

int Organizm::getX()
{
	return xy.getX();
}

int Organizm::getY()
{
	return xy.getY();
}

int Organizm::getSila() const
{
	return sila;
}

string Organizm::getNazwa() const
{
	return nazwa;
}

int Organizm::getInicjatywa() const
{
	return inicjatywa;
}

bool Organizm::czyZyje() const
{
	return zyje;
}


Punkt Organizm::losujWolnaPozycje(Swiat& swiat)
{
	int x, y;
	Punkt a;
	while (true)
	{
		x = rand() % (swiat.getX() - 1);
		y = rand() % (swiat.getY() - 1);
		a.setX(x);
		a.setY(y);
		if (swiat.getOrganizm(a) == NULL) return a;
	}
}
void Organizm::zmienX(int x)
{
	if (x >= 0 && x < swiat.getX())
	{
		Punkt tmp(x, xy.getY());
		
		if (swiat.getOrganizm(tmp) == NULL || !(swiat.getOrganizm(tmp)->czyZyje()))
		{
			swiat.przestawOrganizm(this->getSymbol(), tmp, this);
		}
		else kolizja(tmp);
		
	}
}
void Organizm::zmienY(int y)
{
	if (y >= 0 && y < swiat.getY())
	{
		Punkt tmp(xy.getX(), y);
		
		if (swiat.getOrganizm(tmp) == NULL)
		{
			swiat.przestawOrganizm(this->getSymbol(), tmp, this);
		}
		else kolizja(tmp);
	}
}


Punkt Organizm::losujPozycjeRozmnazanie(Punkt& xy, Swiat& swiat)
{
	int x, y;
	Punkt a;
	while (true)
	{
		x = ((rand() % 3) + (xy.getX() - 1));
		y = ((rand() % 3) + (xy.getY() - 1));
		a.setX(x);
		a.setY(y);
		if (x < swiat.getX() && x >= 0 && y >= 0 && y < swiat.getY() && swiat.getOrganizm(a) == NULL) return a;
	}
}
