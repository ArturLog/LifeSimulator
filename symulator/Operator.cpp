#include "Operator.h"

void Operator::menu()
{
	int x;

	cout << "-----SYMULATOR ZYCIA 2022 - ARTUR SPIEWAK 18866-----" << endl;
	cout << "--               1. Nowa gra                      --" << endl;
	cout << "--               2. Wczytaj gre                   --" << endl;
	cout << "----------------------------------------------------" << endl;

	cin >> x;

	if (x == 1) nowaGra();
	else if (x == 2) wczytajGre();
}

void Operator::zapiszGre()
{
	fstream plik;
	plik.open("save.txt", ios::out);
	if (plik.good())
	{
		cout << "Zapisuje stan gry..." << endl;
		plik << swiat.getX() << " " << swiat.getY() << endl;
		for (size_t i = 0; i < swiat.getAbc().size(); i++)
		{
			plik << swiat.getAbc()[i]->getNazwa() << " " << swiat.getAbc()[i]->getX() << " " << swiat.getAbc()[i]->getY() << endl;
		}
		cout << "Stan gry zapisany !" << endl;
		plik.close();
	}
	else
	{
		cout << "Brak pliku do zapisu !";
	}
}

void Operator::wczytajGre()
{
	fstream plik;
	plik.open("save.txt", ios::in);
	if (plik.good())
	{
		cout << "Wczytuje stan gry..." << endl;
		string nazwa;
		int x, y;
		Punkt tmp;
		plik >> x >> y;
		swiat.setXY(x, y);
		while (!plik.eof())
		{
			plik >> nazwa >> x >> y;
			tmp.setX(x);
			tmp.setY(y);
			if (nazwa == "Antylopa")swiat.dodajOrganizm(new Antylopa(swiat,tmp));
			else if (nazwa == "BarszczSosnowskiego")swiat.dodajOrganizm(new BarszczSosnowskiego(swiat,tmp));
			else if (nazwa == "Czlowiek")swiat.dodajOrganizm(new Czlowiek(swiat,tmp));
			else if (nazwa == "Guarana")swiat.dodajOrganizm(new Guarana(swiat,tmp));
			else if (nazwa == "Lis")swiat.dodajOrganizm(new Lis(swiat, tmp));
			else if (nazwa == "Mlecz")swiat.dodajOrganizm(new Mlecz(swiat, tmp));
			else if (nazwa == "Owca")swiat.dodajOrganizm(new Owca(swiat, tmp));
			else if(nazwa == "Trawa")swiat.dodajOrganizm(new Trawa(swiat, tmp));
			else if (nazwa == "WilczeJagody")swiat.dodajOrganizm(new WilczeJagody(swiat, tmp));
			else if (nazwa == "Wilk")swiat.dodajOrganizm(new Wilk(swiat, tmp));
			else if (nazwa == "Zolw")swiat.dodajOrganizm(new Zolw(swiat, tmp));
		}
		cout << "Pomyslnie wczytano gre !" << endl;
		plik.close();
		cout << swiat;
	}
	else
	{
		cout << "Brak zapisu do wczytania !";
		Swiat swiat(20, 20);
	}
}

void Operator::wykonajTure(char key)
{
	swiat.wykonajTure(key);
	cout << swiat;
}

void Operator::nowaGra()
{
	int a, b;

	cout << "Podaj wielkosc planszy : " << endl << "X: "; cin >> a; cout << "Y : "; cin >> b;
	swiat.setXY(a, b);

	swiat.dodajOrganizm(new Czlowiek(swiat));
	for (int i = 0; i < WILK; i++) swiat.dodajOrganizm(new Wilk(swiat));
	for (int i = 0; i < ANTYLOPA; i++) swiat.dodajOrganizm(new Antylopa(swiat));
	for (int i = 0; i < LIS; i++) swiat.dodajOrganizm(new Lis(swiat));
	for (int i = 0; i < OWCA; i++) swiat.dodajOrganizm(new Owca(swiat));
	for (int i = 0; i < ZOLW; i++) swiat.dodajOrganizm(new Zolw(swiat));
	for (int i = 0; i < TRAWA; i++) swiat.dodajOrganizm(new Trawa(swiat));
	for (int i = 0; i < MLECZ; i++) swiat.dodajOrganizm(new Mlecz(swiat));
	for (int i = 0; i < GUARANA; i++) swiat.dodajOrganizm(new Guarana(swiat));
	for (int i = 0; i < WILCZEJAGODY; i++) swiat.dodajOrganizm(new WilczeJagody(swiat));
	for (int i = 0; i < BARSZCZSOSNOWSKIEGO; i++) swiat.dodajOrganizm(new BarszczSosnowskiego(swiat));

	swiat.sortujOrganizmy();

	system("cls");
	cout << swiat;
}