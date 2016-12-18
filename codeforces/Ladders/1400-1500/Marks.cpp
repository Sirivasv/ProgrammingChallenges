#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int mats[MAXN], ans[MAXN]; 
string s[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		mats[i] = -1;
	for (int j = 0; j < N; ++j) {
		cin >> s[j];
		for (int i = 0; i < M; ++i)
			mats[i] = max(mats[i], s[j][i] - '0');
	}
	int res = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if ((s[i][j] - '0') == mats[j]) {
				res++;
				break;
			}
		}
	}
	cout << res << '\n';
	return 0;
}