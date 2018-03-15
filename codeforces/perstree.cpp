#include <bits/stdc++.h>
using namespace std;

typedef vector <int > Lista;

const int MAXN = 100009;

struct Nodo {
	int valor;
	int izq, der;
	Nodo(): valor(0),izq(-1),der(-1) {}
};

struct SegmentTree {
	int n;
	Lista tiempos;
	vector <Nodo> Arbol;
	void CreaNodos(int ini, int fin, int pos, int val) {
		Arbol[pos].valor++;

		if( ini == fin ) return;

		int mitad = (ini + fin)/2;

		if (val <= mitad) {
			Arbol.push_back(Nodo());

			if (Arbol[pos].izq != -1)
				Arbol[Arbol.size()-1] = Arbol[Arbol[pos].izq];
			
			Arbol[pos].izq = Arbol.size()-1;

			CreaNodos(ini, mitad, Arbol[pos].izq, val);

		} else {
			Arbol.push_back(Nodo());
			if (Arbol[pos].der != -1)
				Arbol[Arbol.size()-1] = Arbol[Arbol[pos].der];
			Arbol[pos].der = Arbol.size()-1;
			CreaNodos(mitad +1, fin, Arbol[pos].der, val);
		}

	}

	SegmentTree(): Arbol(1, Nodo()) {

	}

	void CreaRaiz(int  ini, int fin, int val) {
		if (tiempos.size())
			Arbol.push_back(Arbol[tiempos[tiempos.size() - 1]]);
		tiempos.push_back(Arbol.size() - 1);
		CreaNodos(ini, fin, Arbol.size() - 1, val);
	}

	int Query(int sPos, int inir, int finr, int pos){
		cout << sPos << ' ' << inir << ' ' << finr << ' ' << pos << '\n';

		if (sPos < inir) return 0;
		
		if (sPos >= finr) return Arbol[pos].valor;

		int mitad = ( inir + finr ) /2;
		int izq = (Arbol[pos].izq == - 1) ? (0) : Query(sPos, inir, mitad, Arbol[pos].izq);
		int der = (Arbol[pos].der == - 1) ? (0) : Query(sPos, mitad +1, finr, Arbol[pos].der);
		return izq + der;
	}

};

vector<int> nexk[MAXN];
int arr[MAXN];

int main () {
	// cin.tie(0); ios_base::sync_with_stdio(0);

	int N, K;

	cin >> N >> K; 

	SegmentTree ST = SegmentTree();

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];

		int val = -1;

		if (nexk[arr[i]].size() >= K)
			val = nexk[arr[i]][nexk[arr[i]].size() - K];
		
		ST.CreaRaiz(0, N - 1, val);

		nexk[arr[i]].push_back(i);
	}

	int Q;
	cin >> Q;
	int last = 0;
	for (int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		l = (l + last)%N + 1;
		r = (r + last)%N + 1;
		if (l > r) swap(l, r);
		cout << "8* " << l << ' ' << r << '\n';
		int lastIzq = (l - 2 < 0)?(0):(ST.Query(l - 2, 0, N - 1, ST.tiempos[l - 2]));
		int lastDer = ST.Query(r - 1, 0, N - 1, ST.tiempos[r - 1]);
		last = lastDer - lastIzq;
		cout << last << '\n';
	}

	return 0;
}
x