#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 2000009;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N;
	
	cin >> N;
	
	for (int i = 1; i <= N; ++i) cin >> arr[i];
	
	sort(arr + 1, arr + N + 1, greater<int>());
	
	for (int i = 1; i <= N; ++i) arr[i] += arr[i - 1];
	
	int pot = 1;
	lli sum = 0;
	
	while (pot <= N) {
		sum += arr[pot];
		pot *= 4;
	}
	
	cout << sum << '\n';
	
	return 0;
}