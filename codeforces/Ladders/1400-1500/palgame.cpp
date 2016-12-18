#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	map<char, int> mp;
	string s;
	cin >> s;
	int lim = s.size();
	for (int i = 0; i < lim; ++i)
		mp[s[i]]++;
	int n = 0;
	for (auto it: mp) {
		if (it.second & 1)
			n++;
	}
	n--;
	if (n < 0)
		n = 0;
	cout << ((n & 1)?("Second\n"):("First\n"));
	return 0;
}