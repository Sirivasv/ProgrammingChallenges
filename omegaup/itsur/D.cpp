#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const lld MOD = 1000000007;

int main(){
	lld N;
	cin >> N;
	lld raiz = sqrt(N);
	lld ans = 1;
	lld tam = N / raiz + 1;
	lld* p1 = new lld[N + 1];
	lld* p2 = new lld[N + 1];
	
	p1[0] = p2[0] = 1;
	for(int i = 1; i <= N; i++){
		p1[i] = (raiz * p1[i - 1]);
		p2[i] = ((raiz + 1) * p2[i - 1]);
		
	}
	for(int i = 0; i <= tam; i++){
		if((N - i * raiz) % (raiz + 1))
			continue;
		ans = max(ans, *p1[i] * p2[(N - i * raiz) / (raiz + 1)]);
	)
	return 0;
}