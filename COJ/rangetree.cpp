#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000009;
int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, mats = -1;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		arr[a]++;
		arr[b + 1]--;
	}
	int sum = 0;
	for (int i = 1; i < MAXN; ++i) {
		sum += arr[i];
		mats = max(sum, mats);
	}
	cout << mats << '\n';
	return 0;
}