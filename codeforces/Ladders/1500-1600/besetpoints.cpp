#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	int lim = min(N, M);
	cout << (lim + 1) << '\n';
	for (int i = 0; i <= lim; ++i)
		cout << i << ' ' << (lim - i) << '\n';
	return 0;
}