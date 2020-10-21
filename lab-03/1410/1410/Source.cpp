#include <iostream>
using namespace std;

double delta(double a, double b, double c) {
	
	double delta = b * b - 4 * a * c;
	
	return delta;
}

int ilewynikow(double delta) {
	if (delta < 0) return 0;
	else if (delta == 0) return 1;
	else if (delta > 0) return 2;
}

double oblicz(double delta, double a, double b, double c, double &x1, double &x2) 
{
	
	if (delta < 0)
	{
		return 0;
	}
	else if (delta == 0)
	{
		double x1 = x2 = -b / (2 * a);
		
		return 1;
	}
	else
	{
		double x1 = (-b - sqrt(delta)) / (2 * a);
		double x2 = (-b + sqrt(delta)) / (2 * a);
		
		return 2;
	}
	
}


int main() {

	double a, b, c;
	cout << "Podaj a = ";
	cin >> a ;
	cout << "Podaj b = ";
	cin >> b;
	cout << "Podaj c = ";
	cin >> c;
	if (a == 0) {
		cout << "To nie jest rownanie kwadratowe"; return 0;
	}
	double x1 = 0, x2 = 0;
	double d=delta(a, b, c);
	cout<<"Tyle rozwiazan = "<<ilewynikow(d)<<endl;
	int o=oblicz(d, a, b, c, x1, x2);
	
	cout << "Rozwiazania to: ";
		switch (o) {
		case 0: cout << "Brak rozwiazan"; break;
		case 1: cout << "x = " << x1; break;
		case 2: cout << "x1 = " << x1 << "\nx2 = " << x2; break;
		}
}