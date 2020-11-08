/** @file */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
using namespace std;

/**Funkcja wczytuje dane z pliku tekstowego, zapisuje je do zmiennej typu string
@param name nazwa pliku
@param plik napis do k�rego zosataj� zapisane dane z pliku
*/
void read(string& plik, const string& name);

/**Struktura przechowuj�ca znak, liczbe jego wyst�pien, wskaznik do nastepnego elementu, wskaznik do prawego i lewego potomka
*/
struct Node
{
	Node* next;
	Node* left;
	Node* right;
	char znak;
	int licznik;
};

/**Funkcja liczy ilo�� wyst�pie� danego znaku, oraz tworzy list� jednostronn�
@param plik napis
@param root pocz�tkowy w�ze� listy
*/
void list(string& plik, Node*& root);

/**Funkcja zamieniaj�ca dane dw�ch w�z��w
@param node1
@param node2
*/
void swap(Node* node1, Node* node2);

/**Funkcja, kt�ra sortuje list� jednokierunkow�
@param root pocz�tkowy weze� listy
*/
void sort(Node*& root);

/**Funkcja tworzy drzewo binarne na podstawie listy jednokierunkowej
@param root wska�nik do pierwszego elementu listy
*/
void createTree(Node** root);

/**Funkcja usuwa drzewo z w�z�ami
@param root g��wny w�ze�
*/
void deletetree(Node* root);

/**Funkcja przypisuje unikatowy kod dla danego znaku
@param c znak do kt�rego zostaje przypisany kod
@param root pocz�tkowy weze� drzewa
@param tempcode zmienna, w ktorej zapisany jest zakodowany znak w danej rekurencji
@param code zmienna, w ktorej zapisany jest zakodowany znak
*/
bool codeletter(char c, Node* root, string tempcode, string& code);

/**Funkcja, kt�ra koduje ca�y tekst
@param plik tekst, kt�ry zostanie zakodowany
@param root pocz�tkowy weze� drzewa
@return zakdowany ci�g znak�w
*/
string codetext(string plik, Node* root);

/**Funkcja wyszukuje znak i tworzy s�owniczka 
@param plik
@param root pocz�tkowy weze� drzewa
@return s�owniczek
*/
string createDictionary(string plik, Node* root);

/**Funkcja zapisuje do pliku
@param code dane do zapisania
@param name nazwa pliku tekstowego
*/
void save(string code, const string& name, const string output);


/**Funkcja zapisuje zakodowany tekst w postaci binarnej
@param code dane do zapisania
@param name nazwa pliku tekstowego
*/
void writebin(string code, const string& name);

/**Funkcja odczytuje z postaci binarnej zakodowany tekst
@param name nazwa pliku do odczytania
*/
string readbin(const string& name);

/**Funkcja odczytuje z pliku s�ownika
@param code
@param name nazwa pliku
@return rozkodowany tekst
*/
string readfile(string code, const string& name);