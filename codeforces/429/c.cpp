#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;
typedef pair<int, int> pii;
int arr[MAXN], ans[MAXN];
pii arrb[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i) {
		cin >> arrb[i].first;
		arrb[i].second = i;
	}
	sort(arrb, arrb + N);
	for (int i = 0; i < N; ++i) ans[arrb[i].second] = arr[N - 1 - i];
	for (int i = 0; i < N; ++i) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}