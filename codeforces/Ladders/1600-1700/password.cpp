#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAXN = 1000009;

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

string s, mids;

bool FoundInM(const vector<ull>& HM, const vector<ull>& HS, int len) {
	int lim = (HM.size() - len);
	for (int i = 1; i <= lim; ++i)
		if (Subs(HM, i, i + (len - 1)) == Subs(HS, 1, len))
			return true;
	return false;
}

int Busbin(const vector<ull>& HM, const vector<ull>& HS) {
	int ini = 0, fin = HM.size() - 1, ans = 0;
	while (ini <= fin) {
		int m = (ini + fin) / 2;
		if (FoundInM(HM, HS, m)) {
			ans = m;
			ini = m + 1;
		} else fin = m - 1;
	}
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	CB();
	cin >> s;
	if ((s.size() == 1) || (s.size() == 2)) {
		cout << "Just a legend\n";
		return 0;
	}
	mids = s.substr(1, s.size() - 2);
	vector<ull> HashMid = Mhash(mids);
	vector<ull> HashS = Mhash(s);
	int matslen = Busbin(HashMid, HashS);
	while (matslen) {
		if (Subs(HashS, 1, matslen) == Subs(HashS, s.size() - (matslen - 1), s.size()))
			break;
		matslen--;
	}
	cout << ((matslen)?(s.substr(0, matslen)):("Just a legend")) << '\n';
	return 0;
}