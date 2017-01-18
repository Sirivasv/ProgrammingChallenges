#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;

const int INF = (1 << 30) - 1;
const int LOGV = 30;
const int MAXV = 35;
const int MAXN = 100005;

int N, M;
int MAT[MAXV][MAXN];
int barr[MAXN];
int ST[MAXN * 3];
ter Qes[MAXN];

void Build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		ST[n] = barr[l];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = ST[ls] & ST[rs];
}

int Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L)) return INF;
	if ((l >= L) && (r <= R)) return ST[n];
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	return Query(L, R, ls, l, m) & Query(L, R, rs, m + 1, r);
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	for (int i = 0; i < M; ++i) {
		int ai, bi, qi;
		scanf("%d%d%d", &ai, &bi, &qi);
		for (int j = 0; j < LOGV; ++j) {
			if (!(qi & (1 << j))) continue;
			MAT[j][ai]++;
			MAT[j][bi + 1]--;
		}
		Qes[i].first.first = ai;
		Qes[i].first.second = bi;
		Qes[i].second = qi;
	}
	
	for (int i = 0; i < LOGV; ++i) {
		for (int j = 1; j <= N; ++j) {
			MAT[i][j] += MAT[i][j - 1];
			if (MAT[i][j] > 0)
				barr[j] |= (1 << i);
		}
	}
	
	Build();
	
	int ok = 1;
	
	for (int i = 0; i < M; ++i) {
		int ai = Qes[i].first.first;
		int bi = Qes[i].first.second;
		int qi = Qes[i].second;
		if (Query(ai, bi) != qi) {
			ok = 0;
			break;
		}
	}
	
	if (!ok) printf("NO\n");
	else {
		cout << "YES\n";
		for (int i = 1; i <= N; ++i) {
			if (i > 1) printf(" ");
			printf("%d", barr[i]);
		}
		printf("\n");
	}
	
	return 0;
}