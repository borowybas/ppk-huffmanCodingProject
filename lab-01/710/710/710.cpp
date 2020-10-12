#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	cout << "1 - dodawanie\n2 - odejmowanie\n3 - mnozenie\n4 - dzielenie\n5 - reszta z dzielenia\n";
	cout << "Podaj dzailanie: ";
	cin >> c;
	switch (c) {
	case 1: cout << "a + b = " << a + b << endl; break;
	case 2: cout << "a - b = " << a - b << endl; break;
	case 3: cout << "a * b = " << a * b << endl; break;
	case 4: 
		if (b != 0)  cout << "a / b = " << a / b << endl; 
		else cout << "Nie mozna dzielic przez 0";
		break;
	case 5: 
		if (b != 0)  cout << "a % b = " << a % b << endl; 
		else cout << "Nie mozna dzielic przez 0";
		break;
	default: cout << "Nie ma takiej operacji" << endl;
				}
	}
