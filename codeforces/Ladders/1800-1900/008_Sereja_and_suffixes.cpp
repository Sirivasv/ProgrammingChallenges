//Div2 B - Estructuras
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100009;

int arr[MAX_N];
int ans[MAX_N];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	set<int> numbs;
	for (int i = N - 1; i >= 0; --i) {
		numbs.insert(arr[i]);
		ans[i + 1] = numbs.size();
	}
	for (int i = 0; i < M; ++i) {
		int q;
		cin >> q;
		cout << ans[q] << '\n';
	}
	return 0;
}