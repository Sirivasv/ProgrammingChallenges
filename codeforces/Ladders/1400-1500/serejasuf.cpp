#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int ans[MAXN], arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	set<int> din;
	for (int i = N; i > 0; --i) {
		din.insert(arr[i]);
		ans[i] = din.size();
	}
	for (int i = 0; i < M; ++i) {
		int qi;
		cin >> qi;
		cout << ans[qi] << '\n';
	}
	return 0;
}