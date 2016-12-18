#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pli;

const int MAXN = 100009;

pli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli N, r, avg;
	cin >> N >> r >> avg;
	lli acum = 0;
	avg *= N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].second >> arr[i].first;
		acum += arr[i].second;
	}
	sort (arr, arr + N);
	lli ans = 0;
	for (int i = 0; i < N; ++i) {
		lli tmpans = max(0LL, min(r - arr[i].second, avg - acum));
		ans += tmpans * arr[i].first;
		acum += tmpans;
	}
	cout << ans << '\n';
	return 0;
}