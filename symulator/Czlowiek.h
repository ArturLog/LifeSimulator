#ifndef CZLOWIEK_H
#define CZLOWIEK_H

#include <iostream>
#include "Zwierze.h"
#include "Swiat.h"
#include "Umiejetnosc.h"

using namespace std;

class Czlowiek : public Zwierze
{
	Umiejetnosc tarcza;
public:
	Czlowiek(Swiat& swiat, Umiejetnosc tarcza = Umiejetnosc(), const char symbol = '@', string nazwa="Czlowiek", const int sila = 12, const int inicjatywa = 4, const int zasiegRuchu = 1, const int szansaRuchu = 100) : tarcza(tarcza), Zwierze(swiat, losujWolnaPozycje(swiat), symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};
	Czlowiek(Swiat& swiat, Punkt xy, Umiejetnosc tarcza = Umiejetnosc(), const char symbol = '@', string nazwa = "Czlowiek", const int sila = 12, const int inicjatywa = 4, const int zasiegRuchu = 1, const int szansaRuchu = 100) : tarcza(tarcza), Zwierze(swiat, xy, symbol, nazwa, sila, inicjatywa, zasiegRuchu, szansaRuchu) {};

	Organizm* rozmnozenie() override;
	void akcja() override;
	void kolizja(Punkt kolizja) override;
	bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) override;
};

#endif