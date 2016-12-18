#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5009;

int acum[MAXN];
int cub[15];

int HRep(int x) {
	for (int i = 0; i < 10; ++i)
		cub[i] = 0;
	while (x) {
		cub[x % 10]++;
		if (cub[x % 10] == 2)
			return 0;
		x /= 10;
	}
	return 1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 1; i <= 5000; ++i)
		acum[i] = acum[i - 1] + HRep(i);
	int A, B;
	while (cin >> A >> B) {
		cout << (acum[B] - acum[A - 1]) << '\n';
	}
	return 0;
}