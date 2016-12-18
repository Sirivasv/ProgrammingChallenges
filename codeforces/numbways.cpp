#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 500009;

lli arr[MAXN];

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int pt1 = i, pt3 = N;
		if (pt3 - 1) <= pt1)
			continue;
		int res, ini = i + 1, fin = N - 1;
		while (ini <= fin) {
			int m = (ini + fin) >> 1;
		}
	}
	return 0;
}