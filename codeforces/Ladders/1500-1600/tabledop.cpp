#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 5;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < 3; ++i)
		cin >> arr[i];
	
	sort(arr, arr + 3);
	lli ans = 
	lli mint = min(arr[2] / 2LL, arr[0]);
	arr[2] -= mint * 2LL;
	arr[0] -= mint;
	ans += mint;
	if ((arr[0] >= 2) && arr[2]) {
		ans++;
		arr[0] -= 2LL;
		arr[2]--;
	}
	mint = min(arr[1] / 2LL, arr[0]);
	arr[1] -= mint * 2LL;
	arr[0] -= mint;
	ans += mint;
	if ((arr[0] >= 2) && arr[1]) {
		ans++;
		arr[0] -= 2LL;
		arr[1]--;
	}
	if (arr[2] < arr[1])
		swap(arr[2], arr[1]);
	mint = min(arr[2] / 2LL, arr[1]);
	ans += mint;
	arr[2] -= mint * 2LL;
	arr[1] -= mint;
	if ((arr[1] >= 2) && arr[2]) {
		ans++;
		arr[1] -= 2LL;
		arr[2]--;
	}
	if (arr[2] && arr[1] && arr[0])
		ans++;
	cout << ans << '\n';
	return 0;
}