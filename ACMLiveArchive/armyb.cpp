#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int lef[MAXN], rig[MAXN];

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int N, Q;
	while (cin >> N >> Q) {
		if (! (N || Q))
			break;
		
		lef[1] = -1; 
		for (int i = 2; i <= N; ++i)
			lef[i] = (i - 1);
		
		rig[N] = -1;
		for (int i = 1; i < N; ++i)
			rig[i] = (i + 1);
		
		for (int i = 0; i < Q; ++i) {
			int I, J;
			cin >> I >> J;
			
			if (rig[J] != -1)
				lef[rig[J]] = lef[I];
			if (lef[I] != -1)
				rig[lef[I]] = rig[J];
			
			if (lef[I] == -1)
				cout << "*";
			else
				cout << lef[I];
			cout << ' ';
			if (rig[J] == -1)
				cout << "*";
			else
				cout << rig[J];
			cout << '\n';
		}
		cout << "-\n";
	}
	return 0;
}