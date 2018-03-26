#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

typedef long long Long;
const int MAXN = 4000200;
Long criba[MAXN];
Long potencias[MAXN];

vector<Long> Criba(Long n){
		vector<Long> ret;
		for(Long i = 4; i <= n; i+=2){
			criba[i] = 2;
		}
		for(Long i = 3; i <= n; i+=2){
			if( !criba[i] )
				for(Long j = i*i; j <= n; j += i){
					if(!criba[j]) criba[j] = i;
				}
		}
		for(Long i = 2 ; i <= n ; i++)
			if(!criba[i]) ret.push_back(i);
		
		return ret;
}

int main(){
	
	optimizar_io(0);
	Long N;
	
	cin >> N;
	Long raiz = sqrt(N);
	vector<Long> primos = Criba(2*raiz);
	
	Long pot;
	Long ex_or = 0;
	for( int i = 0; primos[i] <= raiz && N != 1; i++ ){		
		pot = 0;
		while( (N % primos[i]) == 0 ){
			N /= primos[i];
			pot++;
		}
		if(pot & 1 ) ex_or ^= (i+1);
	}
	
	if( N != 1 ){
		for(int i = 0 ; i < primos.size() ; i++){
			if(primos[i] == N ){
				ex_or ^= (i+1);
				if( ex_or ){
					cout << "David\n";
				}
				else{
					cout << "Vasya\n";
				}
				return 0;
			} 
		}
		cout << "David\n";
	} else {
		if( ex_or ){
			cout << "David\n";
		}
		else{
			cout << "Vasya\n";
		}
	}
	return 0;
}
