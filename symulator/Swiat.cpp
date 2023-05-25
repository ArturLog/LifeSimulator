#include "Swiat.h"

ostream& operator<<(ostream& o, const Swiat& swiat)
{
	o << " ";
	o << endl;
	for (int i = 0; i < swiat.y; i++)
	{
		if (i < 10)o << 0;
		o << i;
		for (int j = 0; j < swiat.x; j++)
		{
			if (swiat.organizmy[i][j] == NULL) o << ".";
			else o << swiat.organizmy[i][j]->getSymbol();
		}
		o << endl;
	}

	for (size_t i = 0; i < swiat.komentarz.size(); i++) o << swiat.komentarz[i] << endl;
	return o;
}

Swiat::Swiat(int x, int y)
{
	tura = 0;
	liczba_organizmow = 0;
	this->x = x;
	this->y = y;
	organizmy = new Organizm * *[y];
	for (int i = 0; i < y; i++)
	{
		organizmy[i] = new Organizm * [x];
	}

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
		{
			organizmy[i][j] = NULL;
		}
}

void Swiat::setXY(int x, int y)
{
	tura = 0;
	liczba_organizmow = 0;
	this->x = x;
	this->y = y;
	organizmy = new Organizm * *[y];
	for (int i = 0; i < y; i++)
	{
		organizmy[i] = new Organizm * [x];
	}

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
		{
			organizmy[i][j] = NULL;
		}
}

int Swiat::getX()
{
	return x;
}

int Swiat::getY()
{
	return y;
}

Organizm*& Swiat::getOrganizm(Punkt xy)
{
	return organizmy[xy.getY()][xy.getX()];
}

vector <Organizm*> Swiat::getAbc()
{
	return abc;
}

vector <string> Swiat::getKomentarz()
{
	return komentarz;
}

void Swiat::dodajKomenatrz(string kom)
{
	komentarz.push_back(kom);
}

void Swiat::wyczyscKomentarze()
{
	komentarz.clear();
}

void Swiat::wykonajTure(char key)
{
	wyczyscKomentarze();
	for (int i = 0; i < liczba_organizmow; i++)
	{
		if (abc[i]->czyZyje())
		{
			if (abc[i]->getNazwa() == "Czlowiek")abc[i]->setKey(key);
			abc[i]->akcja();
		}
	}
	for (int i = 0; i < abc.size(); i++)
	{
		if (!abc[i]->czyZyje())
		{
			if(abc[i] == organizmy[abc[i]->getY()][abc[i]->getX()])organizmy[abc[i]->getY()][abc[i]->getX()] = NULL;
			delete abc[i];
			abc[i] = NULL;
			abc.erase(abc.begin() + i);
			i--;
		}
	}
	sortujOrganizmy();
	liczba_organizmow = abc.size();
	tura++;
}

void Swiat::sortujOrganizmy()
{
	Organizm* tmp;
	for (size_t j = 0; j < abc.size(); j++)
	{
		for (size_t i = 0; i < abc.size() - 1; i++)
		{
			if (abc[i]->getInicjatywa() < abc[i+1]->getInicjatywa())
			{
				tmp = abc[i];
				abc[i] = abc[i + 1];
				abc[i + 1] = tmp;
			}
		}
	}
}

void Swiat::dodajOrganizm(Organizm* organizm)
{
	if (tura == 0)liczba_organizmow++;
	abc.push_back(organizm);
	organizmy[organizm->getY()][organizm->getX()] = organizm;
}

void Swiat::przestawOrganizm(char symbol, Punkt ab, Organizm *organizm)
{
	organizmy[organizm->getY()][organizm->getX()] = NULL;
	organizm->setX(ab.getX());
	organizm->setY(ab.getY());
	organizmy[organizm->getY()][organizm->getX()] = organizm;
	
}

bool Swiat::czyIstniejePozycjaRozmnazanie(Punkt& xy)
{
	Punkt a;
	for (int i = xy.getX() - 1; i <= xy.getX() + 1; i++)
	{
		for (int j = xy.getY() - 1; j <= xy.getY() + 1; j++)
		{
			a.setX(i);
			a.setY(j);
			if(i >= 0 && j >=0 && i < getX() && j < getY() && getOrganizm(a) == NULL) return true;
		}
	}
	return false;
}

Swiat::~Swiat()
{
	for (int i = 0; i < y; i++)		delete[] organizmy[i];
	for (size_t i = 0; i < abc.size(); i++) delete abc[i];
	delete[] organizmy;
}