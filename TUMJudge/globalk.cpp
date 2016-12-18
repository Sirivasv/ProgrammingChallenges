#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
long long arr[MAXN];
int val[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	long long K;
	int N;
	val[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		val[i] = (val[i - 1] << 1);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int fullm = 1 << N;
	int pos = 0;
	for (int i = 1; i < fullm; ++i) {
		long long sum = 0;
		cout << i << '\n';
		for(int j = 0; val[j] <= i; ++j) {
			if (i & val[j])
				sum += arr[j];
			cout << ((i & val[j]) > 0) << ' ';
		}
		cout << sum << '\n';
		cout << '\n';
		if ((K % sum) == 0) {
			pos = 1;
			break;
		}
	}
	if (pos)
		cout << "possible\n";
	else
		cout << "impossible\n";
	return 0;
}