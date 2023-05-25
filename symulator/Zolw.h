#pragma once
#ifndef Zolw_H
#define Zolw_H

#include <iostream>
#include "Zwierze.h"
#include "Swiat.h"

using namespace std;

class Zolw : public Zwierze
{
public:
	Zolw(Swiat& swiat, const char symbol = 'Z', string nazwa = "Zolw", const int sila = 2, const int inicjatywa = 1, const int zasiegRuchu = 1, const int szansaRuchu = 25) : Zwierze(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	Zolw(Swiat& swiat, Punkt xy, const char symbol = 'Z', string nazwa = "Zolw", const int sila = 2, const int inicjatywa = 1, const int zasiegRuchu = 1, const int szansaRuchu = 25) : Zwierze(swiat, xy, symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	
	Organizm* rozmnozenie();
	bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) override;
};

#endif