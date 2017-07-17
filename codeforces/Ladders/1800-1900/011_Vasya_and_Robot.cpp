#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MAXN = 1000009;

int N;
lli wi[MAXN];
lli l, r, Ql, Qr;

lli getRange (int i, int j) {
	return wi[j] - wi[i - 1];
}

lli getCost(lli manyL) {
	lli manyR = N - manyL;
	lli sumL = ((manyL) ? (getRange(1, manyL) * l) : 0);
	lli sumR = ((manyR) ? (getRange(N - manyR + 1, N) * r) : 0);
	lli sumQ = 0;
	if (manyL > manyR) sumQ = Ql * (manyL - manyR - 1LL);
	if (manyR > manyL) sumQ = Qr * (manyR - manyL - 1LL);
	return sumL + sumR + sumQ;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> l >> r >> Ql >> Qr;
	for (int i = 1; i <= N; ++i) {
		cin >> wi[i];
		wi[i] += wi[i - 1];
	}
	lli mint = 1LL << 60;
	for (int i = 0; i <= N; ++i)
		mint = min(mint, getCost(i));
	cout << mint << '\n';
	return 0;
}