#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

vector<int> ans[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N; 
	
	int NN = N * N;
	int lim = NN / 2;
	
	for (int i = 1; i <= lim; ++i) {
		ans[((i - 1) % N)].push_back(i);
		ans[((i - 1) % N)].push_back(NN + 1 - i);
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			if (j) cout << ' ';
			cout << ans[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}