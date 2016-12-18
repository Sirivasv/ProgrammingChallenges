#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

char mtr[MAXN][MAXN];
char oris[] = {'N', 'L', 'S', 'O'};
int N, M, NS;

bool Valid(int xi, int yi) {
	if (((xi >= 0 ) && (xi < M)) && ((yi >= 0 ) && (yi < N)) && (mtr[yi][xi] != '#'))
		return true;
	return false;
}

bool IsOr(char c) {
	for (int i = 0 ; i < 4; ++i)
		if (c == oris[i])
			return true;
	return false;
}

int main() {
	while (cin >> N >> M >> NS) {
		if ((N + M + NS) == 0)
			break;
		
		int xi = 0, yi  = 0, idori = 0;
		char curori;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j  < M; ++j) {
				cin >> mtr[i][j];
				if (IsOr(mtr[i][j])) {
					if (mtr[i][j] == 'N')
						idori = 0;
					else if (mtr[i][j] == 'L')
						idori = 1;
					else if (mtr[i][j] == 'S')
						idori = 2;
					else 
						idori = 3;
					xi = j;
					yi = i;
					mtr[i][j] = '.';
				}
			}
		}
		
		string s;
		cin >> s;
		int ans = 0;
		
		for (int i = 0; i < s.size(); ++i) {
			curori = oris[idori];
			
			//cout << curori << ' ' << yi << ' ' << xi << '\n';
			if (s[i] == 'D') {
				idori = (idori + 1) % 4;
				curori = oris[idori];
			} else if (s[i] == 'F') {
				int nx = xi, ny = yi;
				if (curori == 'N') {
					ny = yi - 1;
				} else if(curori == 'S') {
					ny = yi + 1;
				} else if (curori == 'L') {
					nx = xi + 1;
				} else {
					nx = xi - 1;
				}
				
				if (!Valid(nx, ny))
					continue;
				xi = nx;
				yi = ny;
				if (mtr[yi][xi] == '*') {
					ans++;
					mtr[yi][xi] = '.';
				}
			} else {
				idori = (idori - 1 + 4) % 4;
				curori = oris[idori];
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}