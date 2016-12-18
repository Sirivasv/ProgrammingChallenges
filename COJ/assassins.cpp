#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int T, N, A[MAXN], order[MAXN], taken[MAXN];

void TakeNxt(int x) {
	while (taken[x++]);
	taken[x] = 1;
	return;
}

int Cuenta() {
	for (int i = 0; i < N; ++i) order[i] = i;
	int cnt = 0;
	do {
		for (int i = 0; i < N; ++i) taken[i] = 0;
		for (int i = 0; i < N; ++i) {
			if (taken[A[order[i]]]) {
				TakeNxt(A[order[i]]);
			} else {
				taken[A[order[i]]] = 1;
				if (order[i] == 0) cnt++;
			}
		}
	} while(next_permutation(order, order + N));
	return cnt;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; ++i) cin >> A[i];
		cout << Cuenta() << '\n';
	}
	return 0;
}