#include<bits/stdc++.h>
using namespace std;
typedef long long int Long;
const Long MOD = 998244353;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N;
	cin >> N;

	Long res = 1LL , mul;
	for(int i = 2; i <= N; i++){
		mul = (Long(i)*2LL)%MOD;
		res = (res*mul)%MOD;
		 if( i & 1 ) res = ( MOD + res - 1LL ) % MOD;	
		else res = (res + 1LL  ) % MOD;		
	}

	cout << res << '\n';

	return 0;
}
