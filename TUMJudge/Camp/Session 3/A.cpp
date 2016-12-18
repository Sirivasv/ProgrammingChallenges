#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;

int arr[MAXN];

bool IsIland(int ini, int fin) {
	for (int i = ini; i <= fin; ++i)
		if ((arr[i] <= arr[ini - 1]) || (arr[i] <= arr[fin + 1]))
			return false;
	return true;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int tmp;
		cin >> tmp;
		for (int i = 0; i < 12; ++i)
			cin >> arr[i];
		int cnt = 0;
		for (int ini = 1; ini <= 10; ++ini)
			for (int fin = ini; fin <= 10; ++fin)
				if (IsIland(ini, fin))
					cnt++;
		cout << tmp << ' ' << cnt << '\n';
	}
	return 0;
}