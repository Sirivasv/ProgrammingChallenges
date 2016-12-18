#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef vector< vector<lli> > Matriz;

const lli MOD = 1000000007LL;

Matriz Multiplica(Matriz a, Matriz b) {
	Matriz respuesta(a.size(), vector<lli>(b.size(), 0));
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			// fila i por col j;
			lli sum = 0;
			for (int k = 0; k < a[i].size(); ++k)
				sum = (sum + ((a[i][k] * b[k][j]) % MOD)) % MOD;
			respuesta[i][j] = sum;
		} 
	}
	return respuesta;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	Matriz Ady(4, vector<lli>(4, 1));
	Matriz ID(4, vector<lli>(4, 0));
	for (int i = 0; i < 4; ++i) {
		Ady[i][i] = 0;
		ID[i][i] = 1;
	}
	
	int N;
	cin >> N;
	for (; N; N >>= 1) {
		if (N & 1)
			ID = Multiplica(ID, Ady);
		Ady = Multiplica(Ady, Ady);
	}
	cout << ID[0][0] << '\n';
	return 0;
}
