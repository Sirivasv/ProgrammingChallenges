#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int INF = 1000000000;
int N, M, nc, a, b, c, adjmtr[MAXN][MAXN];
int memo[1 << MAXN][MAXN], lim = (1 << MAXN);
int memo2[1 << MAXN][MAXN], memo3[1 << MAXN][MAXN]; 

inline void Limpia(){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) adjmtr[i][j] = INF;
        for (int j = 0; j < (1 << N); ++j) memo[j][i] = memo2[j][i] = memo3[j][i] = 0; 
    }
}

inline void CalcDist() {
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                adjmtr[i][j] = min(adjmtr[i][j], adjmtr[i][k] + adjmtr[k][j]);
}

inline int isallh(int x) {
    for (int i = 0; i < N - 1; ++i) if (!(x & (1 << i))) return 0;
    return 1;
}

inline int ishalf(int X) {
    int fh = N >> 1, cnt = 0;
    while (X) {
        cnt += X & 1;
        X >>= 1;
    }
    return (fh == cnt);
}

inline int LHDP(int mask, int nodo) {
    if (memo2[mask][nodo]) return memo2[mask][nodo];
    if (isallh(mask)) return adjmtr[nodo][0];
    int ans = INF;
    for (int i = 1; i < N - 1; ++i)
        if (!(mask & (1 << i))) ans = min(LHDP(mask | (1 << i), i) + adjmtr[nodo][i], ans);
    return memo2[mask][nodo] = ans;
}

inline int LLHDP(int mask, int nodo) {
    if (memo3[mask][nodo]) return memo3[mask][nodo];
    if (isallh(mask)) return adjmtr[nodo][N - 1];
    int ans = INF;
    for (int i = 1; i < N - 1; ++i)
        if (!(mask & (1 << i))) ans = min(LLHDP(mask | (1 << i), i) + adjmtr[nodo][i], ans);
    return memo3[mask][nodo] = ans;
}

inline int FHDP(int mask, int nodo) {
    if (memo[mask][nodo]) return memo[mask][nodo];
    if (ishalf(mask)) return LHDP(mask, nodo) + LLHDP(mask, nodo);
    int ans = INF;
    for (int i = 1; i < N - 1; ++i)
        if (!(mask & (1 << i))) {
            int val = ((mask == 1)?(adjmtr[N - 1][i] + adjmtr[nodo][i]):(adjmtr[nodo][i] << 1));
            ans = min(FHDP(mask | (1 << i), i) + val, ans);
        }
    return memo[mask][nodo] = ans;
}

int main() {
    while (cin >> N) {
        cin >> M;
        Limpia();
        for (int i = 0; i < M; ++i) {
            cin >> a >> b >> c;
            adjmtr[a][b] = min(adjmtr[a][b], c);
            adjmtr[b][a] = adjmtr[a][b];
        }
        CalcDist();
        //for (int i = 0; i < N; ++i,  cout << '\n')
            //for (int j = 0; j < N; ++j) cout << adjmtr[i][j] << ' ';
        if (N == 3) cout << "Case " << ++nc << ": " << (adjmtr[1][0] << 1) + (adjmtr[1][N - 1] << 1) << '\n';
        else cout << "Case " << ++nc << ": " <<  FHDP(1, 0)<< '\n';
    }
    return 0;
}