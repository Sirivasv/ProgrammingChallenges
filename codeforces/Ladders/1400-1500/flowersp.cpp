#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int mint = 1000000009, mats = -1;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		mint = min(mint, arr[i]);
		mats = max(mats, arr[i]);
	}
	long long a = 0, b	= 0;
	for (int i = 0; i < N; ++i) {
		if (arr[i] == mint)
			a++;
		else if (arr[i] == mats)
			b++;
	}
	
	cout << (mats - mint) << ' ';
	
	if (mint == mats) {
		cout << ((a * (a - 1LL)) / 2LL) << '\n';
	} else
		cout << (a * b) << '\n';
	return 0;
}