#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int arr[5];

lli Abs(int x) { return ((x < 0)?(-x):(x)); }

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < 4; ++i)
		cin >> arr[i];
	sort(arr, arr + 4);
	lli mint = (1LL << 60);
	do {
		mint = min(mint, Abs((arr[0] + arr[1]) - (arr[3] + arr[2])));
	} while(next_permutation(arr, arr + 4));
	cout << mint << '\n';
	return 0;
}