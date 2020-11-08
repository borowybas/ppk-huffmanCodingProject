#include "funkcje.h"

void read(string& plik, const string& name) {
	ifstream stream(name.c_str());
	
	if(stream.is_open()){
		string line;
		do {
			getline(stream, plik);
			
		} while (line != "\0");
	}
	stream.close();
}

void list(string& plik, Node*& root) {

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

void swap(Node* node1, Node* node2) {
	int tlicznik = node1->licznik;
	node1->licznik = node2->licznik;
	node2->licznik = tlicznik;

	int tznak = node1->znak;
	node1->znak = node2->znak;
	node2->znak = tznak;
}

void sort(Node*& root) {
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
	Node* temp_root, * temp_next, * newnode, * begin, * temp_begin;

	temp_root = *root;
	temp_next = temp_root->next;

	while (temp_next != NULL) {

		begin = temp_next->next;
		newnode = new Node;
		newnode->znak = NULL;
		newnode->right = temp_next;
		newnode->left = temp_root;
		newnode->licznik = temp_root->licznik + temp_next->licznik;

		if (!begin || newnode->licznik <= begin->licznik) {
			newnode->next = begin;
			begin = newnode;
			temp_begin = begin;
		}
		else {
			temp_begin = begin;
			while ((begin->licznik < newnode->licznik) && begin->next != NULL) {
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

void deletetree(Node* root) {
	if (root)
	{
		deletetree(root->left);
		deletetree(root->right);
		delete root;
	}
}

bool codeletter(char c, Node* root, string tempcode, string& code) {
	if (root != NULL) {
		codeletter(c, root->left, tempcode + "0", code);
		if (root->znak == c) {
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
		code += code01;
	}
	return code;
}

string createDictionary(string plik, Node* root) {
	string unique = "";
	 
	for (int i = 0; i < plik.size(); i++) {
		size_t found = unique.find(plik[i]);
		if (found == std::string::npos) {
			unique += plik[i];
		}
	}
	string lettandcode = "";
	for (int i = 0; i < unique.size(); i++) {
		string code01 = "";

		codeletter(unique[i], root, "", code01);
		lettandcode = lettandcode + unique[i] + code01 + "\n";
	}
	return lettandcode;
}

void save(string code, const string& name, const string output) {
	unsigned int length = output.length();
	ofstream stream(name.c_str());
	stream << length<<endl;
	stream << code;
	stream.close();
}

void writebin(string code, const string& name) {
	ofstream stream(name.c_str(), ios::binary);
	uint8_t byte = 0;
	uint8_t index = 0;
	uint8_t temp = 0;
	if (stream.good()==true) {
		for (int i = 0, j = 1; i <= code.size(); i++, j++) {
			index = j % 8;
			byte = byte << 1;
			if (code[i] == '1') {
				temp = 1;
				byte = byte | temp;
			}
			if (index == 0 ) {
				stream.write((const char*)&byte, sizeof byte);
			}
			if ( i == code.size()-1 && index) {
				byte = byte << (8 - index);
				stream.write((const char*)&byte, sizeof byte);
			}
		}
	}
	stream.close();
}

string readbin(const string& name) {
	ifstream stream(name.c_str(), ios::binary);
	string text = "";
	uint8_t byte = 0;
	uint8_t bit = 0;
	int size;
	stream.seekg(0, ios::end);
	size = stream.tellg();
	stream.seekg(0, ios::beg);
		for (int k = 0; k < size; k++) {
			stream.read((char*)&byte, 1);
			for (int i = 0; i < 8; i++) {
				bit = byte & 0x80;
				if (bit) {
					text.push_back('1');
				}
				else {
					text.push_back('0');
				}
				byte = byte << 1;
			}
		}
	stream.close();
//	int len = text.length();
//	cout << len << endl;
//	cout << text << endl;
	return text;
}

string readfile(string code, const string& name) {

	vector<char> letters;
	vector<string> codes;
	int length = 0;
	fstream file;
	file.open(name, ios::in);
	if (file.good() == true) {
		string line;
		int j = 0;
		do {
			getline(file, line);
			if (j == 0) {
				stringstream len(line);
				len >> length;
			}
			else {
				letters.push_back(line[0]);
				codes.push_back("");
				for (int i = 1; i < line.length(); i++)
					codes.back() += line[i];
			}
			j++;
		} while (line != "\0");
	}
	else { cout << "Brak dostepu"; }
	file.close();

	string returntext = "";
	string codedletters = "";
	for (int i = 0; i < length; i++) {
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