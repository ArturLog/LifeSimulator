#ifndef ORGANIZM_H
#define ORGANIZM_H

#include <iostream>
#include <sstream>
#include <string>
#include "Punkt.h"
#include "Swiat.h"

class Swiat;

enum { LEWO, PRAWO, GORA, DOL }; // ulatwia czytelnosc funkcji poruszania

class Organizm
{
protected:
	int sila;
	int inicjatywa;
	char symbol;
	char key;
	string nazwa;
	bool zyje;
	Punkt xy;
	Swiat& swiat;
	ostringstream koment;
public:
	Organizm(Swiat& swiat, Punkt xy, const char symbol, string nazwa, const int sila, const int inicjatywa) : swiat(swiat), xy(xy), symbol(symbol), nazwa(nazwa), zyje(true), sila(sila), inicjatywa(inicjatywa), koment(" "), key('a') {}
	
	char getSymbol() const;
	string getNazwa() const;
	bool czyZyje() const;
	int getSila() const;
	int getInicjatywa() const;
	Punkt getPunkt();
	int getX();
	int getY();

	void setSila(int a);
	void setZycie(bool a);
	void zmienX(int x);
	void zmienY(int y);
	void setX(int x);
	void setY(int y);
	void setKey(char key);

	virtual Organizm* rozmnozenie() = 0;
	virtual void akcja() = 0;
	virtual void kolizja(Punkt kolizja) = 0;
	virtual bool odbicieAtaku(Organizm* napastnik, Punkt kolizja) = 0;

	Punkt losujWolnaPozycje(Swiat& swiat);
	Punkt losujPozycjeRozmnazanie(Punkt& xy, Swiat& swiat);
};

#endif