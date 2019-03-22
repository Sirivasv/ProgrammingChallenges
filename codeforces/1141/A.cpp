#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MAXL = 500000009;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    lli a, b;
    cin >> a >> b;
    for (lli i = 1, ic = 0; i <= MAXL; i *= 2LL, ic++) {
        for (lli j = 1, jc = 0; j <= MAXL; j *= 3LL, jc++) {

            if ((a * i * j) == b) {
                cout << ic + jc << '\n';
                return 0;
            }

        }
    }
    cout << "-1\n";

    return 0;
}