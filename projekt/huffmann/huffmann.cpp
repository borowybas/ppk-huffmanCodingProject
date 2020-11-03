// huffmann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>

#include "funkcje.h"

using namespace std;

//drzewo binarne
void read(string &plik, int& n, const string& name) {
	ifstream stream(name.c_str());
	char litera;
	int i = 0;
	while (stream >> litera) {
		plik.push_back(litera);
		
		++i;
	}
	n = i;
	stream.close();
}
struct Node
{
	Node* next;
	Node* left;
	Node* right;
	char znak;
	int licznik;
};

void count(string& plik, Node* &root) {
	
	Node* temp;
	temp = NULL;
	root = NULL;
	int flag = 0;

	for (int i = 0; i < plik.size(); i++) {
		temp = root;
		while (temp != NULL) {
			if (plik[i] == temp->znak) {
				temp->licznik += 1;
				flag = 1;
				break;
			}
			else {
				temp = temp->next;
				flag = 0;
			}
		}
		if (!flag) {
			temp = new Node;
			temp->next = NULL;
			temp->left = NULL;
			temp->right = NULL;
			temp->znak = plik[i];
			temp->licznik = 1;
			if (i == 0) root = temp;
			else if (i != 0) {
				Node* lastel;
				lastel = root;
				while (lastel->next != NULL) {
					lastel = lastel->next;
					}
				lastel->next = temp;
			}
		}
	}
}

void deletelist(Node*& root) {
	Node* pomocniczy;
	pomocniczy = root;
	while (pomocniczy != NULL) {
		pomocniczy = root->next;
		delete root;
		root = pomocniczy;
	}
}

int main()
{
	int n;
	string plik;
	read(plik, n, "plik.txt");
	
	Node* root;
	count(plik, root);
	deletelist(root);

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