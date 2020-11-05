// huffmann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

#include "funkcje.h"

using namespace std;

//drzewo binarne
void read(string &plik, const string& name) {
	ifstream stream(name.c_str());
	char litera;
	int i = 0;
	while (stream >> litera) {
		plik.push_back(litera);
	}
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

void list(string& plik, Node* &root) {
	
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
void swap(Node* node1, Node* node2) {
	int tlicznik = node1->licznik;
	node1->licznik = node2->licznik;
	node2->licznik = tlicznik;

	int tznak = node1->znak;
	node1->znak = node2->znak;
	node2->znak = tznak;
}
void sort(Node*&root) {
	Node* temp;
	temp = root;
	int flag;
	do {
		flag = 1;
		temp = root;

		while (temp->next) {

			if (temp->licznik > temp->next->licznik) {

				swap(temp, temp->next);
				flag = 0;
			}
			temp = temp->next;
		}
	} while (!flag);
}

void createTree(Node** root) {
	Node* temp_root,* temp_next, *newnode, *begin, *temp_begin;

	temp_root = *root;
	temp_next = temp_root->next;

	while (temp_next != NULL) {

		begin = temp_next->next;
		newnode = new Node;
		newnode->znak = NULL;
		newnode->right = temp_next;
		newnode->left = temp_root;
		newnode->licznik = temp_root->licznik + temp_next->licznik;
		//wstawiæ do listy
		if (!begin || newnode->licznik <= begin->licznik) {
			newnode->next = begin;
			begin = newnode;
			temp_begin = begin;
		}
		else {
			//begin = temp_next->next;
			temp_begin = begin;
			while ((begin->licznik < newnode->licznik) && begin != NULL) {
				begin = begin->next;
			}
			newnode->next = begin->next;
			begin->next = newnode;
		}
		temp_root = temp_begin;
		temp_next = temp_begin->next;
		if (temp_begin->next == NULL) {
			*root = temp_begin;
		}
	}
}

void DFSRelease(Node* v)
{
	if (v)
	{
		DFSRelease(v->left);          // usuwamy lewe poddrzewo
		DFSRelease(v->right);         // usuwamy prawe poddrzewo
		delete v;                     // usuwamy sam wêze³
	}
}

bool codeletter(char c, Node* root, string tempcode, string& code) {
	if (root != NULL) {
		codeletter(c, root->left, tempcode + "0", code);
		if(root->znak == c){
			code = tempcode;
			return true;
		}
		codeletter(c, root->right, tempcode + "1", code);
		if (root->znak == c) {
			code = tempcode;
			return true;
		}
	}
}

string codetext(string plik, Node* root) {
	string code = "";

	for (int i = 0; i < plik.size(); i++) {

		string code01 = "";
		codeletter(plik[i], root, "", code01);
		//code += plik[i];
		code += code01;
	}
	return code;
}

string uniq(string plik, Node* root) {
	string unique = "";
	for (int i = 0; i < plik.size(); i++) {
		size_t found = unique.find(plik[i]);//////char??
		if (found == std::string::npos) {
			unique += plik[i];
		}
	}
	string lettandcode = "";
	for(int i = 0; i < unique.size(); i++){
		string code01 = "";
		
		codeletter(unique[i], root, "", code01);
		lettandcode = lettandcode +unique[i]+code01+ "\n";
		//lettandcode += "	";
		//lettandcode += code01;
		//lettandcode += "\n";
	}
	return lettandcode;
}

void save(string code, const string& name) {

	ofstream stream(name.c_str());
	stream << code << endl;
	stream.close();
}

string readfile(string code, const string& name) {
	//szukaj
	/*vector<pair<char, string>> letter;

	ifstream stream(name.c_str());

	string line;

	if (stream) {
		string line;
		while (stream >> line) {
			char litera;
			getline(stream, line);
			//litera = line[0];
			//cout << line[0];
			string liczba = "";
			for (int i = 1; i < line.length(); i++) {
				liczba.push_back(line[i]);
			}

			pair<char, string> zestaw(line[0], liczba);
			letter.push_back(zestaw);

		}
	}

	for (int i = 0; i < letter.size(); i++)
	{
		cout << "\n" << letter[i].first << " " << letter[i].second;
	}

	stream.close();*/
	vector<char> letters;
	vector<string> codes;


	fstream file;
	file.open(name, ios::in);
	if (file.good() == true) {
		string line;
		do {
			getline(file, line);
			letters.push_back(line[0]);
			codes.push_back("");
			for (int i = 1; i < line.length(); i++)
				codes.back() += line[i];

		} while (line != "\0");
	}
	else cout << "Brak";

	for (int i = 0; i < letters.size(); i++) {
		cout << letters[i] << codes[i];
	}
	file.close();

	string returntext = "";
	string codedletters = "";
	for (int i = 0; i < code.size(); i++) {
		codedletters += code[i];

		for (int j = 0; j < codes.size(); j++) {

			if (codedletters == codes[j]) {
				returntext += letters[j];
				codedletters = "";
				break;
			}
		}
	}
	return returntext;
}

void decompress() {

}
int main()
{
	char what;
	cout<<" -i plik wejœciowy- o plik wyjœciowy- t tryb : k –kompresja, d –dekompresja- s plik ze s³ownikiem";
	cin >> what;
	
	string plik;
	string code="";
	read(plik, "plik.txt");
	
	Node* root;
	list(plik, root);
	sort(root);
	//deletelist(root);
	createTree(&root);
	cout<< plik << " " << codetext(plik,root) << endl;
	save(uniq(plik, root), "lettandcode.txt");
	cout<<readfile(codetext(plik, root), "lettandcode.txt");

	DFSRelease(root);

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