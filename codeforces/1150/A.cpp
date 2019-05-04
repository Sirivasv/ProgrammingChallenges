#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 300009;

lli N, arr_a[MAXN], arr_b[MAXN], arr_c[MAXN], M, R;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M >> R;

    lli mats = -1; lli mint = 10000;
    for (int i = 0; i < N; ++i) {
        cin >> arr_a[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> arr_b[i];
    }
    sort(arr_a, arr_a + N);
    sort(arr_b, arr_b + M);
    lli copy_R = R;
    int idN = 0;
    lli mintS = 0;
    while (copy_R && (idN < N)) {
        mintS += (copy_R / arr_a[idN]);
        copy_R -= (arr_a[idN] * (copy_R / arr_a[idN]));
        idN++;
    }
    lli ansL = copy_R  + (mintS * arr_b[M - 1]);
    if (ansL > R) {
        cout << ansL << '\n';
    } else {
        cout << R << '\n';
    }

    return 0;
}