#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int arr[MAXN], cub[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, B;
	while (cin >> N >> B) {
		if (!(N || B))
			break;
		for (int i = 0; i < B; ++i)
			cin >> arr[i];
		for (int i = 0; i <= N; ++i)
			cub[i] = 0;
		for (int i = 0; i < B; ++i)
			for (int j = 0; j < B; ++j)
				cub[(int)fabs(arr[i] - arr[j])] = 1;
		int fl = 1;
		for (int i = 0; i <= N; ++i)
			fl &= cub[i];
		cout << ((fl)?("Y\n"):("N\n"));
	}
	return 0;
}