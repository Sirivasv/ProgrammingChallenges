#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef pair<Long, Long> pll; 
Long MAXN = 1000000;

int primes[1000009];
int criba[1000009];
Long N;

void Criba(){
	int raiz = MAXN;
	for( Long i = 4; i <= MAXN; i +=2 )
		criba[i] = 2;
	for( Long i = 3; i <= MAXN; i += 2 )
		if( !criba[i] )
			for( Long j = i * i; j <= MAXN; j+= i )
				if( !criba[j] ) criba[j] = i;

	for( int i = 2, j = 0; i <= MAXN; i++ ){
		if( !criba[i] ){
			primes[j++] = i;
		}		
	}
}	

pll numDiv(){
	Long PF_idx = 0, PF = primes[PF_idx], ans1 = 1, ans2 = 1;
	while(PF*PF<= N){
		Long power = 0ll;
		while( N%PF == 0 ){
			N /= PF; power++;
		}
		ans1 *= (power +1);
		ans2 *= ((Long)pow((double)PF, power+1.0)-1) / (PF -1);
		PF = primes[++PF_idx];
	}
	if( N != 1 ){ 
		ans1 *= 2ll;
		ans2 *= ((Long)pow((double)N, 2.0)-1) / (N -1);
	}
	return pll(ans1, ans2);
}


Long EulerPhi( Long n ){
	Long ans = n, i;
	for(i = 2; i * i <= n; i++){
		if(n%i == 0){
			while( n % i == 0 ) n/= i;
			ans -= ans/i;
		}
	}
	if(n > 1) ans -= ans/n;
	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N; 
	Criba();
	cout << EulerPhi(N) << ' ';
	pll res = numDiv();
	cout << res.first << ' '<<  res.second << '\n';
	return 0;
}
