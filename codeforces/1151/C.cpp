#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1000000007;

lli lf, rg;

lli get_sum_odd(lli xi) {
    xi -= 1LL;
    xi %= MOD;
    lli A = (xi * ((xi + 1LL)%MOD)) % MOD;
    lli B = (A * 500000004LL)% MOD;
    lli C = (B * 2LL) % MOD;
    lli D = (C + xi) % MOD;
    lli E = (D + 1LL) % MOD;

    return E;
}

lli get_sum_ev(lli xi) {
    xi %= MOD;
    lli A = (xi * ((xi + 1LL)%MOD)) % MOD;
    lli B = (A * 500000004LL)% MOD;
    lli C = (B * 2LL) % MOD;
    return C;
}

lli get_sum(lli id) {
    if (!id) return 0LL;
    if (id == 1) return 1LL;
    lli max_2p = 1;
    lli curr_ids = 1;
    int cnt = 0;
    while (curr_ids < id) {
        max_2p <<= 1;
        curr_ids += max_2p;
        cnt++;
    }
    cnt--;
    curr_ids -= max_2p;
    id -= curr_ids;

    lli sum_ev = 0;
    lli sum_odd = 0;
    max_2p = 1;
    for (int i = 0; i <= cnt; ++i) {
        if (i % 2) {
            sum_ev += max_2p;
        } else {
            sum_odd += max_2p;
        }
        max_2p <<= 1;
    }

    cnt++;
    if (cnt % 2) {
        sum_ev += id;
    } else {
        sum_odd += id;
    }
    // cout << cnt << " " << id << " " << sum_odd << ' ' << sum_ev << " ** \n";
    lli res = (get_sum_odd(sum_odd) + get_sum_ev(sum_ev)) % MOD;
    return res;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> lf >> rg;

    lli B = get_sum(lf - 1);
    lli A = get_sum(rg);
    

    cout << ((A - B + MOD) % MOD) << '\n';

    return 0;
}