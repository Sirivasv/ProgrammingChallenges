#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

int N, M, xi, yi;
lli a, b, c;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	a = 1378LL; 
	b = 1LL;
	cin >> N;
	for (; N; N >>= 1) {
		if (N & 1) {
			b *= a;
			b %= 10LL;
		}
		a *= a;
		a %= 10LL;
	}
	cout << b << '\n';
	return 0;
}