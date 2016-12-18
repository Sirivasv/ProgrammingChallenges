#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int mats = -1;
	int currv = 0;
	for (int i = 0; i < N; ++i) {
		int b, e;
		cin >> b >> e;
		currv -= b;
		currv += e;
		mats = max(mats, currv);
	}
	cout << mats << '\n';
	return 0;
}