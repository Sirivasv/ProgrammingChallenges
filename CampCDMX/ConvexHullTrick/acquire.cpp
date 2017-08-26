#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 50009;

pii arr[MAXN];
lli DP[MAXN];

bool bad(pii rect2, pii rect1, pii nr) {
	return ((nr.second - rect2.second) * (rect2.first - rect1.first)) < ((rect1.second - rect2.second) * (rect2.first - nr.first));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	
	vector<pii> clands;
	clands.push_back(arr[N - 1]);

	for (int i = N - 2; i >= 0; --i) {
		pii currtop = clands[clands.size() - 1];
		if (currtop.second >= arr[i].second) continue;
		clands.push_back(arr[i]);
	}
	
	reverse(clands.begin(), clands.end());
	int limit = clands.size();
	
	vector<pii> rects;
	rects.push_back(pii(clands[0].second, 0));
	for (int i = 1; i <= limit; ++i) {
		DP[i] = (rects[0].first * clands[i - 1].first) + rects[0].second;
		for (int j = 1; j < rects.size(); ++j)
			DP[i] = min(DP[i], (rects[j].first * clands[i - 1].first) + rects[j].second);
		if (i < limit) {
			pii nr = pii(clands[i].second, DP[i]);
			while ((rects.size() >= 2) && (bad(rects[rects.size() - 2], rects[rects.size() - 1], nr))) rects.pop_back();
			rects.push_back(nr);
		}
	}
	
	cout << DP[limit] << '\n';
	return 0;
}