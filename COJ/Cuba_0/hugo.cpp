#include <bits/stdc++.h>
using namespace std;

int toN(vector<int>& v) {
	int ans = 0, dig = 1, len_ = v.size();
	for (int i = len_ - 1; i >= 0; --i) {
		ans += dig * v[i];
		dig *= 10;
	}
	return ans;
} 

vector<int> toV(int X) {
	vector<int> resp;
	while (X) {
		resp.push_back(X % 10);
		X /= 10;
	}
	reverse(resp.begin(), resp.end());
	return resp;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	vector<int> N, M;
	int len_ = s.size();
	for (int i = 0; i < len_; ++i) N.push_back(s[i] - '0');	
	int ans = 0;
	for (;;) {
		M = N;
		sort(M.begin(), M.end());
		//cout << toN(N) << " ? " << toN(M) << " .. " << ans << '\n';
		int dbg;
		//cin >> dbg;
		N = toV(toN(N) - toN(M));
		ans++;
		if (!toN(N))break;
	}
    cout << ans << '\n';	
	return 0;
}