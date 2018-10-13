#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<int, int> pii;

lli sum = 0;

vector<int> getPrimesIn(lli N) {

	vector<int> isPrime(N + 5, 1);

	for (int i = 4; i <= N; i += 2) {
 		isPrime[i] = 0;
	}

	lli lim = lli(sqrt(double(N))) + 1LL;
	for (lli i = 3LL; i <= lim; i += 2LL) {
		if (!isPrime[i]) continue;
		for (lli j = i * i; j <= N; j += i) {
			isPrime[j] = 0;
		}
	}

	vector<int> primes;
	for (int i = 2; i <= N; ++i) {
		if (isPrime[i]) primes.push_back(i);
	}

	return primes;
}

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	if (M < (N - 1)) {
		cout << "Impossible\n";
		return 0;
	}
	if (N >= (1000)) {
		cout << "Possible\n";
		return 0;
	}
	M -= (N - 1);
	vector<int> primes = getPrimesIn(N);
	int cnt = 0;
	set<pii> edges;

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < primes.size(); ++j) {
			if (i % primes[j]) {
				
				if (edges.find(pii(i, primes[j])) != edges.end()) continue;
				if (edges.find(pii(primes[j], i)) != edges.end()) continue;
				cnt++;
				edges.insert(pii(i, primes[j]));
				if (cnt == M) {
					break;
				}
			}				
		}
		if (cnt == M) {
			break;
		}
	}

	if (cnt < M) {
		for (int i = 2; i <= N; ++i) {
			for (int j = 2; j <= N; ++j) {
				if (__gcd(i, j) == 1) {
					if (edges.find(pii(i, j)) != edges.end()) continue;
					if (edges.find(pii(j, i)) != edges.end()) continue;
					edges.insert(pii(i, j));
					cnt++;
					if (cnt == M) {
						break;
					}
				}
			}
			if (cnt == M) {
				break;
			}
		}
	}

	if (cnt == M) {
		cout << "Possible\n";
		for (int i = 2; i <= N; ++i) {
			cout << i << ' ' << 1 << '\n';
		}

		for (auto edge : edges) {
			cout << edge.first << ' ' << edge.second << '\n';
		}

	} else {
		cout << "Impossible\n"; 
	}

	return 0;
}