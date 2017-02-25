#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int pos[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, xi, yi; 
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> xi >> yi;
		int ans = 0; 
		for (int j = 1; j * j <= xi; ++j) if (xi % j == 0) {
			int k = xi / j;
			
			if (pos[j] < i - yi) ans++;
			pos[j] = i;			
			if (pos[k] < i - yi) ans++;
			pos[k] = i;
		}
		cout << ans << '\n';
	}
	
	return 0;
}