#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 109;
lli arr[MAXN];

int main() {
	arr[1] = 1;
	for (lli i = 2; i < MAXN; ++i)
		arr[i] = arr[i - 1] + (i * i);
	int N;
	while (cin >> N) {
		if (!N)
			break;
		cout << arr[N] << '\n';
	}
	return 0;
}