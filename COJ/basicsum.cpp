#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int I, J;
		cin >> I >> J;
		cout << (arr[J] - arr[I - 1]) << '\n';
	}
	return 0;
} 