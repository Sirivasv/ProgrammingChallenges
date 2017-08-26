#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli MOD = 1000000007LL;
const lli BAS = 31LL;
const int MAXN = 600000;

lli hashT[MAXN], hashPattern, PB[MAXN];
string txt, pttrn;

lli val(char c) {
	if ((c >= 'A') && (c <= 'Z')) return (c - 'A') + 1;
	return ((c - 'a') + 27);
}

void getHash(const string& s) { 
	int lim = s.size(); 
	for (int i = 1; i <= lim; ++i) hashT[i] = ((hashT[i - 1] * BAS) + val(s[i - 1])) % MOD;
}

lli getSubHash(int I, int J) { return (hashT[J] - ((hashT[I - 1] * PB[J - I + 1]) % MOD) + MOD) % MOD;}

int solveP() {
	int limt = txt.size(), limp = pttrn.size(), ans = 0, id = 1;
	for (int pos = 0; pos < limt; ++pos) {
		hashT[id] = ((hashT[id - 1] * BAS) + val(txt[pos])) % MOD;
		if (id >= limp) {
			if (hashPattern == getSubHash(id - limp + 1, id)) {
				ans++;
				id = id - limp;
			}
		}
		id++;
	}
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	PB[0] = 1LL;
	for (int i = 1; i < MAXN; ++i) PB[i] = (PB[i - 1] * BAS) % MOD;
	while( cin >> pttrn >> txt) {
		getHash(pttrn);
		hashPattern = hashT[pttrn.size()];
		cout << solveP() << '\n';
	}
	return 0;
}