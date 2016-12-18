#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main () {
	cin.tie(0); ios_base::sync_with_stdio(0);
	vector<lli> par, impar;
	int N, K, P;
	cin >> N >> K >> P;
	vector< vector<lli> > parts(K);
	
	for (int i = 0; i < N; ++i) {
		lli a;
		cin >> a;
		if (a & 1) impar.push_back(a);
		else par.push_back(a);
	}
	
	int lim = par.size();
	for (int i = 0; i < lim; ++i)
		parts[i % K].push_back(par[i]);
	
	lim = min((int)impar.size(), K - P);
	for (int i = 0; i < lim; ++i)
		parts[(K - 1) - (i % (K - P))].push_back(impar[i]);
	
	int manyp = 0, manyi = 0, ok = 1;
	
	int cnt = lim;
	for (int i = lim; i < impar.size(); i += 2) {
		if ((i + 1) < impar.size()) {
			parts[(K - 1) - (cnt % K)].push_back(impar[i]);
			parts[(K - 1) - (cnt % K)].push_back(impar[i + 1]);
		} else { ok = 0; break; }
		cnt++;
	}

	for (int i = 0; i < K; ++i) {
		lim = parts[i].size();
		if (lim == 0)
			ok = 0;
		lli sum = 0;
		for (int j = 0; j < lim; ++j)
			sum += parts[i][j];
		if (sum & 1) manyi++;
		else manyp++;
	}
	
	if ((manyi == (K - P)) && (manyp == P) && ok) {
		cout << "YES\n";
		for (int i = 0; i < K; ++i) {
			lim = parts[i].size();
			cout << lim;
			for (int j = 0; j < lim; ++j) {
				cout << ' ';
				cout << parts[i][j];
			}
			cout << '\n';
		}
	} else
		cout << "NO\n";
	return 0;
}