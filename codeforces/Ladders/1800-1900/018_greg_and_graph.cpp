#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 509;

lli mat[MAXN][MAXN];
int arr[MAXN];
int blocked[MAXN];
lli ans[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		arr[i]--;
		blocked[arr[i]] = 1;
	}

	vector<lli> ans(N);
	for (int i = N - 1; i >= 0; --i) {
		blocked[arr[i]] = 0;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				mat[j][k] = min(mat[j][k], mat[j][arr[i]] + mat[arr[i]][k]);
			}	
		}
		lli currans = 0;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (blocked[j]) continue;
				if (blocked[k]) continue;
				currans += mat[j][k];
			}	
		}
		ans[i] = currans;
	}

	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';

	return 0;
}