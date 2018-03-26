#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100000;

lli BIT[MAXN], BIT2[MAXN];
int N;

lli Sum(int id) {
	lli res = 0;
	while (id) {
		res += BIT[id];
		id -= id&(-id);	
	}
	return res;
}

lli Update(int id, lli val) {
	while (id < MAXN) {
		BIT[id] += val;
		id += id&(-id);
	}
}

lli Sum2(int id) {
	lli res = 0;
	while (id) {
		res += BIT2[id];
		id -= id&(-id);	
	}
	return res;
}

lli Update2(int id, lli val) {
	while (id < MAXN) {
		BIT2[id] += val;
		id += id&(-id);
	}
}

lli ansIzq[MAXN];
int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int col;
	cin >> N;
	
	for (int i = 0; i < N; ++i) {		
		cin >> arr[i];
		ansIzq[i] = Sum(N + 1 - arr[i]);
		Update(N + 1 - arr[i], 1LL);	
	}
	
	lli res = 0;
	for (int i = N - 1; i >= 0; --i) {
		res += Sum2(arr[i]) * ansIzq[i];
		Update2(arr[i], 1LL);
	}	
	
	cout << res << '\n';

	return 0;
}
