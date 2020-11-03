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

void listaznakow(string& plik, vector<Node*> vec) {	

	for (int i = 0; i < plik.size(); i++) {
		Node* p = vec[0];
		for (int j = 0; j<vec.size(); j++) {
			if (plik[i] == p->znak) {
				p->licznik++; break;
			}
			else{
				Node  n = { NULL, NULL, NULL, plik[i], 1 };
				Node* ptr = &n;
				vec.push_back(ptr);
			}
			cout << p->znak << p->licznik;
			p++;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
	}
}

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


/*struct node {
	string s;
	node* left;
	node* right;
};



void add(node*& root, const string& value) {
	if (root == nullptr) root = new node{ value, nullptr, nullptr };
	else {
		if (value < root->s) add(root->left, value);
		if (value > root->s) add(root->right, value);
	}
}*/

int main()
{
	

	/*node* _root = nullptr;
	add(_root, "Katarzyna");
	add(_root, "Anna");
	add(_root, "Kinga");

	delete _root;


	node root;
		*/


	int n;
	string plik;
	read(plik, n, "plik.txt");
	//vector<Node*> vec;
	//listaznakow(plik, vec);
	
	Node* root;
	count(plik, root);

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