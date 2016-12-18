#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

typedef pair<int, int> pii;
pii arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	K--;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].first >> arr[i].second;
		arr[i].first *= -1;
	}
	sort(arr, arr + N);
	
	pii lp = pii(-100, -1);
	int ans = 0, found = 0;
	for (int i = 0; i < N; ++i) {
		//cout << -arr[i].first << ' ' << arr[i].second << '\n';
		if (arr[i] > lp) {
			if (found) {
				found = 0;
				break;
			}
			ans = 0;
		}
		if (i == K)
			found = 1;
		ans++;
		lp = arr[i];
	}
	cout << ans << '\n';
 	return 0;
}