#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

string pal[MAXN];
int IsDead[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
		cin >> pal[i];
	
	int ans = 0;
	for (; ;) {
		int ok = 1;
		int pos = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (pal[i] <= pal[j])
					continue;
				for (int k = 0; k < M; ++k) {
					if (pal[i][k] > pal[j][k]) {
						pos = k;
						ok = 0;
						break;
					}
				}
			}
			if (!ok) {
				for (int i = 0; i < N; ++i)
					pal[i][pos] = '*';
				ans++;
				break;
			}
		}
		if (ok)
			break;
	}
	cout << ans << '\n';
	return 0;
}