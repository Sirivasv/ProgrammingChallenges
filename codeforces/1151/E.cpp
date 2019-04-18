#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    lli N;
    cin >> N;

    lli la = 0;
    lli res = 0;
    for (lli i = 0; i < N; ++i) {
        lli a;
        cin >> a;
        if (a > la) {
            res += (a - la) * (N - a + 1LL);
        } else{
            res += a * (la - a);
        }
        la = a;
    }
    cout << res << '\n';

    return 0;
}