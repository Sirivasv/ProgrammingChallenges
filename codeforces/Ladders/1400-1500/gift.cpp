#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i <= N; ++i) {
		for (int j = i; j < N; ++j)
			cout << ' ' << ' ';
		for (int j = 0; j <= i; ++j) {
			if (j)
				cout << ' ';
			cout << j;
		}
		for (int k = 0; k < i; ++k) {
			cout << ' ';
			cout << (i - 1 - k);
		}
		cout << '\n';
	}
	for (int i = N - 1; i >= 0; --i) {
		for (int j = i; j < N; ++j)
			cout << ' ' << ' ';
		for (int j = 0; j <= i; ++j) {
			if (j)
				cout << ' ';
			cout << j;
		}
		for (int k = 0; k < i; ++k) {
			cout << ' ';
			cout << (i - 1 - k);
		}
		cout << '\n';
	}
	return 0;
}