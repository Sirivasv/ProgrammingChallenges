#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int N;

string mtr[MAXN];

int dir_x[] = {-1, 0, 1};
int dir_y[] = {0, 1, 0};

int checkCross(int yi, int xi) {
	mtr[yi][xi] = '.';
	yi++;
	
	if (yi >= N) return 0;
	
	if (mtr[yi][xi] == '.') return 0;
	else mtr[yi][xi] = '.';

	for (int i = 0; i < 3; ++i) {
		int nx = xi + dir_x[i];
		int ny = yi + dir_y[i];
		if ((nx >= N) || (nx < 0) || (ny >= N) || (ny < 0)) return 0;
		if (mtr[ny][nx] == '.') return 0;
		else mtr[ny][nx] = '.'; 
	}

	return 1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; ++i) cin >> mtr[i];

	int ans = 1;

	for (int i = 0; ((i < N) && (ans)); ++i)
		for (int j = 0; ((j < N) && (ans)); ++j)
			if (mtr[i][j] == '#') ans = checkCross(i, j);

	cout << ((ans)?("YES"):("NO")) << '\n';

	return 0;
}