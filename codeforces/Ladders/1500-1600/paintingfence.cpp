#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int H[MAXN];

int RF(int l, int r, int h) {
	if (l > r)
		return 0;
	int minv = 1000010000, idm;
	for (int i = l; i <= r; ++i) {
		if (H[i] < minv) {
			minv = H[i];
			idm = i;
		}
	}
	return min(r - l + 1, RF(l, idm - 1, minv) + RF(idm + 1, r, minv) + minv - h);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> H[i];
	cout << RF(0, N - 1, 0) << '\n';
	return 0;
}