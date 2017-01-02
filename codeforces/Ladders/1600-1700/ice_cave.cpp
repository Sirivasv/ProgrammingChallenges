#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 505;

int N, M;

int dir_x[] = {1, -1, 0, 0};
int dir_y[] = {0, 0, 1, -1};

string mat[MAXN];

int vis[MAXN][MAXN];

bool FindBFS(int oy, int ox, int ey, int ex) {
	vis[oy][ox] = 1;
	queue<pii> Q;
	Q.push(pii(oy, ox));
	while (!Q.empty()) {
		int uy = Q.front().first, ux = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int vy = uy + dir_y[i], vx = ux + dir_x[i];
			if ((vy < N) && (vy >= 0) && (vx >= 0) && (vx < M)) {
				if ((vy == ey) && (vx == ex)) {
					if (mat[vy][vx] == 'X') return true;
					for (int j = 0; j < 4; ++j) {
						int ny = vy + dir_y[j], nx = vx + dir_x[j];
						if (((ny < N) && (ny >= 0) && (nx >= 0) && (nx < M)) && (mat[ny][nx] == '.') && (!((nx == ux) && (ny == uy)))) 
							return true;
					}
					return false;
				}
				if ((!vis[vy][vx]) && (mat[vy][vx] == '.')) {
					vis[vy][vx] = 1;
					Q.push(pii(vy, vx));
				}
			}
		}
	}
	return false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) cin >> mat[i];
	
	int sty, stx, ey, ex;
	
	cin >> sty >> stx >> ey >> ex;
	
	sty--; stx--; ey--; ex--;
	
	if ((sty == ey) && (stx == ex)) {
		int ok = 0;
		for (int i = 0; i < 4; ++i) {
			int ny = sty + dir_y[i], nx = stx + dir_x[i];
			if (((ny < N) && (ny >= 0) && (nx >= 0) && (nx < M)) && (mat[ny][nx] == '.')) {
				ok = 1;
				break;
			}
		}
			cout << ((ok)?("YES\n"):("NO\n"));
		return 0;
	}
	
	cout << ((FindBFS(sty, stx, ey, ex))?("YES\n"):("NO\n"));
	
	return 0;
}