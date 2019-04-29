#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300009;

vector<int> graph[MAXN];
int op[MAXN], dp[MAXN];
int N, k;

void DFS(int u, int p = -1){
    if ((u > 1) && (graph[u].size() == 1)) {
        k++;
        dp[u] = 1;
        return;
    }
    if (op[u]) dp[u] = 1000000;
    else dp[u] = 0;
    for (int v: graph[u]) {
        if (v == p) continue;
        DFS(v, u);
        if (op[u]){
            if (dp[v] < dp[u]) dp[u] = dp[v];
        } else dp[u] += dp[v];
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> op[i];
    for (int i = 2; i <= N; ++i) {
        int f;
        cin >> f;
        graph[f].push_back(i);
        graph[i].push_back(f);
    }
    DFS(1);
    cout << (k + 1 - dp[1]) << '\n';
    return 0;
}