#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, string> pis;
typedef pair<pis, int> ter;

const int MAXN = 10009;

ter arr[MAXN];
pis sa[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K;
	ll D;
	cin >> N >> D >> K;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].first.second >> arr[i].first.first;
		arr[i].second = i;
	}
	
	sort(arr, arr + N, greater<ter>());
	
	ll saved = 0;
	int lim = 0;
	for (int i = 0; i < K; ++i) {
		if (saved >= D) break;
		saved += arr[i].first.first;
		sa[i] = pis(arr[i].second, arr[i].first.second);
		lim++;
	}
	
	sort(sa, sa + lim);

	if (saved >= D) {
		cout << lim << '\n';
		for (int i = 0; i < lim; ++i) cout << sa[i].second << ", YOU ARE FIRED!\n";	
	} else cout << "impossible\n";

	return 0;
}