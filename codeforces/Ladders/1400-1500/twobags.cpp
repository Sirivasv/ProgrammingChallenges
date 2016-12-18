#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	lli y, k, n;
	
	cin >> y >> k >> n;
	
	int many = 0;
	
	for (lli v = 1LL; (v * k) <= n; ++v) {
		if (((v * k) - y) <= 0)
			continue;
		cout << ((v * k) - y) << ' ';
		many++;
	}
	
	if (many == 0)
		cout << "-1\n";
	
	return 0;
}