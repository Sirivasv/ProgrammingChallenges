#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXM = 3000;
const int MAXN = 509;

int memo[MAXM];
pii Ar[MAXM];
int InD[MAXN];

int DP(int idm) {
	if (idm == M) {
		int mats = 0;
		for (int i = 0; i < N; ++i)
			mats = max(mats, InD[i]);
		return mats;
	}
	if (memo[idm] != -1)
		return memo[id];
	InD[Ar[idm].second]++;
	int opc = DP(idm + 1);
	InD[Ar[idm].second]--;
	int opc = 
}

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	for (int i = 0; i < MAXN; ++i) 
		memo[i] = -1;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		Ar[i].first = u;
		Ar[i].second = v;
	}
	cout << DP(0) << '\n';
	return 0;
}