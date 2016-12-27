#include <bits/stdc++.h>
using namespace std;

const int MAXC = 100009;

int F[MAXC];

void KMPFailValues(const string& P) {
	F[0] = -1; int j = -1, p = P.size();
	for (int i = 0; i < p; ++i) {
		while (P[i] != P[j] && j >= 0) j = F[j];
		F[i + 1] = ++j;
	}
}

int KMPSearch(const string& T, const string& P) {
	int matches = 0, t = T.size(), p = P.size();
	for (int i = 0, j = 0; i < t; ++i) {
		while (T[i] != P[j] && j >= 0) j = F[j];
		if (++j == p) {
			matches++;
			j = F[j];
		}
	}
	return matches;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	string si, sj, ssi, ssj;
	
	cin >> si >> sj;
	
	ssi = si + si; ssj = sj + sj;
	
	KMPFailValues(si);
	int minlengthi = si.size() / (KMPSearch(ssi, si) - 1); 
	
	KMPFailValues(sj);
	int minlengthj = sj.size() / (KMPSearch(ssj, sj) - 1); 
	
	string mindivisori = si.substr(0, minlengthi);
	string mindivisorj = sj.substr(0, minlengthj);
	
	if (mindivisori == mindivisorj) {
		int ans = 0, size_i = si.size(), size_j = sj.size();
		int lim = min(size_i, size_j), curlen = minlengthi;
		while (curlen <= lim) {
			if (((size_i % curlen) == 0) && ((size_j % curlen) == 0)) ans++;
			curlen += minlengthi;
		}
		cout << ans << '\n';
	} else cout << "0\n";
	return 0;
}