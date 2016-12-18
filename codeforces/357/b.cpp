#include <bits/stdc++.h>
using namespace std;
long long n;

int memo[200][1009];
long long a = 1234567LL;
long long b = 123456LL;
long long c = 1234LL;

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	int val = 0;
	for (long long i = 0; i < 200; ++i)
		for (long long j = 0; j < 1009; ++j)
			if (((i * a) + (j * b)) <= n)
				val |= (((n - ((i * a) + (j * b))) % c) == 0);
	if (val)
		cout << "YES\n";
	else 
		cout << "NO\n";
	return 0;
}