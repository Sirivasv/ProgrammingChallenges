#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int mtr[MAXN][MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, Q;
	cin >> N >> M >> Q;
	map<int, int> fils, cols;
	for (int i = 0; i < N; ++i) {
		fils[i] = i;
		for (int j = 0; j < M; ++j) {
			cols[j] = j;
			cin >> mtr[i][j];
		}
	}
	for (int i = 0; i < Q; ++i) {
		char op;
		int I, J;
		cin >> op >> I >> J;
		I--; J--;
		if (op == 'c')
			swap(cols[I], cols[J]);
		else if (op == 'r')
			swap(fils[I], fils[J]);
		else
			cout << mtr[fils[I]][cols[J]] << '\n';
	}
	return 0;
}