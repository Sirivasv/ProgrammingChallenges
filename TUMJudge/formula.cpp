#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef pair<double, double> Coord;

const double EPS = 1e-12;

Coord triangle[5];
double sides[5];
double r;

double Abs(double x) {
	return (x < 0) ? -x: x;
}

bool Igual(double a, double b) {
	return Abs(a - b) < EPS;
}

double CalcD(Coord a, Coord b) {
	return sqrt(((a.X - b.X) * (a.X - b.X)) + ((a.Y - b.Y) * (a.Y - b.Y)));
}

void CalcS() {
	int sd = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = i + 1; j < 3; ++j) 
			sides[sd++] = CalcD(triangle[i], triangle[j]);
}

double CalcA() {
	return ((sqrt((4.0 * sides[0] * sides[0] * sides[1] * sides[1]) - (((sides[0] * sides[0]) + (sides[1] * sides[1]) - (sides[2] * sides[2])) * ((sides[0] * sides[0]) + (sides[1] * sides[1]) - (sides[2] * sides[2]))))) / 4.0);
}

double CalcR() {
	CalcS();
	double A = CalcA();
	A += A;
	A /= (sides[0] + sides[1] + sides[2]);
	return A;
}

void Eval() {
	double cr = CalcR();
	double val = 100.0;
	//cout << cr << ' ' << r << '\n';
	val = (val * cr) / r;
	val = val - 100.0;
	if (Igual(cr, r))
		cout << "0\n";
	else
		cout << fixed << setprecision(6) << val << '\n';
	//
}

int main() {
	for (int i = 0; i < 3; ++i)
		cin >> triangle[i].X >> triangle[i].Y;
	cin >> r;
	Eval();
	return 0;
}