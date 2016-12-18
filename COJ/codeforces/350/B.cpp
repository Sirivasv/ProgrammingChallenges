#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
int ids[MAXN];
long long values[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> ids[i];
	for (long long i = 1; i < MAXN; ++i) values[i] = values[i - 1] + i;
	int idx = lower_bound(values, values + MAXN, k) - values;
	cout << ids[k - values[idx - 1] - 1] << '\n';
	return 0;
}