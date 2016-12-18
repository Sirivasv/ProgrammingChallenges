#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

typedef pair<int, int> pii;

const int MAXN = 2000;

//ull MOD = 100000006147LL;

ull B = 71LL, HB[MAXN];

ull F(char a) {
	return (a - 'A');
}

ull Mult(ull a, ull b) {
    /*ull resultado = 0;
    for (; b; b >>= 1) {
        if (b & 1) resultado = (resultado + a) % MOD;
        a = (a + a) % MOD;
    }
    return resultado;*/
	return a * b;
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
		vs[i] = (Mult(vs[i - 1], B) + F(s[i - 1])); //% MOD;
	return vs;
}

ull Subs(const vector<ull>& HA, int I, int J) {
	return (HA[J] - Mult(HA[I - 1], HB[J - I + 1])); //+ MOD) % MOD;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	CB();
	
	string s, cst;
	int K;
	
	cin >> s >> cst >> K;
	
	vector<ull> Shash = Mhash(s);
	
	set<ull> strs;
	int lim = s.size();
	int acum = 0;
	
	set<pii> pos;
	pos.insert(pii(0, -1));
	for (int i = 0; i < s.size(); ++i) {
		acum += 1 - (cst[s[i] - 'a'] - '0');
		pii pit(acum - K, -1);
		set<pii>::iterator it = pos.lower_bound(pit);
		for (; it != pos.end(); it++) {
			int left_id = (*it).second;
			strs.insert(Subs(Shash, left_id + 2, i + 1));
		}
		pit.second = i;
		pit.first = acum;
		pos.insert(pit);
	}
	
	cout << strs.size() << '\n';
	
	return 0;
}