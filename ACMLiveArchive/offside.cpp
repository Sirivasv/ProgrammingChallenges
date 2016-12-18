#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;

int arr[MAXN], darr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int A, D;
	while (cin >> A >> D) {
		if (!(A || D))
			break;
		for (int i = 0; i < A; ++i)
			cin >> arr[i];
		for (int i = 0; i < D; ++i)
			cin >> darr[i];
		sort(darr, darr + D);
		int cnt = 0;
		for (int i = 0; i < A; ++i) {
			if (arr[i] >= darr[1])
				continue;
			cnt++;
		}
		cout << ((cnt)?("Y\n"):("N\n"));
	}
	return 0;
}