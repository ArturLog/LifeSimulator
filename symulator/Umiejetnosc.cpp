#include "Umiejetnosc.h"

Umiejetnosc::Umiejetnosc()
{
	aktywnosc = false;
	iloscRund = 5;
}

void Umiejetnosc::wlaczUmiejetnosc()
{
	aktywnosc = true;
	iloscRund = 5;
}

void Umiejetnosc::wylaczUmiejetnosc()
{
	aktywnosc = false;
}