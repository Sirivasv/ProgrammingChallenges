#include <bits/stdc++.h>
using namespace std;

int Operation(int a, int b) { return (a * a + b); }

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int m, n, ans = 0;
	
	cin >> n >> m;
	
	for (int i = 0; i <= 100; ++i)
		for (int j = 0; j <= 100; ++j)
			if ((Operation(i, j) == n) && (Operation(j, i) == m))
				ans++;
			
	cout << ans << '\n';
	
	return 0;
}