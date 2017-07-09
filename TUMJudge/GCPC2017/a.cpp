#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, string> pis;

const int MAXN = 10009;

pis arr[MAXN];

int main() {
	int N, K;
	ll D;
	cin >> N >> D >> K;
	for (int i = 0; i < N; ++i) cin >> arr[i].second >> arr[i].first;
	
	sort(arr, arr + N, greater<pis>());
	
	ll saved = 0;
	int lim = min(K, N);
	for (int i = 0; i < lim; ++i) saved += arr[i].first;
	
	if (saved >= D) {
		cout << lim << '\n';
		for (int i = 0; i < lim; ++i) cout << arr[i].second << ", YOU ARE FIRED!\n";	
	} else cout << "impossible\n";

	return 0;
}