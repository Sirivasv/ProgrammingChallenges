#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
bitset<MAXN> tout;
int arr[MAXN];

int Abs(int x) {
	return x < 0 ? -x : x;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, M;
	while (cin >> N >> M) {
		if (!(N + M)) break;
		tout.set();
		for (int i = 0; i < M; ++i)
			cin >> arr[i];
		for (int i = 0; i < M; ++i)
			for (int j = i; j < M; ++j)
				tout[Abs(arr[i] - arr[j])] = 0;
		int val = 1;
		for (int i = 0; i <= N; ++i)
			val &= !tout[i];
		if (val) 
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}