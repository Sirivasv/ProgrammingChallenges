#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 505;
const lli INF = (1LL << 62);

lli mat[MAXN][MAXN], ans[MAXN];
int rlist[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> mat[i][j];
	
	for (int i = 0; i < N; ++i) { 
		cin >> rlist[i];
		rlist[i]--;
	}
	
	reverse(rlist, rlist + N);
	
	for (int i = 0; i < N; ++i) {
		
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				mat[j][k] = min(mat[j][k], mat[j][rlist[i]] + mat[rlist[i]][k]);
				
		lli res = 0;
		for (int j = 0; j <= i; ++j)
			for (int k = 0; k <= i; ++k)
				res += mat[rlist[j]][rlist[k]];
		
		ans[N - 1 - i] = res;
		
	}
	
	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
	
	return 0;
}