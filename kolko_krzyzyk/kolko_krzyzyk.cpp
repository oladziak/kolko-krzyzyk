
#include <iostream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void plansza(char t[])
{
	cout << "\t\t\tKOLKO KRZYZYK\n";
	cout << "   |   |   \n";
	cout << " " << t[0] << " | " << t[1] << " | " << t[2] << " \n";
	cout << "   |   |   \n";
	cout << "---+---+---\n";
	cout << "   |   |   \n";
	cout << " " << t[3] << " | " << t[4] << " | " << t[5] << " \n";
	cout << "   |   |   \n";
	cout << "---+---+---\n";
	cout << "   |   |   \n";
	cout << " " << t[6] << " | " << t[7] << " | " << t[8] << " \n";
	cout << "   |   |   \n";
}
bool wygrana(char t[], char znak)
{
	for (int i = 0; i < 9; i += 3)
	{
		if (t[i] == znak && t[i + 1] == znak && t[i + 2] == znak)
			return true;
	}
	for (int i = 0; i < 3; i++)
	{
		if (t[i] == znak && t[i + 3] == znak && t[i + 6] == znak)
			return true;
	}
	if (t[0] == znak && t[4] == znak && t[8] == znak)
		return true;
	if (t[2] == znak && t[4] == znak && t[6] == znak)
		return true;
	else
		return false;
}
bool remis(char t[])
{
	for (int i = 0; i < 9; i++)
	{
		if (t[i] == ' ')
			return false;
	}
	return true;
}
void ruch_gracza(char t[], char znak_g)
{
	int n;
start:
	cout << "Podaj numer pola w ktorym postawic znak: ";
	do {
		cin >> n;

	} while (n < 1 || n>9);
	if (t[n - 1] == ' ')
	{
		t[n - 1] = znak_g;
	}
	else
	{
		cout << "Podales zajete pole, sprobuj ponoownie.\n";
		goto start;
	}
}
void ruch_komp(char t[], char znak, char znak_g)
{
	for (int i = 0; i < 9; i += 3)
	{
		if ((t[i] == znak_g && t[i + 1] == znak_g) || (t[i] == znak_g && t[i + 2] == znak_g) || (t[i + 1] == znak_g && t[i + 2] == znak_g))
		{
			if (t[i] == ' ') {
				t[i] = znak;
				return;
			}
			if (t[i + 1] == ' ') {
				t[i + 1] = znak;
				return;
			}
			if (t[i + 2] == ' ') {
				t[i + 2] = znak;
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if ((t[i] == znak_g && t[i + 3] == znak_g) || (t[i] == znak_g && t[i + 6] == znak_g) || (t[i + 3] == znak_g && t[i + 6] == znak_g))
		{
			if (t[i] == ' ') {
				t[i] = znak;
				return;
			}
			if (t[i + 3] == ' ') {
				t[i + 3] = znak;
				return;
			}
			if (t[i + 6] == ' ') {
				t[i + 6] = znak;
				return;
			}
		}
	}
	if ((t[0] == znak_g && t[4] == znak_g) || (t[0] == znak_g && t[8] == znak_g) || (t[4] == znak_g && t[8] == znak_g))
	{
		for (int j = 0; j < 9; j += 4)
		{
			if (t[j] == ' ') {
				t[j] = znak;
				break;
			}
		}
		return;
	}
	if ((t[2] == znak_g && t[4] == znak_g) || (t[2] == znak_g && t[6] == znak_g) || (t[4] == znak_g && t[6] == znak_g))
	{
		for (int i = 2; i < 7; i += 2)
		{
			if (t[i] == ' ') {
				t[i] = znak;
				break;
			}
		}
		return;
	}
	if (t[4] == ' ')
	{
		t[4] = znak;
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		if (t[i] == ' ')
		{
			t[i] = znak;
			return;
		}
	}
}
int main()
{
	char znak_g, znak, b, wybor; //znak_g- znak gracza; znak- znak komputera; b-zmienna dziêki której ustawiamy kto rozpoczyna grê ; wybor- zmienna potrzebna do decyzji o ponownej turze
	char pl[9];
	do {
		for (int i = 0; i < 9; i++)
		{
			pl[i] = ' ';
		}
		system("cls");
		cout << "\t\t\tKOLKO KRZYZYK\n";
		do
		{
			cout << "\n Prosze wybrac znak : O lub X\n";
			cin >> znak_g;
			switch (znak_g)
			{
			case 'O':
			case 'o':
				cout << "Gracz -> O\n" << "Komputer -> X\n";
				znak_g = 'O';
				znak = 'X';
				break;
			case 'X':
			case 'x':
				cout << "Gracz -> X\n" << "Komputer -> O\n";
				znak_g = 'X';
				znak = 'O';
				break;
			default:
				cout << "Wprowadzono nieprawidlowy znak, sprobuj ponownie." << endl;
				znak_g = 'a';
				break;
			}
		} while (znak_g == 'a');
		do
		{
			cout << "Kto rozpoczyna gre?(G/K)\n";
			cin >> b;
			switch (b)
			{
			case 'g':
			case 'G':
				cout << "Gre rozpoczyna gracz\n";
				b = 'G';
				break;
			case 'k':
			case 'K':
				cout << "Gre rozpoczyna komputer\n";
				b = 'K';
				break;
			default:
				cout << "Wprowadzono nieprawidlowy znak, sprobuj ponownie\n";
				b = 'b';
				break;
			}
		} while (b == 'b');
		system("cls");
		plansza(pl);
		if (b == 'G')
		{
			for (int i = 0; i < 5; i++)
			{
				ruch_gracza(pl, znak_g);
				system("cls");
				plansza(pl);
				if (wygrana(pl, znak) == true)
				{
					cout << "Komputer wygral!" << endl;
					break;
				}
				if (wygrana(pl, znak_g) == true)
				{
					cout << "Gracz wygral!" << endl;
					break;
				}
				if (remis(pl) == true)
				{
					cout << "Remis!" << endl;
					break;
				}
				ruch_komp(pl, znak, znak_g);
				system("cls");
				plansza(pl);
				if (wygrana(pl, znak) == true)
				{
					cout << "Komputer wygral!" << endl;
					break;
				}
				if (wygrana(pl, znak_g) == true)
				{
					cout << "Gracz wygral!" << endl;
					break;
				}
				if (remis(pl) == true)
				{
					cout << "Remis!" << endl;
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i < 5; i++) {
				ruch_komp(pl, znak, znak_g);
				system("cls");
				plansza(pl);
				if (wygrana(pl, znak) == true)
				{
					cout << "Komputer wygral!" << endl;
					break;
				}
				if (wygrana(pl, znak_g) == true)
				{
					cout << "Gracz wygral!" << endl;
					break;
				}
				if (remis(pl) == true)
				{
					cout << "Remis!" << endl;
					break;
				}
				ruch_gracza(pl, znak_g);
				system("cls");
				plansza(pl);
				if (wygrana(pl, znak) == true)
				{
					cout << "Komputer wygral!" << endl;
					break;
				}
				if (wygrana(pl, znak_g) == true)
				{
					cout << "Gracz wygral!" << endl;
					break;
				}
				if (remis(pl) == true)
				{
					cout << "Remis!" << endl;
					break;
				}
			}
		}
		cout << "Czy chcesz zagrac ponownie? (T/N)" << endl;
		cin >> wybor;

	} while (wybor == 'T' || wybor == 't');
	return 0;

}

