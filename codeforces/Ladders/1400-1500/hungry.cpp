#include <bits/stdc++.h>
using namespace std;

vector<int> Criba(int n) {
	int raiz = sqrt(n); vector<int> criba(n + 1);
	vector<int> primes;
	primes.push_back(2);
	for (int i = 4; i <= n; i += 2) criba[i] = 2;
	for (int i = 3; i <= raiz; i += 2) if (!criba[i]) {
		primes.push_back(i);
		for (int j = i * i; j <= n; j += i)
			if (!criba[j]) criba[j] = i;
	}
	return primes;
}

const int MAXN = 100009;

int arr[MAXN], id;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	vector<int> prim = Criba(10010000);
	int lim = prim.size();
	for (int i = 0; i < lim; ++i) {
		for (int j = i; j < lim; ++j) {
			arr[id++] = prim[i] * prim[j];
			if (id == MAXN)
				break;
		}
		if (id == MAXN)
			break;
	}
	sort(arr, arr + MAXN);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		if (i)
			cout << ' ';
		cout << arr[i];
	}
	cout << '\n';
	return 0;
}