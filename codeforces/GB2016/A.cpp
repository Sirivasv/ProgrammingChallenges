#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K;
	cin >> N >> K; 
	
	int havt = 240 - K, ans = 0;
	
	for (int i = 1; i <= N; ++i) {
		if ((havt - (5 * i)) >= 0) {
			havt -= (5 * i);
			ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}