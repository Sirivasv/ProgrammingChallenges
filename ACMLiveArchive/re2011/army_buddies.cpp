#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
int le[MAXN], ri[MAXN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N, M;
	while (cin >> N >> M) {
		if (!(N + M))
			break;
		le[1] = 0;
		ri[1] = 2;
		for (int i = 2; i <= N; ++i) {
			le[i] = i - 1;
			ri[i] = i + 1;
		}
		ri[N] = 0;
		
		int L, R;
		
		while (M--) {
			cin >> L >> R;
			ri[le[L]] = ri[R];
			le[ri[R]] = le[L];
			
			if (!le[L])
				cout << "* ";
			else
				cout << le[L] << ' ';
			
			if (!ri[R])
				cout << "*\n";
			else
				cout << ri[R] << '\n';
			
		}
		
		cout << "-\n";
	}
	return 0;
}