#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		int sum = 0;
		for (int j = 0; j < N; ++j) {
			cin >> arr[j];
			sum += arr[j];
		}
		int eval = sum / N;
		sort(arr, arr + N);
		int acum = 0;
		for (int j = 0; j < N; ++j) {
			acum += (arr[j] - eval);
		}
		if (acum) cout << N - 1 << '\n';
		else cout << N << '\n';
	}

	return 0;
}