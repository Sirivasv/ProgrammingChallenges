#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100;

int pzzl[MAXN];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		cin >> pzzl[i]; 
	sort(pzzl, pzzl + M);
	for (int i = 0; i < M; ++i)
		pzzl[i + M] = pzzl[i];
	int lim = M << 1;
	set<pii> mp;
	int ans = 1 << 30;
	for (int i = 0; i <= lim; ++i) {
		if (mp.size() < N) {
			mp.insert(pii(pzzl[i], i));
		} else { 
			ans = min(ans, (*(mp.rbegin())).first - (*(mp.begin())).first);
			//cout << (*(mp.begin())).first << ' ' << (*(mp.begin())).second << ' ' << (*(mp.rbegin())).first << ' ' << (*(mp.rbegin())).second << '\n';
			//cout << ans << ' ' << (i - N) << ' ' << (i - 1) << '\n';
			mp.erase(pii(pzzl[(i - N)], (i - N)));
			mp.insert(pii(pzzl[i], i));
		}
	}
	cout << ans << '\n';
	return 0;
}