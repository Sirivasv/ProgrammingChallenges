#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
const Long MOD = 1e9 + 7;
int main() {

	int S;
	int K;
	Long d;		
	Long l,r;
	Long B,V;
	Long lo,ro;
	Long Bl,Br;
	Long res,add;

	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> S >> K;
	for(int i = 0; i < K ;i++){
		cin >> l >> r;
		lo = l;
		ro = r;
		B = 1LL;
		V = (1LL << (S-1LL));
		res = 0;
		for(int j = 0; j < S ; j++){
			l = lo;
			r = ro;
			Bl = l/B;
			Br = r/B;
			if(Bl == Br){
				if(Bl & 1LL ){
					add = (V*(r-l+1LL))%MOD;
					res = (res + add )%MOD;
				}
			} else {
				if(l % B != 0LL){
					if(Bl & 1LL ){ 
						add = (MOD + B*(Bl+1LL) - l)%MOD;
						add = (add*V)%MOD;
						res = (res + add) %MOD;
					}
					l = Bl+1LL;
				} else l = Bl;
				if(r % B != B-1LL){
					if(Br & 1LL ){	
						add = ( MOD + r - (Br*B-1LL))%MOD;
						add = (add*V)%MOD;
						res = (res + add)%MOD;										
					}
					r = Br - 1LL;
				} else r = Br;
				if(l <= r ){
					d = r - l +1LL;
					add = (d/2LL)*V;
					add %= MOD;
					add = (add*B)%MOD;
					res = (res+add)%MOD;
					if((d&1LL) && (l&1LL) ) {
						add = (V*B)%MOD;
						res = (res+add)%MOD;
					}
				}
			}
			B <<= 1;
			V >>= 1;
		}
		cout << res%MOD << '\n';
	}	
			
	
	return 0;
}
