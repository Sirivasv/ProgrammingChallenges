#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAXN = 1000009;

ull MOD = 100000006147LL;

ull B = 71LL, HB[MAXN];

ull F(char a) {
	return (a - 'a');
}

ull Mult(ull a, ull b) {
    ull resultado = 0;
    for (; b; b >>= 1) {
        if (b & 1) resultado = (resultado + a) % MOD;
        a = (a + a) % MOD;
    }
    return resultado;
	//return a * b;
}

void CB() {
	HB[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		HB[i] = Mult(HB[i - 1], B);
}

vector<ull> Mhash(const string& s) {
	vector<ull> vs(s.size() + 1, 0);
	int lim = s.size();
	for (int i = 1; i <= lim; ++i)
		vs[i] = (Mult(vs[i - 1], B) + F(s[i - 1])) % MOD;
	return vs;
}

ull Subs(const vector<ull>& HA, int I, int J) {
	return (HA[J] - Mult(HA[I - 1], HB[J - I + 1]) + MOD) % MOD;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	CB();
	int N, M;
	cin >> N >> M;
	set<ull> wmemory;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		vector<ull> hashs = Mhash(s);
		wmemory.insert(hashs[s.size()]);
	}
	
	for (int i = 0; i < M; ++i) {
		string s;
		cin >> s;
		vector<ull> hashs = Mhash(s);
		int lim = s.size(); 
		int ok = 0;
		for (int j = 0; j < lim; ++j) {
			for (int k = 0; k < 3; ++k) {
				if ((k + 'a') == s[j]) continue;
				ull Q = Mult((Mult(hashs[j], B) + F(k + 'a')) % MOD, HB[lim - 1 - j]);
				if (j != (lim - 1)) Q = (Q + Subs(hashs, j + 2, lim))% MOD;
				ok = (wmemory.find(Q) != wmemory.end());
				if (ok) break;
			}
			if (ok) break;
		}
		cout << ((ok)?("YES\n"):("NO\n"));
	}
	
	return 0;
}