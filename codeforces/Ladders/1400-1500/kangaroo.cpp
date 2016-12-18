#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 500009;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	lli n;
	
	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	sort(arr, arr + n);
	
	int lim = n / 2LL;
	int fin = lim, ans = 0;
	
	for(int i = 0; i < lim; ++i) {
		while (fin < n) {
			if ((arr[i] * 2LL) <= arr[fin]) {
				ans++;
				break;
			}
			fin++;
		}
		fin++;
	}
	
	cout << (n - ans) << '\n';
	
	return 0;
}

//50;
/*
8 4 2 1
8 4 2 2
8 5 4 2
*/