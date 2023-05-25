#ifndef ZWIERZE_H
#define ZWIERZE_H

#include "Organizm.h"

class Zwierze : public Organizm
{
	int zasiegRuchu;
	int szansaRuchu;//0 - 100
public:
	Zwierze(Swiat& swiat, Punkt xy, const char symbol, string nazwa, const int sila, const int inicjatywa, const int zasiegRuchu, const int szansaRuchu) : zasiegRuchu(zasiegRuchu), szansaRuchu(szansaRuchu), Organizm(swiat, xy, symbol, nazwa, sila, inicjatywa) {};
	
	virtual Organizm* rozmnozenie() = 0;
	void kolizja(Punkt kolizja);
	void akcja() override;
	bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) override;
};

#endif