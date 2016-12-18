#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
int n;
long long k, needs[MAXN], has[MAXN], magic, aux;

inline bool Checa(long long X) {
	magic = k;
	for (int i = 0; i < n; ++i) {
		aux = has[i] - (needs[i] * X);
		if (aux < 0) magic += aux;
		if (magic < 0) return false;
	}
	return true;
}

inline long long BusBin(){
	long long ini = 0, fin = 2000000000, mid, ans = 0;
	while (ini <= fin) {
		mid = (ini + fin) >> 1;
		if (Checa(mid)) {
			ans = mid;
			ini = mid + 1;
		} else fin = mid - 1;
	}
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> needs[i];
	for (int i = 0; i < n; ++i) cin >> has[i];
	cout << BusBin() << '\n';
	return 0;
}