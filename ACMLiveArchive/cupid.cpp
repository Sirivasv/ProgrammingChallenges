#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

int arr[MAXN];

int main() {
	int N;
	while (cin >> N) {
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		int minl = 0;
		for (int i = 0; i < N; i += 2) {
			minl += min(fabs(arr[i] - arr[i + 1]), 24.0 - fabs(arr[i] - arr[i + 1]));
		}
		int minr = min(fabs(arr[0] - arr[N - 1]), 24.0 - fabs(arr[0] - arr[N - 1]));
		int lim = N - 1;
		for (int i = 1; i < lim; i += 2) {
			minr += min(fabs(arr[i] - arr[i + 1]), 24.0 - fabs(arr[i] - arr[i + 1]));
		}
		cout << min(minr, minl) << '\n';
	}
	return 0;
}