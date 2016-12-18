#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MAXN = 10000009;

vector<lli> Primes;

void Sieve() {
	bitset<MAXN> bits;
	
	lli lim = sqrt(MAXN);
	
	for (lli i = 4LL; i < MAXN; i += 2LL)
		bits[i] = 1;
	
	for (lli i = 3LL; i <= lim; i += 2LL)
		if (!bits[i])
			for (lli j = i * i; j < MAXN; j += i)
				bits[j] = 1;
			
	for (lli i = 2LL; i < MAXN; ++i)
		if (!bits[i])
			Primes.push_back(i);
}

int cnt[MAXN], F[700000];

int Busbinm(int v) { //mas chico que sea mayor o igual
	int ini = 0, fin = Primes.size() - 1, ans = -2;
	while (ini <= fin) {
		int m = (ini + fin) / 2;
		if (Primes[m] >= v) {
			ans = m;
			fin = m - 1;
		} else ini = m + 1;
	}
	ans++;
	return ans;
}

int BusbinM(int v) { //mas grande que sea menor o igual
	int ini = 0, fin = Primes.size() - 1, ans = -2;
	while (ini <= fin) {
		int m = (ini + fin) / 2;
		if (Primes[m] <= v) {
			ans = m;
			ini = m + 1;
		} else fin = m - 1;
	}
	ans++;
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	Sieve();
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		int xi;
		cin >> xi;
		cnt[xi]++;
	}
	
	for (int i = 0; i < Primes.size(); ++i) {
		F[i + 1] = F[i];
		for (lli j = Primes[i]; j < MAXN; j += Primes[i])
			F[i + 1] += cnt[j];
	}
	
	int M;
	cin >> M;
	
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		int I = Busbinm(a);
		int J = BusbinM(b);
		if ((I <= J) && (I != -1) && (J != -1)) cout << F[J] - F[I - 1] << '\n';
		else cout << "0\n";
	}
	
	return 0;
}