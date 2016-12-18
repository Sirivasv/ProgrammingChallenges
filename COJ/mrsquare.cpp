#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;

char mtr[MAXN][MAXN];

int dir_x[] = {1, -1, 0, 0};
int dir_y[] = {0, 0, 1, -1};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> mtr[i][j];
		int ok = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < 4; ++k) {
					int ni = i + dir_y[k];
					int nj = j + dir_x[k];
					if ((((ni >= 0) && (ni < N)) && ((nj >= 0) && (nj < N))) && (mtr[i][j] == mtr[ni][nj]))
						ok = 0;
				}
			}
		}
		cout << ((ok)?("YES\n"):("NO\n"));
	}
	return 0;
}