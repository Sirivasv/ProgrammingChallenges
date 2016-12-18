#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

bool isLucky(lli x) { return ((x == 4LL) || (x == 7LL)); }

bool isNearLucky(lli n) {
	lli cnt = 0;
	while (n) {
		if (isLucky(n % 10LL))
			cnt++;
		n /= 10LL;
	}
	return isLucky(cnt);
}

int main() {
	
	lli N;
	cin >> N;
	
	cout << ((isNearLucky(N))?("YES"):("NO")) << '\n';
	
	return 0;
}