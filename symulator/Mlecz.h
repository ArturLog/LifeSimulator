#pragma once
#ifndef Mlecz_H
#define Mlecz_H

#include <iostream>
#include "Roslina.h"
#include "Swiat.h"

using namespace std;

class Mlecz : public Roslina
{
public:
	Mlecz(Swiat& swiat, const char symbol = '%', string nazwa = "Mlecz", const int sila = 0, const int iloscProbRozsiania = 3) : Roslina(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila) {};
	Mlecz(Swiat& swiat, Punkt xy, const char symbol = '%', string nazwa = "Mlecz", const int sila = 0, const int iloscProbRozsiania = 3) : Roslina(swiat, xy, symbol, nazwa, sila) {};
	
	Organizm* rozmnozenie() override;

	void kolizja(Punkt kolizja) override;
};

#endif