#pragma once
#ifndef Guarana_H
#define Guarana_H

#include <iostream>
#include "Roslina.h"
#include "Swiat.h"

using namespace std;

class Guarana : public Roslina
{
public:
	Guarana(Swiat& swiat, const char symbol = '$', string nazwa = "Guarana", const int sila = 0) : Roslina(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila) {};
	Guarana(Swiat& swiat, Punkt xy, const char symbol = '$', string nazwa = "Guarana", const int sila = 0) : Roslina(swiat, xy, symbol, nazwa, sila) {};
	
	Organizm* rozmnozenie() override;

	void kolizja(Punkt kolizja) override;
	bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) override;
};

#endif