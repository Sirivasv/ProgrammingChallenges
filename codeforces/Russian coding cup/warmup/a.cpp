#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s, ss;
	cin >> s;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> ss;
		map<char, int> ls, lss;
		for (int j = 0; j < s.size(); ++j)
			ls[s[j]]++;
		for (int j = 0; j < ss.size(); ++j)
			lss[ss[j]]++;
		int lim = min(s.size(), ss.size());
		int ans1 = 0, ans2 = 0;
		for (int j = 0; j < lim; ++j)
			if (s[j] == ss[j]) {
				ls[s[j]]--;
				lss[s[j]]--;
				if (!ls[s[j]])
					ls.erase(s[j]);
				if (!lss[s[j]])
					lss.erase(s[j]);
				ans1++;
			}
		for (auto it = lss.begin(); it != lss.end(); it++) {
			char c = it->first;
			if (!ls.count(c))
				continue;
			ans2 += min(lss[c], ls[c]);
		}
		cout << ans1 << ' ' << ans2 << '\n';
	}
	return 0;
}