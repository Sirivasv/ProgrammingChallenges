#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

const double ERROR = 1e-9;
const int MAXN = 109;

bool Igual(double a, double b) {
	return fabs(a - b) < ERROR;
} 

struct Punto {
	double x, y;
	Punto() : x(), y() {}
	Punto(double X, double Y) : x(X), y(Y) {}
	bool operator<(const Punto& cmp) const {
		if (!Igual(x, cmp.x)) return x < cmp.x;
		return Igual(y, cmp.y) ? false: y < cmp.y;
	}
	bool operator==(const Punto& cmp) const {
		return Igual(x, cmp.x) && Igual(y, cmp.y);
	}
};

struct Linea {
	Punto p, q;
	double a, b, c;
	Linea() : p(), q(), a(), b(), c() {}
	Linea(const Punto& P, const Punto& Q)
		: p(P), q(Q), a(), b(), c() {
			if (q < p)
				swap(p, q);
			a = q.y - p.y;
			b = p.x - q.x;
			if (Igual(a, 0.0))
				c = p.y, b = -1;
			else if (Igual(b, 0.0))
				c = p.x, a = -1;
			else
				c = -a*p.x - b*p.y;
		}
};

Linea PerpendicularEnPunto(const Linea& l, const Punto& p) {
	return Linea(p, Punto(p.x + l.a, p.y + l.b));
}

Punto PuntoInterseccion(const Linea& l, const Linea& m) {
	if (Igual(l.a, 0.0))
		return Punto((l.c * m.b + m.c) / -m.a, l.c);
	double y_ = (m.a * l.c - l.a * m.c) / (m.b * l.a - m.a * l.b);
	return Punto((l.c + l.b * y_) / -l.a, y_);
}

bool Colinear(const Punto& a, const Punto& b, const Punto& c) {
	return Igual((a.x - b.x) * (c.y - b.y), (a.y - b.y) * (c.x - b.x));  
}

Punto Center(const Punto& a, const Punto& b, const Punto& c) {
	Punto midPointAB((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
	Punto midPointBC((c.x + b.x) / 2.0, (c.y + b.y) / 2.0);
	Linea MAB = PerpendicularEnPunto(Linea(a, b), midPointAB);
	Linea MBC = PerpendicularEnPunto(Linea(b, c), midPointBC);
	return PuntoInterseccion(MAB, MBC);
}

Punto puntos[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		if (!N)
			break;
		if (N <= 2) {
			cout << N << '\n';
			continue;
		}
		for (int i = 0; i < N; ++i)
			cin >> puntos[i].x >> puntos[i].y;
		int ans = 2;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				map<Punto, int> manyp;
				for (int k = 0; k < N; ++k) {
					if (k == i || k == j)
						continue;
					if (Colinear(puntos[i], puntos[k], puntos[j]))
						continue;
					Punto c = Center(puntos[i], puntos[k], puntos[j]); 
					manyp[c]++;
					ans = max(ans, manyp[c] + 2);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}