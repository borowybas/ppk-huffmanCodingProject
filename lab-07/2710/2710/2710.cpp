#include <iostream>

using namespace std;

void Swap(double* const x, double* const y) {
	double buff = *x;
	*x = *y;
	*y = buff;
}

double *Createvector(const int size) {
	return new double[size];//przydzielanie pamiêci
}
void Destroyvector(double** v) {
	delete[] *v;
	*v = nullptr;
}

void show(const double* const v, const int size) {
	if (v == nullptr)return;
	for (int i = 0; i < size; ++i) {
		cout << v[i] << endl;//i[v]//*(v+i)
	}
}
void initvector(double * const v, const int size, double initvalue = 1.0) {
	if (v == nullptr)return;
	for (int i = 0; i <size; ++i)
	{
		*(v + 1) = initvalue++;    //adres kolejnego elementu, v[i]= initvalue++; wy³uskanie

	}
}
double** Creatematrix(const int rows, const int cols) {
	double** m = new double*[rows];//wsk na doubl*

	for (int i = 0; i < rows; ++i) {
		//m[i] = new double[cols];
		*(m+i) = new double[cols];
	}

	return m;
}
void destroymatrix(double*** m, const int rows) {
	if (m == nullptr)return;
	for (int i = 0; i < rows; ++i)delete[] * (*m + i);
	delete[] *m;
	*m = nullptr;
}
void showmatrix(const double* const* const m, const int rows, const int cols) {
	if (m == nullptr)return;
	for (int i = 0; i < rows; ++i) {
		if (*(m + i) == nullptr)continue;
		for (int j = 0; j < cols; ++j) {
			cout << *(*(m + i) + j) << " ";//m[i][j]
		}
		cout << endl;
	}
}
void initmatrix(double *const*const m, const int rows, const int cols, double initvalue=1.0 )
{
	if (m == nullptr)return;
	for (int i = 0; i < rows; ++i) {
		if (*(m + i) == nullptr)continue;
		for (int j = 0; j < cols; ++j) {
			*(*(m + i) + j) = initvalue++;
		}
	}
}
void swaprows( double** m,  int a, int b) {
	if (m == nullptr)return;
	int i = 0;
	double* buff = *(m + a);
	*(m + a) = *(m + b);
	*(m + b) = buff;

}

void swapcols(double* const* const m, const int rows, const int cols, int a, int b) { 

	for (int i = 0; i < rows; ++i) {

		for (int j = 0; j < cols; ++j) {
			double buff = *(*(m + i) + a);
			*(*(m + i) + a) = *(*(m + i) + b);
			*(*(m + i) + b) = buff;
		}
	}
}




int main()
{
	int rows, cols;
	cout << "rows = ";
	cin >> rows;
	cout << "cols = ";
	cin >> cols;


	double** m = Creatematrix(rows, cols);
	initmatrix(m, cols, rows, 5.0);
	showmatrix(m, cols, rows);
	
	swaprows(m,  1, 2);
	swapcols(m, cols, rows, 1, 2);
	showmatrix(m, cols, rows);
	destroymatrix(&m, rows);

	/*
	auto v = Createvector(n);
	initvector(v, n);
	show(v, n);
	Destroyvector(&v);*/
	
	

	/*double a = 3.1415;
	double b = 2.71;
	cout << "a =" << a << endl;
	cout << "b =" << b << endl;
	Swap(&a, &b);
	cout << "a =" << a << endl;
	cout << "b =" << b << endl;*/


	/*double a = 3.1415;
	double* p = &a;

	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	cout << "&p = " << &p << endl;
	cout << "*p = " << *p << endl;
	cout << "++p" << ++p << endl;//zwiekszenie adresu*/


	return 0;
}
