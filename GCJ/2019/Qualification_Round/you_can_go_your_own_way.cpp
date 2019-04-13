#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1005;

char memo[MAXN][MAXN];
char visited[MAXN][MAXN];
int ID, N, NM;
string taken_path_string;
map<pii, int> taken_path;

int getID(int xi, int yi) { 
    return (yi * N) + xi;
}

char DP(int xi, int yi) {
    if ((xi == NM) && (yi == NM)) return 1;
    if ((xi == N) || yi == N) return 0;
    if (visited[xi][yi] == ID) return memo[xi][yi];
    visited[xi][yi] = ID;
    char reached_limit = 0;
    if (!taken_path.count(pii(getID(xi, yi), getID(xi + 1, yi)))) {
        reached_limit = DP(xi + 1, yi);
    }
    if (!taken_path.count(pii(getID(xi, yi), getID(xi, yi + 1)))) {
        reached_limit |= DP(xi, yi + 1);
    }
    return memo[xi][yi] = reached_limit;
}

void RECONDP(int xi, int yi){

    if ((xi == NM) && (yi == NM)) return;
    int reached_limit = 0;
    if (!taken_path.count(pii(getID(xi, yi), getID(xi + 1, yi)))) {
        reached_limit = DP(xi + 1, yi);
        if (reached_limit) {
            cout << 'E';
            RECONDP(xi + 1, yi);
        }
    }
    if (!taken_path.count(pii(getID(xi, yi), getID(xi, yi + 1)))) {
        if (!reached_limit) {
            cout << 'S';
            RECONDP(xi, yi + 1);
        }
    }
    return;
}

void fill_taken_path(int xi, int yi, int pos_in_string) {
    if (pos_in_string == taken_path_string.length()) return;
    int nx, ny;
    if (taken_path_string[pos_in_string] == 'S') {
        nx = xi;
        ny = yi + 1;
    } else {
        nx = xi + 1;
        ny = yi;
    }
    // cout << getID(xi, yi) << ' ' << getID(nx, ny) << '\n';
    taken_path[pii(getID(xi, yi), getID(nx, ny))] = 1;
    fill_taken_path(nx, ny, pos_in_string + 1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int total_cases;
    cin >> total_cases;

    for (int i = 1; i <= total_cases; ++i) {
        taken_path.clear();
        ID++;
        cin >> N >> taken_path_string;
        NM = N - 1;
        // cout << i << ' ' << N << ' ' << NM << '\n';
        fill_taken_path(0, 0, 0);
        DP(0, 0);
        cout << "Case #" << i << ": ";
        RECONDP(0, 0);
        cout << '\n';
    }

    return 0;
}