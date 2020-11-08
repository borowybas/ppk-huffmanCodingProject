#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[])
{
	string inputname = "plik.txt";
	string outputname = "code.txt";
	string dictionary = "letterandcode.txt";
	char mode = NULL;
	if (argc == 1 || argc != 9 || argc == 0) {
		cout << "-i plik wejsciowy\n-o plik wyjsciowy\n-t tryb : k –kompresja, d –dekompresja\n-s plik ze slownikiem\n";
	}
	else {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-i") == 0 && argv[i+1] != NULL)
				inputname = argv[i+1];
			if (strcmp(argv[i], "-o") == 0 && argv[i + 1] != NULL)
				outputname = argv[i + 1];
			if (strcmp(argv[i], "-s") == 0 && argv[i + 1] != NULL)
				dictionary = argv[i + 1];
			if (strcmp(argv[i], "-t") == 0 && argv[i + 1] != NULL)
				mode = *argv[i + 1];
		}
		switch (mode)
		{
		case 'k': {
			string plik;
			string code = "";
			read(plik, inputname);
			if (plik == "") { cout << "Brak danych do skompresowania"; break; }
			Node* root;
			list(plik, root);
			sort(root);
			createTree(&root);
			string output = codetext(plik, root);
			save(createDictionary(plik, root), dictionary, output);
			writebin(output, outputname);
			deletetree(root); 
			cout << "compressing statuss: finished";
			break; }
		case 'd': {string text = readbin(outputname);
			string decode = readfile(text, dictionary);
			cout << decode;
			 break; }
		default:cout << "Nie ma takiego trybu";
			break;
		}
	}
    std::cout << "\nHello World!\n";
	return 0;
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