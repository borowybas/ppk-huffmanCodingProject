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
@param plik napis do ktorego zostaja zapisane dane z pliku
*/
void read(string& plik, const string& name);

/**Struktura przechowujaca znak, liczbe jego wyst¹pien, wskaznik do nastepnego elementu, wskaznik do prawego i lewego potomka
*/
struct Node
{
	Node* next;
	Node* left;
	Node* right;
	char znak;
	int licznik;
};

/**Funkcja liczy ilosc wyst¹pien danego znaku, oraz tworzy liste jednostronna
@param plik napis
@param root poczatkowy weze³ listy
*/
void list(string& plik, Node*& root);

/**Funkcja zamieniajaca dane dwoch wezlow
@param node1
@param node2
*/
void swap(Node* node1, Node* node2);

/**Funkcja, ktora sortuje liste jednokierunkowa
@param root poczatkowy wezel listy
*/
void sort(Node*& root);

/**Funkcja tworzy drzewo binarne na podstawie listy
@param root wskaznik do pierwszego elementu listy
*/
void createTree(Node** root);

/**Funkcja usuwa drzewo z wezlami
@param root glowny wezel
*/
void deletetree(Node* root);

/**Funkcja przypisuje unikatowy kod dla danego znaku
@param c znak do ktorego zostaje przypisany kod
@param root poczatkowy wezel drzewa
@param tempcode zmienna, w ktorej zapisany jest zakodowany znak w danej rekurencji
@param code zmienna, w ktorej zapisany jest zakodowany znak
*/
bool codeletter(char c, Node* root, string tempcode, string& code);

/**Funkcja, ktora koduje ca³y tekst
@param plik tekst, ktory zostanie zakodowany
@param root poczatkowy wezel drzewa
@return zakdowany ciag znakow
*/
string codetext(string plik, Node* root);

/**Funkcja wyszukuje znak i tworzy slowniczek 
@param plik tekst, ktory zostanie zakodowany
@param root pocz¹tkowy weze³ drzewa
@return slowniczek
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

/**Funkcja odczytuje z pliku slownika
@param code
@param name nazwa pliku
@return rozkodowany tekst
*/
string readfile(string code, const string& name);