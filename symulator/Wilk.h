#ifndef WILK_H
#define WILK_H

#include <iostream>
#include "Zwierze.h"
#include "Swiat.h"

using namespace std;

class Wilk : public Zwierze
{
public:
	Wilk(Swiat& swiat, const char symbol = 'W', string nazwa="Wilk", const int sila = 9, const int inicjatywa = 5, const int zasiegRuchu = 1, const int szansaRuchu = 100) : Zwierze(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	Wilk(Swiat& swiat, Punkt xy, const char symbol = 'W', string nazwa = "Wilk", const int sila = 9, const int inicjatywa = 5, const int zasiegRuchu = 1, const int szansaRuchu = 100) : Zwierze(swiat, xy, symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	
	Organizm* rozmnozenie();
};

#endif