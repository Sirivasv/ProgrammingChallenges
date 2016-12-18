#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;
const int MAXN = 809;
const int INF = (int)1e9 << 1;
typedef pair<int, int> pii;
int N, S;
char mtr[MAXN][MAXN]; //matriz de carateres 
int mtrv[MAXN][MAXN], dist[MAXN][MAXN]; //(mtrv) matriz de los tiempos de las abejas -- (dist)visitasos de mecho 
pii dest, orig;
 
int dir_x[] = {0, 1, -1, 0};
int dir_y[] = {1, 0, 0, -1};
 
inline void HFill(queue<pii> Q) {
	while (!Q.empty()) {
		pii u = Q.front();
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int n_y = u.y + dir_y[i], n_x = u.x + dir_x[i];
			if ((n_y >= 0) && (n_y < N) && (n_x >= 0) && (n_x < N) && (mtrv[n_y][n_x] == INF) && (mtr[n_y][n_x] == 'G')) {
				mtrv[n_y][n_x] = mtrv[u.y][u.x] + 1;
				Q.push(pii(n_y, n_x));
 			}
		}
	}
}
 
inline bool Checa(int x) {
	//cout << "CHECANDO: " << x << '\n';
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) dist[i][j] = -1;
    queue<pii> Q;
	Q.push(orig);
	dist[orig.y][orig.x] = x * S;
	if (x >= mtrv[orig.y][orig.x]) return false;
	while (!Q.empty()) {
		pii u = Q.front();
		int currd = dist[u.y][u.x];
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int n_y = u.y + dir_y[i], n_x = u.x + dir_x[i];
			pii yx = pii(n_y, n_x);
			if (yx == dest) return true;
			//cout << (currd + 1)/S << " == " << mtrv[n_y][n_x] << '\n';
			if ((n_y >= 0) && (n_y < N) && (n_x >= 0) && (n_x < N) && (mtr[n_y][n_x] == 'G') && (dist[n_y][n_x] == -1) && (((currd + 1) / S) < mtrv[n_y][n_x])) {
				dist[n_y][n_x] = currd + 1;
				//cout << "p; " << n_y << n_x << '\n';
				Q.push(yx);
 			}
		}
	}
	return false;
}
 
inline int BusBin() {
	int ini = 0, fin = N * N, mid, ans = -1;
	while (ini <= fin) {
		mid = (ini + fin) >> 1;
		if (Checa(mid)) {
			ans = mid;
			ini = mid + 1;
		} else fin = mid - 1;
	}
	return ans;
}
 
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &S);
		queue<pii> hives;
		for (int i = 0; i < N; ++i) {
			scanf("%s", mtr[i]);
			for (int j = 0; j < N; ++j) {
				mtrv[i][j] = INF;
				if (mtr[i][j] == 'H') {
					hives.push(pii(i,j));
					mtrv[i][j] = 0;
				} else if (mtr[i][j] == 'M') { 
					orig = pii(i,j); 
					mtr[i][j] = 'G'; 
				} else if (mtr[i][j] == 'D') dest = pii(i,j);
			}
		}
		HFill(hives);
		//for (int i = 0; i < N; ++i) {
		//for (int j = 0; j < N; ++j) if (mtrv[i][j] != INF)cout << mtrv[i][j] << "|";
		//else cout << "-1" << "|";
		//cout << '\n';
		//}
		printf("%d\n", BusBin());
	}
	return 0;
} 