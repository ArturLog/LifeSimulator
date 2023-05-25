#pragma once
#ifndef Antylopa_H
#define Antylopa_H

#include <iostream>
#include "Zwierze.h"
#include "Swiat.h"

using namespace std;

class Antylopa : public Zwierze
{
public:
	Antylopa(Swiat& swiat, const char symbol = 'A', string nazwa = "Antylopa", const int sila = 4, const int inicjatywa = 4, const int zasiegRuchu = 2, const int szansaRuchu = 100) : Zwierze(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	Antylopa(Swiat& swiat, Punkt xy, const char symbol = 'A', string nazwa = "Antylopa", const int sila = 4, const int inicjatywa = 4, const int zasiegRuchu = 2, const int szansaRuchu = 100) : Zwierze(swiat, xy, symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	
	Organizm* rozmnozenie() override;
	void kolizja(Punkt kolizja) override;
	bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) override;
};

#endif