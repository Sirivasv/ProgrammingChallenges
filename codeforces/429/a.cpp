#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;	
	cin >> N >> M;
	string s;
	cin >> s;
	map<char, int> ms;
	for (int i = 0; i < s.size(); ++i) ms[s[i]]++;
	int mats = -1;
	for (auto it : ms) mats = max(mats, it.second);
	if (mats > M) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}