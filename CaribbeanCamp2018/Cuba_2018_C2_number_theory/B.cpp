#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

void findPrimefactors(unordered_set<Long> &s, Long n) {
    while (n % 2LL == 0) {
        s.insert(2LL);
        n = n / 2LL;
    }

    Long lim = sqrt(n) + 1LL;
	for (Long i = 3LL; i <= lim; i += 2LL) {
        while (n % i == 0) {
            s.insert(i);
            n = n / i;
        }
    }
 
    if (n > 2LL) s.insert(n);
}

Long Euclides( Long a, Long b, Long& x, Long & y, Long mod = 0 ) {
	if(!b){
		x = 1; y = 0;return a;
	}
	Long gcd = Euclides(b, a%b, x, y, mod);
	x = !mod ? x - y * (a/b) :
		(mod + x - (y * (a/b)) % mod)% mod;
	swap(x, y);
	return gcd;
}

Long Inv(Long vi, Long mod = 0) {
	Long inv, yi;
	Euclides(vi, mod, inv, yi, mod);
	return inv;
}

Long Exponenciar(Long a,Long n,Long m){
	Long resultado = 1LL;
	for(; n ; n >>= 1LL){
		if(n&1) resultado = (resultado*a)%m;
		a = (a*a)%m;
	}
	return resultado;
}


Long primitive_root(Long m) {
	if (m == 1)
		return 0;
	if (m == 2)
		return 1;
	if (m == 4)
		return 3;
	
	Long phi = m - 1LL;
	unordered_set<Long> s;
	findPrimefactors(s, phi);

	for (Long r = 2LL; r <= phi; r++) {
		bool flag = false;
		for (auto it = s.begin(); it != s.end(); it++) {
			if (Exponenciar(r, phi/(*it), m) == 1) {
				flag = true;
				break;
			}
		}
		if (flag == false) return r;
	}
}

int T;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> T;
	for (int nc = 0; nc < T; ++nc) {
		Long pi, ai, bi;
		cin >> pi >> ai >> bi;

		if (!bi) {
			int lim = min(pi, 10LL);
			cout << lim << '\n';
			for(int i = 0; i < lim; ++i){
				if (i) cout << ' ';
				cout << i;
			}
			cout << '\n';
			continue;
		}
		
		Long g = __gcd(pi - 1LL, ai);
		int lim = min(10LL, g - 1LL);

		set<Long> res;
		Long pot = (pi - 1LL) / g;
		for(int i = 0; i < 1000; ++i) {
			if(res.size() == lim) break;
			Long gi = (rand() * 1LL * rand() + rand() ) % (pi - 1LL);
			gi += pi - 1LL;
			gi %= pi - 1LL;
			gi++;
			Long gij = Exponenciar(gi, pot, pi);
			if (gij == 1) continue;
			Long xi = (bi * Inv(gij - 1LL, pi)) % pi;
			res.insert(xi);
		}

		cout << lim << '\n';
		int cnt = 0;
		for (Long it : res) {
			if (cnt++) cout << ' ';
			cout << it;
		}
		cout << '\n';
	}

	return 0;
}