#ifndef OWCA_H
#define OWCA_H

#include <iostream>
#include "Zwierze.h"
#include "Swiat.h"

using namespace std;

class Owca : public Zwierze
{
public:
	Owca(Swiat& swiat, const char symbol = 'O', string nazwa = "Owca", const int sila = 4, const int inicjatywa = 5, const int zasiegRuchu = 1, const int szansaRuchu = 100) : Zwierze(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	Owca(Swiat& swiat, Punkt xy, const char symbol = 'O', string nazwa = "Owca", const int sila = 4, const int inicjatywa = 5, const int zasiegRuchu = 1, const int szansaRuchu = 100) : Zwierze(swiat, xy, symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	
	Organizm* rozmnozenie() override;
};

#endif