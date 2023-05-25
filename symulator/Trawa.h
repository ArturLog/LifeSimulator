#pragma once
#ifndef Trawa_H
#define Trawa_H

#include <iostream>
#include "Roslina.h"
#include "Swiat.h"

using namespace std;

class Trawa : public Roslina
{
public:
	Trawa(Swiat& swiat, const char symbol = '#', string nazwa = "Trawa", const int sila = 0 ) : Roslina(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila) {};
	Trawa(Swiat& swiat, Punkt xy, const char symbol = '#', string nazwa = "Trawa", const int sila = 0 ) : Roslina(swiat, xy, symbol, nazwa, sila) {};
	
	Organizm* rozmnozenie() override;
	
	void kolizja(Punkt kolizja) override;
};

#endif