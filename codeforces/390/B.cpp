#include <bits/stdc++.h>
using namespace std;

char mat[10][10];

bool IsWinner(int oi, int oj) {
	if (((oj - 2) >= 0)) {
		if ((mat[oi][oj - 1] == 'x') && (mat[oi][oj - 2] == 'x')) return true;
	}
	if (((oj - 1) >= 0) && ((oj + 1) < 4)) {
		if ((mat[oi][oj - 1] == 'x') && (mat[oi][oj + 1] == 'x')) return true;
	}
	if (((oj + 2) < 4)) {
		if ((mat[oi][oj + 1] == 'x') && (mat[oi][oj + 2] == 'x')) return true;
	}
	
	if (((oi - 2) >= 0)) {
		if ((mat[oi - 1][oj] == 'x') && (mat[oi - 2][oj] == 'x')) return true;
	}
	if (((oi - 1) >= 0) && ((oi + 1) < 4)) {
		if ((mat[oi - 1][oj] == 'x') && (mat[oi + 1][oj] == 'x')) return true;
	}
	if (((oi + 2) < 4)) {
		if ((mat[oi + 1][oj] == 'x') && (mat[oi + 2][oj] == 'x')) return true;
	}
	
	
	if (((oi + 2) < 4) && ((oj + 2) < 4)) {
		if ((mat[oi + 1][oj + 1] == 'x') && (mat[oi + 2][oj + 2] == 'x')) return true;
	}
	if (((oi - 1) >= 0) && ((oj - 1) >= 0) && ((oi + 1) < 4) && ((oj + 1) < 4)) {
		if ((mat[oi + 1][oj + 1] == 'x') && (mat[oi - 1][oj - 1] == 'x')) return true;
	}
	if (((oi - 2) >= 0) && ((oj - 2) >= 0)) {
		if ((mat[oi - 2][oj - 2] == 'x') && (mat[oi - 1][oj - 1] == 'x')) return true;
	}
	
	if (((oi + 2) < 4) && ((oj - 2) >= 0)) {
		if ((mat[oi + 1][oj - 1] == 'x') && (mat[oi + 2][oj - 2] == 'x')) return true;
	}
	if (((oi - 1) >= 0) && ((oj - 1) >= 0) && ((oi + 1) < 4) && ((oj + 1) < 4)) {
		if ((mat[oi + 1][oj - 1] == 'x') && (mat[oi - 1][oj + 1] == 'x')) return true;
	}
	if (((oi - 2) >= 0) && ((oj + 2) < 4)) {
		if ((mat[oi - 2][oj + 2] == 'x') && (mat[oi - 1][oj + 1] == 'x')) return true;
	}
	
	return false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) cin >> mat[i][j];
	
	int ok = 0;
	
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if ((mat[i][j] == '.') && (IsWinner(i, j)))
				ok = 1;
			
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}