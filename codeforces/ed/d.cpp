#include <bits/stdc++.h>
using namespace std;
const unsigned long long MOD = 1000000007LL;
unsigned long long A, B, x, N;

unsigned long long ExpBin(unsigned long long b, unsigned long long pot) {
	unsigned long long res = 0, p = b;
	res++;
	for (unsigned long long n = pot; n; n >>= 1) {
		if (n & 1) 
			res = (res * p) % MOD;
		p = (p * p) % MOD;
	}
	return res;
}

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> A >> B >> N >> x;
	unsigned long long res = ExpBin(A, N);
	unsigned long long bres = res;
	res = (res * x) % MOD;
	bres = (bres + MOD);
	bres--;
	bres %= MOD;
	unsigned long long aux = A;
	unsigned long long auxx = MOD;
	aux--;
	auxx--;
	auxx--;
	bres = (bres * ExpBin(aux, auxx)) % MOD;
	bres = (B * bres) % MOD;
	res = (res + bres) % MOD;
	if (A == 1LL) {
		res = ExpBin(A, N);
		res = (x * res) % MOD;
		bres = (B * N) % MOD;
		res = (res + bres) % MOD;
		cout << res << '\n';
	} else {
		cout << res << '\n';
	}
	return 0;
}