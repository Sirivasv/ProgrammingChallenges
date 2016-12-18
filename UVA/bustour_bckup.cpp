#include <bits/stdc++.h>
using namespace std;
const int MAXN = 21;
const int INF = 1000000000;
int N, M, nc, a, b, c, adjmtr[MAXN][MAXN];
int memo[1 << MAXN][MAXN], lim = (1 << MAXN), redp, ln;

inline void Limpia(){
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) adjmtr[i][j] = INF;
		for (int j = 0; j <= lim; ++j) memo[j][i] = 0; 
	}
}

inline void CalcDist() {
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				adjmtr[i][j] = min(adjmtr[i][j], adjmtr[i][k] + adjmtr[k][j]);
}

inline int ishalf(int X) {
	int fh = N >> 1, cnt = 0;
	while (X) {
		cnt += X & 1;
		X >>= 1;
	}
	return (fh == cnt);
}

inline int FHDP(int mask, int nodo) {
	if (memo[mask][nodo]) return memo[mask][nodo];
	if (ishalf(mask)) return 0;
	int ans = INF;
	for (int i = 1; i < N - 1; ++i)
		if ((!(mask & (1 << i))) && (adjmtr[nodo][i] != INF)) {
			int val = ((mask == 1)?(adjmtr[N - 1][i]):(0));
			ans = min(FHDP(mask | (1 << i), i) + adjmtr[nodo][i] + val, ans);
		}
	return memo[mask][nodo] = ans;
}

inline int isallh(int x) {
	for (int i = 0; i < N - 1; ++i) if (!(x & (1 << i))) return 0;
	return 1;
}

inline int LHDP(int mask, int nodo) {
	if (memo[mask][nodo]) return memo[mask][nodo];
	if (isallh(mask)) return 0;
	int ans = INF;
	for (int i = 1; i < N - 1; ++i)
		if ((!(mask & (1 << i))) && (adjmtr[nodo][i] != INF))
			ans = min(LHDP(mask | (1 << i), i) + adjmtr[nodo][i], ans);
	return memo[mask][nodo] = ans;
}

inline void RRDP(int mask, int nodo) {
	if (isallh(mask)) return;
	int ans = INF, idmin, aux;
	for (int i = 1; i < N - 1; ++i)
		if (!(mask & (1 << i))) {
			aux = LHDP(mask | (1 << i), i) + adjmtr[nodo][i];
			if (aux < ans) {
				ans = aux;
				idmin = i;
			}
		}
	if (idmin != -1) {
		ln = idmin;
		RRDP(mask | (1 << idmin), idmin);
	}
	return;
}


inline void RDP(int mask, int nodo) {
	if (ishalf(mask)) return;
	int ans = INF, idmin = -1;
	for (int i = 1; i < N - 1; ++i)
		if ((!(mask & (1 << i))) && (adjmtr[nodo][i] != INF)) {
			int val = ((mask == 1)?(adjmtr[N - 1][i]):(0));
			int aux = FHDP(mask | (1 << i), i) + adjmtr[nodo][i] + val;
			if (aux < ans) {
				ans = aux;
				idmin = i;
			}
		}
	if (idmin != -1) {
		redp |= (1 << idmin);
		ln = idmin;
		RDP(mask | (1 << idmin), idmin);
	}
	return;
}
int main() {
	while (cin >> N) {
		cin >> M;
		Limpia();
		for (int i = 0; i < M; ++i) {
			cin >> a >> b >> c;
			adjmtr[a][b] = c;
			adjmtr[b][a] = c;
		}
		CalcDist();
		for (int i = 0; i < N; ++i,  cout << '\n')
			for (int j = 0; j < N; ++j) cout << adjmtr[i][j] << ' ';
		int fhalf = FHDP(1, 0);
		cout << " MinHalfDist: " << fhalf << '\n';
		redp = 1;
		RDP(1, 0);
		cout << " Mask in best half " << redp << '\n';
		cout << " Last hotel to be visited: " << ln << '\n';
		int resth = LHDP(redp, ln);
		cout << " REST of hotels: " << resth << '\n'; 
		RRDP(redp, ln);
		cout << " Last hotel to be re - visited: " << ln << '\n';
		if (N == 3) cout << "Case " << ++nc << ": " << (resth << 1) + fhalf + adjmtr[ln][N - 1] + adjmtr[ln][N - 1] << '\n';
		else cout << "Case " << ++nc << ": " << (resth << 1) + fhalf + adjmtr[ln][0] + adjmtr[ln][N - 1] << '\n';
	}
	return 0;
}