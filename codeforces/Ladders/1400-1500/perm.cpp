#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400000;

typedef long long lli;

int arr[MAXN];

lli Abs(int x) { return ((x < 0)?(-x):(x)); }

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	lli ans = 0;
	for (int i = 1; i <= N; ++i)
		ans += Abs(i - arr[i - 1]);
	cout << ans << '\n';
	return 0;
}