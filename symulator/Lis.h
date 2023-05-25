#pragma once
#ifndef LIS_H
#define LIS_H

#include <iostream>
#include "Zwierze.h"
#include "Swiat.h"

using namespace std;

class Lis : public Zwierze
{
public:
	Lis(Swiat& swiat, const char symbol = 'L', string nazwa = "Lis", const int sila = 3, const int inicjatywa = 7, const int zasiegRuchu = 1, const int szansaRuchu = 100) : Zwierze(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	Lis(Swiat& swiat, Punkt xy, const char symbol = 'L', string nazwa = "Lis", const int sila = 3, const int inicjatywa = 7, const int zasiegRuchu = 1, const int szansaRuchu = 100) : Zwierze(swiat, xy, symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	
	Organizm* rozmnozenie() override;
	void kolizja(Punkt kolizja) override;
};

#endif