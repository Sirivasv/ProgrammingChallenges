#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 5009;

pii arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) 
		cin >> arr[i].first >> arr[i].second;
	lli mint = -1;
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i) {
		if (arr[i].second >= mint) {
			mint = arr[i].second;
			continue;
		}
		mint = arr[i].first;
	}
	cout << mint << '\n';
	return 0;
}