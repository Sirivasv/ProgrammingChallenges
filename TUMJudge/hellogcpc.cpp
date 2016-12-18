#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);	ios_base::sync_with_stdio(0);
	long long mats = 0;
	int N;
	cin >> N;
	long long aux;
	for (int i = 0; i < N; ++i) {
		cin >> aux;
		mats = max(mats, aux);
	}
	cout << (mats * mats * mats) << '\n';
	return 0;
}