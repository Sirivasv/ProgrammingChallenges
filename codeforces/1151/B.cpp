#include <bits/stdc++.h>
using namespace std;

const int MAXN = 509;

int N, M;
int mat[MAXN][MAXN];
unordered_map<int, int> memo[MAXN];
vector<int> ans_v;

int DP(int rw, int xr) {
    if (memo[rw].count(xr)) return memo[rw][xr];
    if (rw == N) return (xr > 0)?(1):(0);

    int possible = 0;
    for (int i = 0; i < M; ++i) {
        if (DP(rw + 1, xr ^ mat[rw][i])) {
            possible = 1;
            break;
        }
    }

    return memo[rw][xr] = possible;
}

void REDP(int rw, int xr) {
    if (rw == N) return;
    for (int i = 0; i < M; ++i) {
        if (DP(rw + 1, xr ^ mat[rw][i])) {
            ans_v.push_back(i + 1);
            REDP(rw + 1, xr ^ mat[rw][i]);
            break;
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mat[i][j];
        }
    }
    if (DP(0, 0)) {
        REDP(0, 0);
        cout << "TAK\n";
        int limi = ans_v.size();
        for (int i = 0; i < limi; ++i) {
            if (i) cout << ' ';
            cout << ans_v[i];
        }
        cout << '\n';
    } else {
        cout << "NIE\n";
    }
    return 0;
}