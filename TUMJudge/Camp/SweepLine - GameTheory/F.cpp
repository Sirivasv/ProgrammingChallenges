#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef double Coord;
const double ERROR = 1e-9;

bool Igual(Coord a, Coord b) {
    return fabs(a - b) < ERROR;
}

struct Punto {
    Coord x, y;

    Punto() : x(0), y(0) {}
    Punto(Coord x_, Coord y_)
        : x(x_), y(y_) {}

    bool operator<(const Punto& cmp) const {
        if (Igual(x, cmp.x))
            return y < cmp.y;
        return x < cmp.x;
    }
};

double Cruz(const Punto& v, const Punto& w) {
    return v.x * w.y - v.y * w.x;
}

Punto Trasladar(const Punto& o, const Punto& p) {
    return Punto(p.x - o.x, p.y - o.y);
}

int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
    double ccw = Cruz(Trasladar(o, p), Trasladar(o, q));
    return Igual(ccw, 0)? 0: (ccw < 0)? -1: 1;
}

typedef vector<Punto> Poligono;

Poligono CercoConvexo( vector<Punto>& P){
    sort(P.begin(), P.end());
    Poligono arriba;
    for (int i = 0; i < P.size(); ++i) {
        while (arriba.size() > 1) {
            int p = arriba.size() - 1;
            if (ManoDerecha(arriba[p - 1],
                arriba[p], P[i]) < 0) break;
            arriba.pop_back();
        }
        arriba.push_back(P[i]);
    }
    Poligono abajo;
    for (int i = P.size() - 1; i >= 0; --i) {
        while (abajo.size() > 1) {
            int p = abajo.size() - 1;
            if(ManoDerecha(abajo[p - 1], abajo[p], P[i]) < 0) break;
            abajo.pop_back();
        }
        abajo.push_back(P[i]);
    }
    arriba.pop_back();
    arriba.insert(arriba.end(),
        abajo.begin(), abajo.end());
    return arriba;
}


int main() {
	cin.tie(0);	ios_base::sync_with_stdio(0);
    int T;
	cin >> T;
    for (int nc = 1; nc <= T; ++nc) {
		int N;
		cin >> N;
		Poligono P;
		map<pii, int> ID;
		for (int i = 0; i < N; ++i) {
			int x, y;
			cin >> x >> y;
			P.push_back(Punto(x, y));
			ID[pii(x, y)] = (i + 1);
		}
		set<int> idp;
		P = CercoConvexo(P);
		int lim = P.size() - 1;
		for (int i = 0; i < lim; ++i)
			idp.insert(ID[pii(P[i].x, P[i].y)]);
		int cnt = 0;
		cout << "Case #" << nc << ':';
		for (set<int>::iterator it = idp.begin(); it != idp.end(); it++)
			cout << ' ' << (*it);
		cout << '\n';
	}
	return 0;
}
