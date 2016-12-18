#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

int arr[MAXN];

int Abs(int x) {
	return (x < 0)? -x : x;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		for (int i = 0; i < N; ++i) 
			cin >> arr[i];
		sort(arr, arr + N);
		int mint = (1 << 30);
		int sum = 0;
		for (int i = 1; i < N; i += 2)
			sum += min(24 - Abs(arr[i] - arr[i - 1]), Abs(arr[i] - arr[i - 1]));
		mint = min(mint, sum);
		sum = min(Abs(arr[0] - arr[N - 1]), 24 - Abs(arr[0] - arr[N - 1]));
		for (int i = 2; i < (N - 1); i += 2)
			sum += min(24 - Abs(arr[i] - arr[i - 1]), Abs(arr[i] - arr[i - 1]));
		mint = min(mint, sum);
		cout << mint << '\n';
	}
	return 0;
}
