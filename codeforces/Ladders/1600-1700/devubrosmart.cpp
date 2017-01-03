#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

lli a[MAXN], b[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N, M;
	
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < M; ++i) cin >> b[i];
	
	sort(a, a + N); sort(b, b + M, greater<int>());
	
	lli res = 0;
	
	int lim = min(M, N);
	
	for (int i = 0; i < lim && a[i] < b[i]; ++i) res += b[i] - a[i];	
	
	cout << res << '\n';
	
	return 0;
}