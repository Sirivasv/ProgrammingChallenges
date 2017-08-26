#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 100009;

lli distto[MAXN], buspeed[MAXN], dp[MAXN], preptrip[MAXN];
vector<pii> grafo[MAXN];
pii rectas[MAXN];

bool bad(pii r2, pii r1, pii r) {
	return 1.0 *(r.second - r2.second) / (r2.first - r.first) < 1.0 * (r1.second - r2.second) / (r2.first - r1.first);
}

int querySearch(lli Xi, int length) {
	int ini = 0, fin = length - 1, ans = 0;
	while (ini <= fin) {
		int m = (ini + fin) >> 1;
		//cout << "M: " << m << '\n';
		if (m == 0) {
			if ((!ini) && (!fin)) return 0;
			lli val1 = (rectas[1].first * Xi) + rectas[1].second;
			lli val2 = (rectas[0].first * Xi) + rectas[0].second;
			//cout << val1 << ' ' << val2 <<'\n';
			if (val2 <= val1) return 0;
			return 1;	
		}
		lli val1 = (rectas[m].first * Xi) + rectas[m].second;
		lli val2 = (rectas[m - 1].first * Xi) + rectas[m - 1].second;
		//cout << val1 << ' ' << val2 <<'\n';
		if (val2 <= val1)
			fin = m - 1;
		else {
			ans = m;
			ini = m + 1;
		}
	}
	return ans;
}

int queryAdd(pii nr, int length) {
	if (length <= 1) return length; 

	int ini = 0, fin = length - 1, ans = length;
	while (ini <= fin) {
		int m = (ini + fin) >> 1;
		if (m == 0) {
			if ((!ini) && (!fin)) return ans;
			if (bad(rectas[0], rectas[1], nr)) return 1;
			return 2;	
 		}
		if ((m >= 1) && bad(rectas[m - 1], rectas[m], nr)) {
			ans = m;
			fin = m - 1;
		} else ini = m + 1;
	}
	return ans;
}

void F(int u, int p, int length) {
	//cout << "//Rectas\n";
	//for (int i = 0; i < length; ++i) 
	//	cout << "Eval " << i << ": " << (rectas[i].first * buspeed[u]) + rectas[i].second << '\n';
	
	int LP = querySearch(buspeed[u], length);
	//cout << "LP:" << LP << "\n";

	dp[u] = (rectas[LP].first * buspeed[u]) + rectas[LP].second;
	dp[u] += (distto[u] * buspeed[u]) + preptrip[u];

	pii nr = pii(-distto[u], dp[u]);

	int idx = queryAdd(nr, length);
	
	//cout << "IDX: " << idx << '\n';

	pii tmp = rectas[idx];

	rectas[idx] = nr;

	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i].first;
		if (v == p) continue;
		lli wi = grafo[u][i].second;
		distto[v] = distto[u] + wi;
		F(v, u, idx + 1);
	}

	rectas[idx] = tmp;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i < N; ++i) {
		int u, v;
		lli ci;
		cin >> u >> v >> ci;
		grafo[u].push_back(pii(v, ci));
		grafo[v].push_back(pii(u, ci));
	}
	for (int i = 2; i <= N; ++i) cin >> preptrip[i] >> buspeed[i];
	rectas[0] = pii(0, 0);
	
	for (int i = 0; i < grafo[1].size(); ++i) {
		int v = grafo[1][i].first;
		distto[v] = grafo[1][i].second;
		F(v, 1, 1);
	}
	
	for (int i = 2; i <= N; ++i) cout << dp[i] << ' ';
		cout << '\n';
	return 0;
}
