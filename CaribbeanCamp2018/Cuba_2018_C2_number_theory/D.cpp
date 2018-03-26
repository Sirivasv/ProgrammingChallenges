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

	Long a,b, c,x,y;

	cin >> a >> b >> c;
	Long gcd = Euclides(a, b, x, y);
	if( c%gcd== 0 ){
		Long por = c/gcd , R, K , O;
		x *= por;
		y *= por;
		K = b/gcd;
		O = (a/gcd)*-1;
		if(K < 0 ){
			K*=-1;
			O*=-1;
		}

		if(x<0){
			R = (x*-1)/K;
			if(x+K*R < 0) R++;
		} else {
			R = (x/K)*-1;
		}

		x += K*R;		
		y += O*R;

		cout << x << ' ' << y << '\n';

		return 0;
	}
	cout << "Impossible" << '\n';

	return 0;
}
