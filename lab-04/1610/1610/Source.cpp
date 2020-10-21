#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int maxSize = 10;

void show(const double m[][maxSize], const int rows, const int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void read(double m[][maxSize], const int rows, const int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << " m[" << i + 1 << ", " << j + 1 << "] = ";
			cin >> m[i][j];
		}
		cout << endl;
	}
}

int max(double m[][maxSize], const int rows, const int cols) {
	int max = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			if (m[i][j] > max)max = m[i][j];
		}
		return max;
	}
}
int min(double m[][maxSize], const int rows, const int cols) {
	int min = m[0][0];
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			if (m[i][j] < min) min = m[i][j];
		}
		return min;
	}
}

void show(const double v[], const int n) {
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}
}

void read(double v[], const int n) {
	for (int i = 0; i < n; ++i) {
		cout << " v[" << i + 1 << "] = ";
		cin >> v[i];
	}
}

void read(double v[], int& n, const string& name) {
	ifstream stream(name.c_str());
	double value;
	int i = 0;
	while (stream >> value) {
		v[i] = value;
		cout << value << endl;
		++i;
	}
	n = i;
	stream.close();
}

void read1(double v[], int& n, const string& name) {
	ifstream stream(name.c_str());
	n = 0;
	while (stream >> v[n]) ++n;
	stream.close();
}

void write(const double v[], const int n, const string& name) {
	ofstream stream(name.c_str());

	for (int i = 0; i < n; ++i) {
		stream << v[i] << endl;
	}

	stream.close();
}
void writeb(const double v[], const int n, const string& name) {
	ofstream stream(name.c_str());

	for (int i = 0; i < n; ++i) {
		stream.write((char*)&v[i], sizeof(v[i]));
	}

	stream.close();
}


void writeb2(const double v[], const int n, const string& name) {
	ofstream stream(name.c_str());

	stream.write((char*)&v, n * sizeof(*v));
	stream.close();
}

void readb(double v[], int& n, const string& name) {
	ifstream stream(name.c_str(), ios::binary);
	stream.seekg(0, ios::end);
	n = stream.tellg();
	stream.seekg(0, ios::beg);
	stream.read((char*)&v[0], n);
	n /= sizeof(*v);
	stream.close();
}


int main()
{
	double tab[maxSize];
	int n;
	read(tab, n, "dane.txt");
	//show(tab, maxSize);
	//write(tab, n, "dane1.txt");
	//writeb(tab, n, "dane1.bin");
	//readb(tab, n, "dane1.bin");

	/*double matrix[maxSize][maxSize] = { 0 };
	int rows = 3;
	int cols = 4;
	//show(matrix, rows, cols);
	read(matrix, rows, cols);
	cout << "Max = " << max(matrix, rows, cols);
	cout << "Min = " << min(matrix, rows, cols);*/

}