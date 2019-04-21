#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
const int MINF = -100000;

int memo[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
int ID, N;
string s;

int DP (int id, int mna, int ln) {

    if (id == N) {
        if (mna > (ln >> 1)) return 0;
        return MINF;
    }

    if (vis[id][mna][ln] == ID) return memo[id][mna][ln];
    vis[id][mna][ln] = ID;

    int maxt = DP(id + 1, mna, ln);
    maxt = max(maxt, DP(id + 1, mna + (s[id] == 'a'), ln + 1) + 1);

    return memo[id][mna][ln] = maxt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> s;
    N = s.size();

    ID++;
    cout << DP(0, 0, 0) << '\n';

    return 0;
}