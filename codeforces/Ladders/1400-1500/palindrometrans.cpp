#include <bits/stdc++.h>
using namespace std;

int Abs(int x) { return ((x > 0)?(x):(-x)); }

int GetCst(char a, char b) {
	int va = a - 'a';
	int vb = b - 'a';
	return min(Abs(va - vb), 26 - Abs(va - vb));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, p;
	cin >> N >> p;
	string s;
	cin >> s;
	int cst = 0;
	
	int halve = (N >> 1);
	
	if ((p == ((N + 1) >> 1)) && (N & 1))
		p--;
	
	int ini = 0, fin = halve, sidev = 1;
	
	if (p > halve) {
		ini = halve + (N & 1);
		fin = N;
		sidev = -1;
	}
	
	p--;
	
	vector<int> vs(2, 0);
	int tp = 0;
	
	for (int i = ini; i < fin; ++i) {
		//cout << i << ' ' << (N - i - 1) << '\n';
		//cout << s[i] << ' ' << s[(N - i - 1)] << '\n';
		cst += GetCst(s[i], s[N - i - 1]);
		if (i == p) {
			tp++;
			continue;
		}
		if (GetCst(s[i], s[N - i - 1]))
			vs[tp] = max(vs[tp], Abs(i - p));
	}
	//cout << vs[0] << ' ' << vs[1] << '\n';
	//cout << cst << "**\n";
	cst += ((min(vs[0], vs[1])) * 2) + max(vs[0], vs[1]);
	
	cout << cst << '\n';
	return 0;
}