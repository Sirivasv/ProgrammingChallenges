#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 1000000;

lli Fib[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli N;
	cin >> N;
	Fib[0] = 1LL;
	Fib[1] = 2LL;
	int ans = 2;
	for (;; ans++) {
		Fib[ans] = Fib[ans - 1] + Fib[ans - 2];
		if (Fib[ans] > N)
			break;
	} 
	cout << (ans - 1) << '\n';
	return 0;
} 