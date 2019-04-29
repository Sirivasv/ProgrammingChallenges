#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

const int MAXN = 2100;
const lli MOD = 1000000007LL;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    lli n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 <<'\n';
        return 0;
    }
    if (n == 2) {
        cout << 3 <<'\n';
        return 0;
    }
    lli res = 2LL;
    lli mins = (2LL * n) %MOD;
    mins = (mins - 3LL + MOD) % MOD;
    for (int i = 3; i <= n; ++i) {
        res = (res * 2LL) % MOD;
    }
    res = (res * n) % MOD;
    lli ans = (res - mins + MOD) %MOD;
    cout << ans << '\n';
    return 0;    
}