#ifndef OPERATOR_H
#define OPERATOR_H

#include <fstream>
#include <string>
#include <sstream>
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

//ilosc gatunkow organizmow na start
#define OWCA 2
#define WILK 2
#define ANTYLOPA 2
#define ZOLW 2
#define LIS 2

#define TRAWA 1
#define MLECZ 1
#define GUARANA 1
#define WILCZEJAGODY 1
#define BARSZCZSOSNOWSKIEGO 1

class Operator
{
	Swiat swiat;
public:
	void menu();
	void wykonajTure(char key);

	void nowaGra();
	void zapiszGre();
	void wczytajGre();
};

#endif