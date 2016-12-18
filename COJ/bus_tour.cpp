#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
 
using namespace std;
 
const int max_n = 20, max_s = 1 << (max_n - 2);
 
int t, n, m, n_ones[max_s], g[max_n][max_n], dis1[max_s][max_n], dis2[max_s][max_n];
 
void pre_compute() {
    for (int i = 0; i < max_s; ++i) {
        n_ones[i] = 0;
        for (int j = i; j != 0; j &= j - 1)
            ++n_ones[i];
    }
}
 
void update(int &val, int v) {
    if (val == -1 || v < val)
        val = v;
}
 
void compute_distance(int src, int dis[max_s][max_n]) {
    dis[0][src] = 0;
    for (int i = 0; i < (1 << (n - 2)); ++i) {
        if (n_ones[i] * 2 >= n - 2)
            continue;
        for (int j = 0; j < n; ++j) {
            if (dis[i][j] == -1)
                continue;
            for (int k = 0; k < n - 2; ++k) {
                if (((i >> k) & 1) == 1)
                    continue;
                update(dis[i | (1 << k)][k + 1], dis[i][j] + g[j][k + 1]);
            }
        }
    }
}
 
int get_min_time() {
    for (int i = 0; i < n; ++i)
        g[i][i] = 0;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    memset(dis1, -1, sizeof(dis1));
    compute_distance(0, dis1);
    memset(dis2, -1, sizeof(dis2));
    compute_distance(n - 1, dis2);
    int res = INT_MAX;
    for (int i = 0; i < (1 << (n - 2)); ++i) {
        if (n_ones[i] != (n - 2) / 2)
            continue;
        int s1 = i, s2 = ((1 << (n - 2)) - 1) ^ s1, t1 = INT_MAX, t2 = INT_MAX;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (dis1[s1][j] != -1 && dis2[s2][k] != -1)
                    t1 = min(t1, dis1[s1][j] + g[j][k] + dis2[s2][k]);
                if (dis2[s1][j] != -1 && dis1[s2][k] != -1)
                    t2 = min(t2, dis2[s1][j] + g[j][k] + dis1[s2][k]);
            }
        }
        res = min(res, t1 + t2);
    }
    return res;
}
 
bool solve() {
    if (scanf("%d%d", &n, &m) == EOF)
        return false;
    memset(g, 0x0F, sizeof(g));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = c;
    }
    printf("Case %d: %d\n", ++t, get_min_time());
    return true;
}
 
int main() {
    pre_compute();
    while (solve());
    return 0;
}