#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 5;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli sum = 0;
	for (int i = 0; i < 3; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 3);
	cout << min(arr[0] + arr[1], sum / 3LL) << '\n';
	return 0;
}