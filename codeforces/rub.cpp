#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() { 
	lli N;
	cin >> N;
	lli modf = N % 4LL;
	lli a, b, c;
	cin >> a >> b >> c;
	if (modf == 0)
		cout << "0\n";
	else if (modf == 1LL) // quieres 3
		cout << min(3LL * a, min(a + b, c)) << '\n';
	else if (modf == 2LL)
		cout << min(2LL * a, min(b, 2LL * c)) << '\n';
	else 
		cout << min(a, min(b + c, c)) << '\n';
	return 0;
}