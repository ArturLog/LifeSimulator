#ifndef ROSLINA_H
#define ROSLINA_H

#include "Organizm.h"

using namespace std;

class Roslina : public Organizm
{
protected:
	int szansaRozsiania;
	int iloscProbRozsiania;
public:
	Roslina(Swiat& swiat, Punkt xy, const char symbol, string nazwa, const int sila, const int iloscProbRozsiania = 1, const int szansaRozsiania = 1, const int inicjatywa = 0) : iloscProbRozsiania(iloscProbRozsiania), szansaRozsiania(szansaRozsiania), Organizm(swiat, xy, symbol, nazwa, sila, inicjatywa) {};
	
	virtual Organizm* rozmnozenie() = 0;

	void akcja() override;
	bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) override;
	void kolizja(Punkt kolizja) override;
};

#endif