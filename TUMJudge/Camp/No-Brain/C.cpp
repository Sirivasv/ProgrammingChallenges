#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long mats = 0;
	for (int i = 0; i < N; ++i) {
		long long aux;
		cin >> aux;
		mats = max(aux, mats);
	}
	cout << (mats * mats * mats) << '\n';
	return 0;
}