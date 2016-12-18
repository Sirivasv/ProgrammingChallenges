#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

vector<int> vi[MAXN];

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	int ini = 1, fin = N, ans = N;
	while (ini <= fin) {
		int m = (ini + fin) / 2;
		int ok = 1;
		for (int i = 0; i < N; ++i)
			if ((i / m) > arr[i])
				ok = 0;
		if (ok) {
			ans = m;
			fin = m - 1;
		} else ini = m + 1;
	}
	cout << ans << '\n';
	return 0;
}