#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arr[MAXN];

int Abs(int x) {
	return (x < 0)? -x: x;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + N);
	int lim = N - 1;
	int val = sum / N;
	if ((sum % N) != 0)
		lim = (N - (sum % N)) - 1;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += Abs(arr[i] - val);
		if (i == lim)
			val++;
	}
	ans >>= 1;
	cout << ans << '\n';
	return 0;
}