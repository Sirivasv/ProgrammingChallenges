#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 30;
const int MAXNN = 900;

vector<int> graph[MAXNN];
int vis[MAXNN];
vector<int> res_vec;

int R, C;

int try_path(int ori){

    for (int i = 0; i < MAXNN; ++i) {
        vis[i] = 0;
    }
    
    // run_path(ori);

    for (int i = 0; i < MAXNN; ++i) {
        if(!vis[i]) return 0;
    }
    return 1;
}

pii coord_from_id(int zi) {
    int yi = zi / C;
    int xi = zi - (yi * C);
    return pii(xi, yi);
}

inline int id_from_coord(int xi, int yi) {
    return xi + (yi * C);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int total_cases;
    cin >> total_cases;
    for (int no_case = 1; no_case <= total_cases; ++no_case) {

        cin >> R >> C;

        int LIMN = R*C;
        for (int i = 0; i < MAXNN; ++i) {
            graph[i].clear();
        }

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {

                for (int ni = 0; ni < R; ++ni) {
                    for (int nj = 0; nj < C; ++nj) {
                    
                        if (i == ni) continue;
                        if (j == nj) continue;
                        if ((i - j) == (ni - nj)) continue;
                        if ((i + j) == (ni + nj)) continue;

                        int u = id_from_coord(j, i);
                        int v = id_from_coord(nj, ni);
                        graph[u].push_back(v);
                        graph[v].push_back(u);

                    }
                }
            }
        }

        int found = 0;
        for (int i = 0; i < LIMN; ++i) {
            if (try_path(i)) {
                found = 1;
                break;
            }
        }


        if (!found) {
            cout << "Case #" << no_case << ": IMPOSSIBLE\n";
            continue;
        }
        cout << "Case #" << no_case << ": POSSIBLE\n";
        int limi = res_vec.size();
        for (int i = 0; i < limi; ++i) {
            pii curr_c = coord_from_id(res_vec[i]);
            cout << curr_c.first << ' ' << curr_c.second << '\n';
        }
    }

    return 0;
}