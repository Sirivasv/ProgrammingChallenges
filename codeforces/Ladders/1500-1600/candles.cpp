#include <bits/stdc++.h>
using namespace std;

int main() {
	int W, T, M;
	cin >> W >> T >> M;
	
	int pos;
	cin >> pos;
	
	queue<int> cpos;
	int ans = M, PBP;
	
	int ok = 1;
	
	for (int i = 0; i < M; ++i) {
		cpos.push((pos - (M - i)) + T);
		PBP = pos - (M - i);
		if ((PBP + T) < pos)
			ok = 0;
	}
	
	for (int i = 1; i < W; ++i) {
		cin >> pos;
		int cnt = 0;
		while ((!cpos.empty()) && (pos > cpos.front())) {
			cpos.pop();
			cnt++;
		}
		int CBP = PBP;
		for (int i = 0; i < cnt; ++i) {
			if ((pos - (cnt - i)) <= PBP) {
				ok = 0;
				break;
			}
			cpos.push((pos - (cnt - i)) + T);
			CBP = pos - (cnt - i);
		}
		ans += cnt;
		if (!ok)
			break;
		PBP = CBP;
	}
	if (!ok)
		cout << "-1\n";
	else 
		cout << ans << '\n';
	return 0;
}