#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5009;

string s[MAXN];
int n , m, b[MAXN], ans, a[MAXN];

int main() {	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> s[i];
	
	for (int i = 0; i < m; ++i) {	
		memset(a, 0, sizeof a);	
		for (int j = 0; j < n; ++j) if (s[j][i] == '1') b[j]++, a[b[j]]++; else b[j] = 0;
		for (int j = m; j >= 0; --j) a[j] += a[j + 1], ans = max(ans, a[j] * j);
	}
	
	cout << ans << '\n';
	
	return 0;
}