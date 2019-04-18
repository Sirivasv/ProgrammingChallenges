#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pll;
typedef pair<lli, pll> ter;

const int MAXN = 100009;

ter val[MAXN];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    lli N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> val[i].second.first >> val[i].second.second;
        val[i].first = val[i].second.first - val[i].second.second;
    }
    sort(val, val + N);
    lli res = 0;
    for (lli i = N; i >= 1; --i) res += (val[i - 1].first * (N - i + 1LL)) + (val[i - 1].second.second * N) - val[i - 1].second.first;
    cout << res << '\n';
    return 0;
}