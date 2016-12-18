#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 5009;
int memo[MAXN][MAXN], arr[MAXN];
pii A[MAXN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		for (int i = 1; i <= N; ++i) {
			cin >> A[i].first;
			arr[i] = A[i].first;
			A[i].second = i;
		}
		for (int i = 0; i <= N; ++i)
			for (int j = 0; j <= N; ++j) memo[i][j] = 0;
		sort(A + 1, A + N + 1);
		for (int k = 1; k <= N; ++k) {
			int i = A[k].second;
			for (int j = i - 1; j >= 1; --j) 
				memo[i][j] = max((arr[i] > arr[j])?(1 + memo[j][i - 1]):0, memo[i][j + 1]);
			for (int j = i + 1; j <= N; ++j) 
				memo[i][j] = max((arr[i] > arr[j])?(1 + memo[j][i + 1]):0, memo[i][j - 1]);
		}
		for (int i = 1; i <= N; ++i) {
			int ans = 0;
			for (int j = 1; j <= N; ++j) ans = max(ans, memo[i][j]);
			cout << ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}