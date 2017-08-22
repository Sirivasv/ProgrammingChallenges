#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;
const int MAXL = 2 * MAXN;

int ini[MAXN], fin[MAXN];
int timeL[MAXL];
map<int, int> mp;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) { 
		cin >> ini[i] >> fin[i];
		fin[i]++;
		mp[ini[i]] = 1;
		mp[fin[i]] = 1;
	}
	int id = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) it->second = id++;
	//for (auto it : mp) cout << it.second << '\n';

	for (int i = 0; i < N; ++i) { 
		timeL[mp[ini[i]]]++;
		timeL[mp[fin[i]]]--;
	}

	int acum = 0;
	for (int i = 0; i < MAXL; ++i) {
		acum += timeL[i];
		if (acum > 2) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}