#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

int N, M;
string pala[MAXN];

int dir_x[] = {1, 0, -1, 0};
int dir_y[] = {0, -1, 0, 1};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) cin >> pala[i];

	int Tcnt = 0;

	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j) {
			if (pala[i][j] == '+') {
				int cnt = 0;
				for (int k = 0; k < 4; ++k) {
					int ny = i + dir_y[k]; 
					int nx = j + dir_x[k];
					if (((ny < N) && (ny >= 0)) && ((nx < M) && (nx >= 0))) {
						if (pala[ny][nx] == '-') cnt = 1;
					}
				}
				if (cnt) Tcnt++;
			}
		}
	cout << Tcnt << '\n';
	return 0;
}