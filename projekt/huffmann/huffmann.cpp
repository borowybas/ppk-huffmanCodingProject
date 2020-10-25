// huffmann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<cstdlib>

#include "funkcje.h"

using namespace std;

//drzewo binarne
void read(string &plik, int& n, const string& name) {
	ifstream stream(name.c_str());
	char litera;
	int i = 0;
	while (stream >> litera) {
		plik.push_back(litera);
		cout << litera << endl;
		++i;
	}
	n = i;
	stream.close();
}
void licz(const string& plik){
	int licze[123] = {};

	int i = 0;
	while (plik[i]) {
		++licze[plik[i]];
		++i;
	}
	for (int i = 97; i < 123; i++) //wypisanie wyst¹pieñ ma³ych liter ASCII - 97-122
		if (licze[i] < 0) //lub if(zlicz[i])
			cout << (char)i << " - " << licze[i] << endl;

	for (int i = 65; i < 91; i++) //wypisanie wyst¹pieñ du¿ych liter ASCII - 65-90
		if (licze[i] < 0) //lub if(zlicz[i])
			cout << (char)i << " - " << licze[i] << endl;
}

int main()
{
	int n;
	string plik;
	read(plik, n, "plik.txt");
	for (int i = 0; i < plik.size(); i++) {
		cout << plik[i];
	}
	licz(plik);
    std::cout << "\nHello World!\n";
}
/*Napisaæ program do kompresji plików metod¹ Huffmanna.Program uruchamiany jest z linii poleceñ z wykorzystaniem nastêpuj¹cych prze³¹czników:
-i plik wejœciowy
-o plik wyjœciowy
-t tryb: k –kompresja, d –dekompresja
-s plik ze s³ownikiem (tworzonym w czasie kompresji, u¿ywanym w czasie dekompresji)*/

/*1.Celem projektu jest nabycie umiejêtnoœci korzystania z dynamicznych struktur danych (np. listy, drzewa, stosy, kolejki itd.). 
Warunkiem zaliczenia programu jest u¿ycie tych struktur.
2.U¿ycie bibliotecznych kontenerów biblioteki stl jest dozwolone (np. std::vector, std::list itd.).
3.Mo¿na u¿ywaæ typu std::string do przeprowadzenia dowolnej operacji na danych typu tekstowego.
4.Przed implementacj¹ konieczna jest akceptacja struktury danych przez prowadz¹cego zajêcia.
5.Program powinien byæ podzielony na pliki z deklaracjami (*.h) i definicjami (*.cpp).
6.Uruchomienie programu bez parametrów powoduje wypisanie krótkiej informacji o tym, jak u¿yæ programu.
7.Wszystkie funkcje musz¹ byæ skomentowane w doxygenie*/