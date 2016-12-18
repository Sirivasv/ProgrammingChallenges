#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int f[N][26], tot;
char str[N];
int mark[N];

void add(int x, char* s) {
	if (*s == '\0') {
		mark[x]++;
		return;
	}
	int t = *s - 'a';
	int y = f[x][t];
	if (y == 0) {
		f[x][t] = ++tot;
		memset(f[tot], 0, sizeof(f[tot]));
		mark[tot] = 0;
		y = tot;
	}
	add(y, s + 1);
}

void dfs(int x, int& ans, int s) {
	ans += s * mark[x];
	int mnch = 0;
	int flag = 0;
	for (int i = 0; i < 26; ++i)
		if (f[x][i])
			++mnch;
	if (mnch > 1 || mark[x] || !x)
		flag = 1;
	for (int i = 0; i < 26; ++i)
		if (f[x][i])
			dfs(f[x][i], ans, s + flag);
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while (scanf("%d", &n) == 1) {
		tot = 0;
		memset(f[0], 0, sizeof(f[0]));
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			add(0,str);
		}
		int ans = 0;
		dfs(0, ans, 0);
		cout << fixed << setprecision(2) << (((double)ans) / ((double)n)) << '\n';
	}
	return 0;
}