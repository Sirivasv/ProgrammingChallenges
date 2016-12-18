#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

int N, M;
lli a, xi;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> xi;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	map<lli, lli> many;
	lli ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += many[xi ^ arr[i]];
		many[arr[i]]++;
	}
	cout << ans << '\n';
	return 0;
}