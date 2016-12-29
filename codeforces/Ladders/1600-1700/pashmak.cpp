#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 1000009;

int arr[MAXN];

lli BIT[MAXN];

lli Sum(int idx) {
	lli res = 0;
	if (idx <= 0) return res; 
	while (idx) {
		res += BIT[idx];
		idx -= (idx & (-idx));
	}
	return res;
}

void Update(int idx, lli val) {
	if (idx <= 0) return;
	while (idx < MAXN) {
		BIT[idx] += val;
		idx += (idx & (-idx));
	}
}

map<int, int> rl, lr;

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	scanf("%d", &N);
	//cin >> N;
	for (int i = 0; i < N; ++i) {
		//cin >> arr[i];
		scanf("%d", &arr[i]);
		lr[arr[i]]++;
	}
	
	lli ans = 0;
	
	for (int i = N - 1; i > 0; --i) {
		rl[arr[i]]++;
		lr[arr[i]]--;
		Update(rl[arr[i]], 1);
		ans += Sum(lr[arr[i - 1]] - 1);
	}
	
	//cout << ans << '\n';
	
	printf("%lld\n", ans);
	
	return 0;
}