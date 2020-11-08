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
	//cout<<" -i plik wejsciowy- o plik wyjsciowy- t tryb : k �kompresja, d �dekompresja- s plik ze slownikiem";
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
/*Napisa� program do kompresji plik�w metod� Huffmanna.Program uruchamiany jest z linii polece� z wykorzystaniem nast�puj�cych prze��cznik�w:
-i plik wej�ciowy
-o plik wyj�ciowy
-t tryb: k �kompresja, d �dekompresja
-s plik ze s�ownikiem (tworzonym w czasie kompresji, u�ywanym w czasie dekompresji)*/

/*1.Celem projektu jest nabycie umiej�tno�ci korzystania z dynamicznych struktur danych (np. listy, drzewa, stosy, kolejki itd.). 
Warunkiem zaliczenia programu jest u�ycie tych struktur.
2.U�ycie bibliotecznych kontener�w biblioteki stl jest dozwolone (np. std::vector, std::list itd.).
3.Mo�na u�ywa� typu std::string do przeprowadzenia dowolnej operacji na danych typu tekstowego.
4.Przed implementacj� konieczna jest akceptacja struktury danych przez prowadz�cego zaj�cia.
5.Program powinien by� podzielony na pliki z deklaracjami (*.h) i definicjami (*.cpp).
6.Uruchomienie programu bez parametr�w powoduje wypisanie kr�tkiej informacji o tym, jak u�y� programu.
7.Wszystkie funkcje musz� by� skomentowane w doxygenie*/