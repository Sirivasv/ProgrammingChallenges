#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

const int MAXN = 2100;
const lli MOD = 1000000007;
lli C[MAXN][MAXN];

void PRECnR() {
	C[0][0] = 1LL;
	for (int i = 1; i < MAXN; ++i) {
		C[i][0] = 1LL;
        int limit = min(5, i);
		for (int j = 1; j <= limit; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
}


inline lli Euclides(lli a, lli b, lli& x, lli& y) {
    if (!b) { x = 1, y = 0; return a; }
    lli gcd = Euclides(b, a % b, x, y);
    x = !MOD? x - y * (a / b):
        (MOD + x - (y * (a / b)) % MOD) % MOD;
    swap(x, y);
    return gcd;
}

inline lli InvMod(lli x) {
	lli res, tmpy;
	Euclides(x, MOD, res, tmpy);
	return res;
}

inline lli get_Fact(lli xi) {

    lli res = 1LL;

    for (lli i = 2LL; i <= xi; ++i) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    lli n;
    PRECnR();
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if (n == 2) {
        cout << 3 << '\n';
        return 0;
    }

    lli res = 3LL;
    for (int i = 3; i <= n; ++i) {
        res = (res * C[i][2]) % MOD;
        cout << C[i][2] <<'\n';
        cout << res <<'\n';
        cout << (i - 2) <<'\n';
        cout << InvMod(i - 2) <<'\n';
        res = (res * InvMod(i - 2)) % MOD;
    }

    cout << res << '\n';
    return 0;    
}