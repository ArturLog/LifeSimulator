#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <vector>
#include <string>
#include "Operator.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Operator op;
	op.menu();
	char x;
	while (true)
	{
		if (_kbhit())//start tury
		{
			system("cls");
			x = _getch();
			if (x == 'z')
			{
				op.zapiszGre();
				exit(0);
			}
			else op.wykonajTure(x);
		}
	}
	
	return 0;
}