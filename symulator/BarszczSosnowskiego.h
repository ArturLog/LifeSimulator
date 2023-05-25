#pragma once
#ifndef BarszczSosnowskiego_H
#define BarszczSosnowskiego_H

#include <iostream>
#include "Roslina.h"
#include "Swiat.h"

using namespace std;

class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(Swiat& swiat, const char symbol = '^', string nazwa = "BarszczSosnowskiego", const int sila = 10) : Roslina(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila) {};
	BarszczSosnowskiego(Swiat& swiat, Punkt xy, const char symbol = '^', string nazwa = "BarszczSosnowskiego", const int sila = 10) : Roslina(swiat, xy, symbol, nazwa, sila) {};
	
	Organizm* rozmnozenie();

	void kolizja(Punkt kolizja) override;
	void akcja() override;
	bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) override;
};

#endif