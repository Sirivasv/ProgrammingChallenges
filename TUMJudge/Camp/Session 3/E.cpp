#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const lli INF = (1LL << 62);

const int MAXK = 30;
const int MAXN = 2009;
const int MAXV = 20009;

lli memo[MAXK][MAXN];
lli cost[MAXN][MAXN];
lli Acum[MAXN];
lli arr[MAXN];

int N, K;

int BITA[MAXV], BITM[MAXV], sz;

void Update(int idx, int v, int* BIT) {
	while (idx < MAXV) {
		BIT[idx] += v;
		idx += (idx & (-idx));
	}
}

int Query(int idx, int* BIT) {
	int sum = 0;
	while (idx) {
		sum += BIT[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}

int Range(int I, int J, int* BIT) {
	return (Query(J, BIT) - Query(I - 1, BIT));
}

int GetMed() {
	int ini = 1, fin = MAXV - 1, m, ans;
	int lim = (sz + 1) / 2;
	while (ini <= fin) {
		m = (ini + fin) >> 1;
		if (Query(m, BITM) >= lim) {
			ans = m;
			fin = m - 1;
		} else 
			ini = m + 1;
	}
	return ans;
}

void CalcCost() {
	for (int i = 1; i <= N; ++i) {
		int ini = 0, j;
		lli med;
		sz = 0;
		for (j = 0; j < i; ++j) {
			Update(arr[j], 1, BITM);
			Update(arr[j], arr[j], BITA);
			sz++;
		}
		
		j--;
		
		while (j < N) {
			med = GetMed();
			cost[ini][j] = (fabs(((Query(med - 1, BITA))) - ((med) * ((lli)(Query(med - 1, BITM)))))) + (fabs(((Query(MAXV - 1, BITA) - Query(med, BITA))) - ((med) * ((lli)(Query(MAXV - 1, BITM) - Query(med, BITM))))));
			j++;
			if (j == N)
				break;
			Update(arr[j], 1, BITM);
			Update(arr[j], arr[j], BITA);
			
			Update(arr[ini], -1, BITM);
			Update(arr[ini], -arr[ini], BITA);
			ini++;
			
		}
		while (ini < N) {
			Update(arr[ini], -1, BITM);
			Update(arr[ini], -arr[ini], BITA);
			ini++;
		}
		
	}
}

lli DP(int ck, int ci) {
	if (ck == K) {
		if (ci != N)
			return INF;
		return 0;
	}
	if (ci == N)
		return INF;
	if (memo[ck][ci] != -1)
		return memo[ck][ci];
	lli res = INF;
	for (lli i = ci; i < N; ++i)
		res = min(res, DP(ck + 1, i + 1) + cost[ci][i]);
	return memo[ck][ci] = res;
}

void Limpia() {
	for (int i = 0; i < MAXK; ++i)
		for (int j = 0; j < MAXN; ++j)
			memo[i][j] = -1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	Limpia();
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		arr[i] += 10005;
	}
	CalcCost();
	cout << DP(0, 0) << '\n';
	return 0;
}