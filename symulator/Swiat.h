#ifndef SWIAT_H
#define SWIAT_H

#include <iostream>
#include <vector>
#include "Punkt.h"
#include "Organizm.h"

class Organizm;

using namespace std;

class Swiat
{
	int x, y;
	int tura;
	int liczba_organizmow;
	Organizm*** organizmy;
	vector <Organizm*> abc;
	vector <string> komentarz;
public:
	Swiat() = default;
	Swiat(int x, int y);

	friend ostream& operator<<(ostream& o, const Swiat& swiat);

	Organizm*& getOrganizm(Punkt xy);
	vector <Organizm*> getAbc();
	vector <string> getKomentarz();
	int getX();
	int getY();

	void wyczyscKomentarze();
	void dodajKomenatrz(string kom);
	void setXY(int x, int y);
	void sortujOrganizmy();
	void dodajOrganizm(Organizm* organizm);
	void wykonajTure(char key);
	void przestawOrganizm(char symbol, Punkt xy, Organizm *organizm);
	bool czyIstniejePozycjaRozmnazanie(Punkt& xy);

	~Swiat();
};

#endif