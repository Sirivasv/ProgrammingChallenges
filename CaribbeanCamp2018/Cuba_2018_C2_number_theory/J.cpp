#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;

Long Exponenciar(Long a,Long n,Long m){
	Long resultado = 1LL;
	for(; n ; n >>= 1LL){
		if(n&1) resultado = (resultado*a)%m;
		a = (a*a)%m;
	}
	return resultado;
}	

Long Euclides( Long a, Long b, Long& x, Long & y, Long mod = 0 ){
	if(!b){
		x = 1; y = 0;return a;
	}
	Long gcd = Euclides(b, a%b, x, y, mod);
	x = !mod ? x - y * (a/b) :
		(mod + x - (y * (a/b)) % mod)% mod;
	swap(x, y);
	return gcd;
}

Long getSum(Long curr, Long P, Long pot) {
	Long inv, yi;
	Euclides(curr - 1LL, P, inv, yi, P);
	//cout << pot << '\n';
	Long val = (Exponenciar(curr, pot, P) + P - 1LL) % P;
	//cout << "S: " << curr << ' ' << inv << ' ' << val << '\n'; 
	return ((inv * val) % P);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	Long N;
	
	cin >> N;

	Long P = 4066273LL;
	
	Long res = 0;
	Long g = 5LL;
	Long currPot = 5LL;

	Long first;
	cin >> first;
	
	res = (N * first) % P;
	
	for (int i = 1; i < N; ++i) {
		Long curr;
		cin >> curr;
		curr = (curr * getSum(currPot, P, N)) % P;
//		cout << getSum(currPot, P, N) << '\n'; 
		res = (res + curr) % P; 
		currPot = (currPot * g) % P;
//		cout << "D " << res << '\n';
	}
	
	cout << res << '\n';
 
	return 0;
}
