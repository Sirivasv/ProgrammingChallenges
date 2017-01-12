#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef vector< vector<lli> > Matriz;

const lli MOD = 1000000007LL;

class ChristmasBinaryTree {
	private:
	public:
	
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
	
	Matriz Exponencia(lli N, Matriz a) {
		Matriz ID(a.size(), vector<lli>(a[0].size(), 0));
		for (int i = 0; i < a.size(); ++i) ID[i][i] = 1;
		for (; N; N >>= 1) {
			if (N & 1)
				ID = Multiplica(ID, a);
			a = Multiplica(a, a);
		}
	} 

	string isOrdered(vector<string> words) {
		grafo = vector< vector<int> >(30);
		vis = vector<char>(30);
		for (const auto& wi : words)
			for (int i = 0; i < wi.size() - 1; ++i)
				if (wi[i] != wi[i + 1])
					grafo[wi[i] - 'a'].push_back(wi[i + 1] - 'a');
		string ans = ((HasCycle())?("Impossible"):("Possible"));
		return ans;
	}
	
};
