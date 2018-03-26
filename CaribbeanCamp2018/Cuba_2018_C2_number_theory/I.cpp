#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
const int MOD = 2007;

int main(){


	int N;
	optimizar_io(0);

	cin >> N;
	vector<int>F(N+1),G(N+1);
	for(int i  = 1 ; i <= N ; i++)
		cin >> F[i];
	
	int suma;
	G[1] = 1;
	for(int i = 2; i <= N ; i++){
		suma = 0;
		for(int j = 2; j*j <= i ; j++){
			if(i%j == 0){
				int k = i/j;
				suma = (suma+F[j]*G[k])%MOD;
				if(j != k) {
					suma = (suma+F[k]*G[j])%MOD;
				}
			}
		}
		suma = (suma+F[i])%MOD;
		G[i] = (MOD - suma )%MOD;
	}

	for(int i = 1 ; i <= N ; i++)
		cout << G[i] << ' ';
	cout << '\n';

	return 0;
}
