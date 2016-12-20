#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string prev, cur;
	
	prev = "22";
	
	int N;
	cin >> N;
	
	int ans = 1;
	
	for (int i = 0; i < N; ++i) {
		cin >> cur;
		if (cur[0] == prev[1])
			ans++;
		prev = cur;
	}
	
	cout << ans << '\n';
	
	return 0;
}