#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 100009;
const int MAXM = 10;

lli arr[MAXN][MAXM];

set<pii> det[MAXM];

lli anshots[MAXM];

int main() {
	
	int N, M;
	lli K;
	
	scanf("%d%d%lld", &N, &M, &K);
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%lld", &arr[i][j]);
	
	int ini = 0;
	
	int ans = 0;
	
	for (int fin = 0; fin < N; ++fin) {
		for (int i = 0; i < M; ++i) det[i].insert(pii(arr[fin][i], fin));
		lli shots_needed = 0;
		for (int i = 0; i < M; ++i) shots_needed += (*det[i].rbegin()).first;
		if (shots_needed <= K) {
			if ((fin - ini + 1) > ans) {
				ans = fin - ini + 1;
				for (int i = 0; i < M; ++i) anshots[i] = (*det[i].rbegin()).first;
			}
		} else {
			while ((shots_needed > K) && (ini <= fin)) {
				for (int i = 0; i < M; ++i) det[i].erase(pii(arr[ini][i], ini));
				ini++;
				shots_needed = 0;
				for (int i = 0; i < M; ++i) if (det[i].size()) shots_needed += (*det[i].rbegin()).first;
			}
			if ((ini <= fin) && ((fin - ini + 1) > ans)) {
				ans = fin - ini + 1;
				for (int i = 0; i < M; ++i) anshots[i] = (*det[i].rbegin()).first;
			}
		}
	}
	
	for (int i = 0; i < M; ++i) {
		if (i) printf(" ");
		printf("%lld", anshots[i]);
	}
	printf("\n");
	
	return 0;
}