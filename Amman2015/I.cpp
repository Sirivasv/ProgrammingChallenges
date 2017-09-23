#include <bits/stdc++.h>
using namespace std;

const int MAXN = 259;

string s;

int acum[MAXN], K;

int Check(int grop, int ld) {
	for (int i = 0; i <= K; ++i) acum[i] = 0;
	int lim = K - grop;
	int sum = 0;
	for (int i = 0; i < K; ++i) {
		int num_here = s[i] - '0';
		sum += acum[i]; 
		num_here += sum;
		num_here %= 10;
		if (i > lim){ 
			if (num_here != ld) return 0;
			continue;
		}
		int added = 0;
		if (num_here > ld) added = (ld + (10 - num_here));
		else added = (ld - num_here);
		sum += added;
		acum[i + grop] -= added; 
	}
	return 1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> s;
		K = s.size();
		int ans = 0, res = 1;
		for (int i = K; i >= 1; --i) {
			for (int j = 0; j <= 9; ++j) {
				ans = Check(i, j);
				if (ans) { /* cout << i << ' ' << j << '\n'; */ res = i; break; } 
			}
			if (ans) break;
		}
		cout << res << '\n';
	}
	return 0;
}