#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>

using namespace std;

class Punkt
{
	int x, y;
public:
	Punkt();
	Punkt(int x, int y);

	friend bool operator==(const Punkt& p1, const Punkt& p2);

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};

#endif