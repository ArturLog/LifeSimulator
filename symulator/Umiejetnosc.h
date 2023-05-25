#pragma once
#ifndef UMIEJETNOSC_H
#define UMIEJETNOSC_H

struct Umiejetnosc
{
	bool aktywnosc;
	int iloscRund;
public:
	Umiejetnosc();

	void wlaczUmiejetnosc();
	void wylaczUmiejetnosc();
};

#endif