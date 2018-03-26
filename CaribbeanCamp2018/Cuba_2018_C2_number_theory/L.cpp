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

	Long n,e,C;
	cin >> n >> e >> C ;

	Long p,q;
	for(int i = 2; i*i <= n ;  i++){
		if(n%i == 0){
			p = i;
			q = n/i;
			break;
		}
	}

	//cout << "chosto" << endl;
	Long F = (p-1)*(q-1);
	Long F2 = EulerPhi(F);

	Long d = Exponenciar(e,F2-1,F);

	cout << Exponenciar(C,d,n)<< '\n';

	

	
	return 0;
}
