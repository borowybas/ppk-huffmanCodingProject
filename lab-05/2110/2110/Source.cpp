#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

//typedef vector<double> Vector;
//typedef vector<vector<int>> Matrix;
using namespace std;

//struktury moze byc inny typ danych
struct Point {
	double x;
	double y;
	
};



int getsize(const string &text = "n = ") {
	int n;
	do {
		cout << text;
		cin >> n;
	} while (n <= 0);
		return n;
}

void read(vector<double>& v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << "v[" << i + 1 << "] = ";
		cin >> v[i];
	}
}

vector<double> read(const int size) {
	if (size <= 0)return {};//zwrocony pusty vector
	vector<double> v(size);
	read(v);
	return v;
}

void show(const vector<double> &v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}

}

void show1(const vector<double>& v) {
	cout << "[ ";
	for (auto el : v) {
		cout << el << " ";
	}
	cout << "]";
}

void write(const vector<double>& v, const string& filename) {

	ofstream stream(filename);
	if (stream.good()) {
	for (auto el : v) {
		stream << el << endl;
	}
}
	stream.close();
}

vector<double> read(const string& filename) {/////
	vector<double> v;
	ifstream stream(filename);
	double value;
	while (stream >> value) {
		v.push_back(value);
	}

	stream.close();
	return v;
}
//macierz
void show(const vector < vector<int>>& m) {
	for (auto row : m) {
		for (auto el : row) {
			cout << el << " ";
		}
		cout << endl;
	}
}

void read(vector<vector<int>>& m) {
	for (int i = 0; m.size(); ++i) {
		for (int j = 0; j < m[i].size(); ++j) {
			cout << "[" << i + 1 << ", " << j + 1 << "] = ";
			cin >> m[i][j];
		}
	}
}

vector<vector<int>> read(const int rows, const int cols) {
	vector<vector<int>> m(rows, vector<int>(cols));
	read(m);
	return m;
}


void writem(const vector<vector<int>>& m, const string& filename) {

	ofstream stream(filename);
	if (stream.good()) {
		for (auto row : m) {//for (vector<int> row : m) {
			for (auto el : row) {
				stream << el << " ";
			}
			stream << endl;
		}
	}
	stream.close();
}

vector<vector<int>> readm(const string& filename){
	vector < vector<int>> m;
	ifstream stream(filename);
	if (stream.good())
	{
		char buff[1024];
		while (stream.getline(buff, sizeof(buff))) {//odcz caly wiersz
			m.push_back(vector<int>());
			stringstream ss(buff);
			int value;
			while (ss >> value) {
				m.back().push_back(value);//zwraca ost el z wektora
			}
		}

	}
	stream.close();
	return m;


}
//struktury
Point Read() {
	Point p;
	cout << "p.x = ";
	cin >> p.x;
	cout << "p.y = ";
	cin >> p.y;
	return p;
}

void show(const Point& p) {
	cout << "(" << p.x << ", " << p.y << ")" << endl;
}

int main(){
	Point p = { 1, 2 };
	p = Read();
	//p.x = 13.4;
	//p.y = 33.0;
	show(p);
	vector<Point> points(12, Point{ 1, 2 });
	for (auto _p : points) {
		show(_p);
	}


	/*int rows = getsize("rows = ");
	int cols = getsize("cols = ");

	vector<vector<int>> matrix(rows, vector<int>(cols));
	show(matrix);
	read(matrix);
	show(matrix);

	writem(matrix, "matrix.txt");*/
	//auto matrix1 = readm("matrix.txt");
	//show(matrix1);

	//auto matrix1 = read(rows, cols);
	//show(matrix1);

	
	/*int n = getsize();

	vector<double> v(n);
	read(v);
	show(v);
	write(v, "vector.txt");

	auto v1 = read(n);
	show(v1);

	auto v2 = read("vector.txt");
	show1(v2);*/

	return 0;
	}