#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		if (arr[i] != i)
			ans++;
	cout << ans << '\n';
	return 0;
}