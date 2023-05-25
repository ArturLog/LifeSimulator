#pragma once
#ifndef WilczeJagody_H
#define WilczeJagody_H

#include <iostream>
#include "Roslina.h"
#include "Swiat.h"

using namespace std;

class WilczeJagody : public Roslina
{
public:
	WilczeJagody(Swiat& swiat, const char symbol = '&', string nazwa = "WilczeJagody", const int sila = 99) : Roslina(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila) {};
	WilczeJagody(Swiat& swiat, Punkt xy, const char symbol = '&', string nazwa = "WilczeJagody", const int sila = 99) : Roslina(swiat, xy, symbol, nazwa, sila) {};
	
	Organizm* rozmnozenie() override;

	void kolizja(Punkt kolizja) override;
	bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) override;
};

#endif