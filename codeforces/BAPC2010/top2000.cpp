#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 62);
const int MAXL = 109;
const int MAXN = 50009;

int N, M;
long long A, B;
long long memo[MAXN][MAXL];
long long duration[MAXN];

long long DP(int id, int manyB) {
	if (id == N) 
		return (manyB)?((M - manyB) * B) : 0;
	if (memo[id][manyB] != -1)
		return memo[id][manyB];
	long long res = INF;
	
	for (long long i = 1; i <= duration[id]; ++i) {
		int nxtV = manyB + duration[id];
		long long csta = A * (duration[id] - i);
		long long cstb = B * (M - (manyB + duration[id]));
		//cout << id << ' ' << manyB << ' ' << nxtV << '\n';
		if (nxtV >= M) {
			csta = (nxtV - M) * A;
			nxtV = 0;
			cstb = 0;
		}
		if (cstb)
			res = min(res, min(DP(id + 1, nxtV) + csta, DP(id + 1, 0) + csta + cstb));
		else
			res = min(res, DP(id + 1, nxtV) + csta);
	}
	return memo[id][manyB] = res;
}

void Limpia() {
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXL; ++j)
			memo[i][j] = -1;
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		Limpia();
		cin >> N >> M;
		cin >> A >> B;
		for (int i = 0; i < N; ++i)
			cin >> duration[i];
		cout << DP(0, 0) << '\n';
	}
	return 0;
}