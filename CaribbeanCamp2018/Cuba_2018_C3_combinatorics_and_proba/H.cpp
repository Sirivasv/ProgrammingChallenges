#include<bits/stdc++.h>
using namespace std;
typedef long long int Long;
const Long MOD = 1e9+7;


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N,M;
	cin >> N >> M;
	vector<Long> izq(M) , der(N) , h(M) , res(M) , d(M);

	for(int i = 0; i < N ; i++)
		cin >> der[i];
	for(int i = 0; i < M ; i++)
		cin >> izq[i];

	if( N < M ){
		cout << "0\n";
		return 0;
	}

	sort(izq.begin(),izq.end());
	sort(der.begin(),der.end());
	reverse(der.begin(),der.end());
	reverse(izq.begin(),izq.end());

	int pos = 0;
	for(int i = 0; i < M ; i ++){
		while(pos < N && der[pos] >= izq[i] ){
			pos++;		
		}		
		h[i] = pos;
	}

	//res[0] = h[0];
	//d[1] = (h[0] * (h[0]-1LL))%MOD;
	//Long suma = d[1];
	//for(int i = 1; i < M ; i++){
	//	res[i] = (h[i]*res[i-1])%MOD;
	//	res[i] = (res[i]+suma)%MOD;
	//	d[i] = (h[i] * (h[i]-1LL))%MOD;
	//	d[i] = (d[i] * (res[i-1]))%MOD;
	//	d[i] = (d[i]+suma)%MOD;
	//	suma = (suma + d[i])%MOD;
	//}

	Long ans = 1LL;
	for (int i = 0; i < M; ++i) {
		ans = (ans * (h[i] - i)) % MOD;	
	}
	cout << ans << '\n';
	//cout << max(0LL,res[M-1]) << '\n';
	

	return 0;
}
