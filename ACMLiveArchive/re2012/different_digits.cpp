#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5009;
int acum[MAXN];
bitset<15> digs;

int nrep(int x) {
	digs.reset();
	while (x) {
		if (digs[x % 10]) 
			return 0;
		digs[x % 10] = 1;
		x /= 10;
	}
	return 1;
}

void Pre() {
	for (int i = 1; i < MAXN; ++i)
		acum[i] = acum[i - 1] + nrep(i);
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, M;
	Pre();
	while (cin >> N >> M) {
		cout << acum[M] - acum[N - 1] << '\n';
	}
	return 0;
}