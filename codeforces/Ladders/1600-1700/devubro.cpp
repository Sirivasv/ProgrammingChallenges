#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;
const lli INF = (1LL << 62);

int N, M;
lli a[MAXN], b[MAXN], suma[MAXN], sumb[MAXN];

lli F(lli xi) {
	lli res = 0;
	
	int id = lower_bound(a + 1, a + N + 1, xi) - a;
	id--;
	if (id) res += id * xi - suma[id];
	
	id = lower_bound(b + 1, b + M + 1, xi) - b;
	id--;
	res += (sumb[M] - sumb[id]) - ((M - id) * xi);
	
	return res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i) cin >> a[i];
	for (int i = 1; i <= M; ++i) cin >> b[i];
	
	sort(a + 1, a + N + 1);
	sort(b + 1, b + M + 1);
	
	for (int i = 1; i <= N; ++i) suma[i] = suma[i - 1] + a[i];
	for (int i = 1; i <= M; ++i) sumb[i] = sumb[i - 1] + b[i];
	
	lli mint = INF;
	
	for (int i = 1; i <= N; ++i) mint = min(mint, F(a[i]));
	for (int i = 1; i <= M; ++i) mint = min(mint, F(b[i]));
	
	cout << mint << '\n';
	
	return 0;
}