/** @file */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;

/**Funkcja wczytuje dane z pliku tekstowego
@param name nazwa pliku
@param plik napis do kórego zosataj¹ zapisane dane z pliku
*/
void read(string& plik, const string& name);

struct Node
{
	Node* next;
	Node* left;
	Node* right;
	char znak;
	int licznik;
};

/**Funkcja liczy iloœæ wyst¹pieñ danego znaku, oraz tworzy listê jednostronn¹
@param plik napis
@param root pocz¹tkowy wêze³ listy
*/
void list(string& plik, Node*& root);

void deletelist(Node*& root);

/**Funkcja zamieniaj¹ca dane dwóch wêz³ów
@param node1
@param node2
*/
void swap(Node* node1, Node* node2);

/**Funkcja, która sortuje listê jednokierunkow¹
@param root pocz¹tkowy weze³ listy
*/
void sort(Node*& root);

/**Funkcja tworzy drzewo binarne na podstawie listy jednokierunkowej
@param root wskaŸnik do pierwszego elementu listy
*/
void createTree(Node** root);

/**Funkcja usuwa drzewo z wêz³ami
@param root g³ówny wêze³
*/
void deletetree(Node* root);

/**Funkcja przypisuje unikatowy kod dla danego znaku
@param c znak do którego zostaje przypisany kod
@param root pocz¹tkowy weze³ drzewa
@param tempcode zmienna, w ktorej zapisana jest zakodowany znak w danej rekurencji
@param code zmienna, w ktorej zapisana jest zakodowany znak
*/
bool codeletter(char c, Node* root, string tempcode, string& code);

/**Funkcja, która koduje ca³y tekst
@param plik tekst, który zostanie zakodowany
@param root pocz¹tkowy weze³ drzewa
@return zaodowany ci¹g znaków
*/
string codetext(string plik, Node* root);

/**Funkcja wyszukuje znak i tworzy s³owniczka 
@param plik
@param root pocz¹tkowy weze³ drzewa
@return s³owniczek
*/
string uniq(string plik, Node* root);

/**Funkcja zapisuje do pliku
@param code dane do zapisania
@param name nazwa pliku tekstowego
*/
void save(string code, const string& name);

/**Funkcja odczytuje z pliku s³ownika
@param code 
@param name nazwa pliku
@return rozkodowany tekst
*/
string readfile(string code, const string& name);

/**Funkcja zapisuje zakodowany tekst w postaci binarnej
@param code dane do zapisania
@param name nazwa pliku tekstowego
*/
void writeb(string code, const string& name);

string readbin(const string& name);

void readb(const string& name);