#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;

char mtr[MAXN][MAXN];

int main() {
	int N, M;
	cin >> N >> M;
	set<int> fil, col;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j) {
			cin >> mtr[i][j];
			if (mtr[i][j] == 'S') {
				fil.insert(i);
				col.insert(j);
			}
		}
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if ((mtr[i][j] == '.') && ((fil.find(i) == fil.end()) || (col.find(j) == col.end())))
				ans++;
	cout << ans << '\n';
	return 0;
}