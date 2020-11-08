// huffmann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include "funkcje.h"

using namespace std;

int main()
{
	//char what;
	//cout<<" -i plik wejsciowy- o plik wyjsciowy- t tryb : k –kompresja, d –dekompresja- s plik ze slownikiem";
	//cin >> what;
	
	string plik;
	string code="";
	read(plik, "plik.txt");
	Node* root;
	list(plik, root);
	sort(root);
	//deletelist(root);
	createTree(&root);
	string output = codetext(plik, root);
	cout<< plik << output << endl;
	save(uniq(plik, root), "lettandcode.txt");
	writeb( output , "code.txt");
	string text = readbin("code.txt");
	string decode = readfile(text, "lettandcode.txt");
	cout << decode;
	deletetree(root);
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