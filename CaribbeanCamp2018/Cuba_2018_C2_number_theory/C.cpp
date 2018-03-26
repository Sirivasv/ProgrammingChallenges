#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1e9 + 7LL;

set<lli> divs, ndivs;

void getDivs(lli xi) {
	lli root = sqrt(xi) + 1;
	for (lli i = 1LL; i < root; ++i) {
		if (!(xi % i)) {
			divs.insert(xi / i);
			divs.insert(i);
		}
	}
}

lli Exponenciar(lli a,lli n,lli m){
	lli resultado = 1LL;
	for(; n ; n >>= 1LL){
		if(n&1) resultado = (resultado*a)%m;
		a = (a*a)%m;
	}
	return resultado;
}	

lli Euclides( lli a, lli b, lli& x, lli & y, lli mod = 0 ){
	if(!b){
		x = 1; y = 0;return a;
	}
	lli gcd = Euclides(b, a%b, x, y, mod);
	x = !mod ? x - y * (a/b) :
		(mod + x - (y * (a/b)) % mod)% mod;
	swap(x, y);
	return gcd;
}

lli getGeom(lli pi, lli n) {
	lli inv, yi;
	Euclides(pi - 1LL, MOD, inv, yi, MOD);
	//cout << pot << '\n';
	lli val = (Exponenciar(pi, n - 2, MOD) + MOD - 1LL) % MOD;
	//cout << "S: " << curr << ' ' << inv << ' ' << val << '\n'; 
	return ((inv * val) % MOD);
}

int main() {
	lli p, N;

	cin >> p >> N;

	getDivs(p - 1);

	lli np = p * (p - 1LL);

	for (auto it : divs) {
		ndivs.insert(it);
		ndivs.insert(p * it);
		ndivs.insert(it * (-1LL));
		ndivs.insert(p * it * (-1LL));
	}

	lli res0 = 0;
	lli res1 = 0;
	// cout << "RR: " << (p * (p - 1LL)) << '\n'; 
	int cnt = 0;
	for (auto it : ndivs) {
		lli n = it;
		lli m = np / it;
		lli a1 = (p - 1LL) - n;
		lli a2 = p - m;
		if ((a2 <= 0) || (a1 <= 0)) continue;
		a1 %= MOD;
		a2 %= MOD;
		res0 = (res0 + (p - 1LL)) % MOD;
		res1 = (res1 + a1) % MOD;
		cnt++;
		// cout << (cnt++) << " N: " << n << " M: " << m << " A1: " << a1 << " A2: " << a2 << '\n';
		// cout << "JJ: " << (n * m) << " V: " << ((p - a2) * ((p - 1LL) - a1)) << '\n';
		// cout << "TT: " << double(double(p - 1LL) / double(a1)) + double(double(p) / double(a2)) << '\n';
	}

	cout << cnt << '\n';

	if (N == 0) {
		cout << res0 << '\n';
		return 0;
	}

	if (N == 1) {
		cout << res1 << '\n';
		return 0;
	}

	cnt = 1;
	lli res = 0;
	for (auto it : ndivs) {
		lli n = it;
		lli m = np / it;
		lli a1 = (p - 1LL) - n;
		lli a2 = p - m;
		if ((a2 <= 0) || (a1 <= 0)) continue;
		a1 %= MOD;
		a2 %= MOD;
		res = (res + ((Exponenciar(p, N - 2, MOD) * a2) % MOD)) % MOD;
	}	

	cout << res << '\n';

	return 0;
}