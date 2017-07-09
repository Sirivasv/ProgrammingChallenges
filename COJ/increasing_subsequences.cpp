#include <bits/stdc++.h>
using namespace std;
const int MAXS = 100005;
const int MAXN = 10005;
const int MAXK = 55;
const long long MOD = 5000000;

long long BIT[MAXS][MAXK];
int N, K, x;

void Update(int id, long long val, int k) {
	while (id < MAXS) {
		BIT[id][k] = (val + BIT[id][k]) % MOD;
		id += (id & -id);
	}	
}

long long Query(int id, int k) {
	long long sum = 0;
	if (!id) return 0;
	while (id > 0) {
		sum = (sum + BIT[id][k]) % MOD;
		id -= (id & -id);
	}
	return sum;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	long long res = 0LL, aux;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		for (int j = 1; j <= K; ++j)
			Update(x, Query(x - 1, j - 1), j);
		Update(x, 1, 1);
	}
	cout << Query(MAXS - 1, K) << '\n';
	return 0;
} 