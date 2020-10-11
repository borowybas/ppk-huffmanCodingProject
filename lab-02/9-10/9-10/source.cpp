#include <iostream>
#include <limits>
using namespace std;

int GetSize(const int maxSize = 100)
{
	int n;
	do {
		cout << "Ilosc ocen = ";
		cin >> n;
	} while (n <= 0 || n > maxSize);
	return n;


}
void getdata(int *tab, const int n) 
{
	for (int i = 0; i < n; ++i) {
		cout << "Podaj ocene nr " << i + 1 << ": ";
		cin >> tab[i];
	} 
}

void showdata(int* tab, const int n)
{
	for (int i = 0; i < n; i++) {
		cout << "ocena " << i + 1 << " = ";
		cout << tab[i] << endl;
	}
}

int suma(int *tab, const int n)
{
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s = s + tab[i];
	}
	return s;
}

double srednia(int *tab, const int n)
{
	double srednia = 1.0*suma(tab, n) / n;
	return srednia;
}

int min(int *tab, const int n)
{
	

	int min = numeric_limits<int>::max();
	for (int i = 0; i < n; i++)
	{
		if (tab[i] < min) min = tab[i];
	}
	return min;
}

int max(int *tab, const int n)
{
	
	int max = numeric_limits<int>::min();
	for (int i = 0; i < n; i++)
	{
		if (tab[i] > max) max = tab[i];
	}
	
	
	return max;
}

int main()
{
	const int maxSize = 10;
	int n = GetSize(10);
	int tablica[maxSize];
	getdata(tablica, n);
	suma(tablica, n);
	showdata(tablica, n);
	cout<<"Suma: "<<suma(tablica, n)<<endl;
	cout <<"Srednia: "<< srednia(tablica, n)<<endl;
	cout<<"Max: "<<max(tablica, n)<<endl;
	cout<<"Min: "<<min(tablica, n);
}
