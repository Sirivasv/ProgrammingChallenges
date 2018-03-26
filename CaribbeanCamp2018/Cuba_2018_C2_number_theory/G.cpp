#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

Long Euclides( Long a, Long b, Long& x, Long & y, Long mod = 0 ){
	if(!b){
		x = 1; y = 0;return a;
	}
	Long gcd = Euclides(b, a%b, x, y, mod);
	x = !mod ? x - y * (a/b) :
		(mod + x - (y * (a/b)) % mod)% mod;
	swap(x, y); return gcd;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	Long n, m, x, y;

	cin >> n >> m;
	if( __gcd(n,m) == 1 ){
		Euclides( n, m, x, y,m );
		cout << x << '\n';
		return 0;
	}
	cout << -1 << '\n';

	return 0;
}
