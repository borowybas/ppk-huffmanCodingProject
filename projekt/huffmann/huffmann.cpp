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
	string outputname = "coded.txt";
	string dictionary = "dictionary.txt";
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
			cout << "compressing status: finished";
			break; }
		case 'd': {string text = readbin(outputname);
			string decode = readfile(text, dictionary);
			cout << decode<<endl<<"decompressing status: finished";
			 break; }
		default:cout << "Nie ma takiego trybu";
			break;
		}
	}
	return 0;
}