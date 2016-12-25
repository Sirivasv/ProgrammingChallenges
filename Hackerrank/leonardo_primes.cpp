#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

bool IsPrime(lli xi) { //O(sqrt(xi))
    if ((xi % 2) == 0) return false;
    lli lim = sqrt(xi);
    for (lli i = 3LL; i <= lim; i += 2LL)
        if ((xi % i) == 0) return false;
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<lli> primes;
    primes.push_back(2LL);
    for (lli p = 3LL; p <= 1000LL; ++p)
        if (IsPrime(p)) primes.push_back(p);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        lli xi;
        cin >> xi;
        int cnt = 0;
        lli prod = 1LL;
        while ((prod < xi) && (cnt < 16))
            prod *= primes[cnt++];
        cout << (cnt - (prod != xi)) << '\n';
    }
    return 0;
}
