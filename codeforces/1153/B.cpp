#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109;

int cols_a[MAXN];
int cols_b[MAXN];

int rows_a[MAXN];
int rows_b[MAXN];

int mat_pos[MAXN][MAXN];
int mat_ans[MAXN][MAXN];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M, H;
    cin >> N >> M >> H;

    for (int i = 0; i < M; ++i) {
        cin >> cols_a[i];
        cols_b[M - i - 1] = cols_a[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> rows_a[i];
        rows_b[M - i - 1] = rows_a[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mat_pos[i][j];
            if (!mat_pos[i][j]) continue;
            mat_ans[i][j] = min(rows_a[i], cols_a[j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j) cout << ' ';
            cout << mat_ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}