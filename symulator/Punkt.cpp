#include "Punkt.h"

bool operator==(const Punkt& p1, const Punkt& p2)
{
	return (p1.x == p2.x) && (p1.y == p2.y);
}

Punkt::Punkt()
{
	x = 0;
	y = 0;
}

Punkt::Punkt(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Punkt::getX()
{
	return x;
}

int Punkt::getY()
{
	return y;
}

void Punkt::setX(int x)
{
	this->x = x;
}

void Punkt::setY(int y)
{
	this->y = y;
}