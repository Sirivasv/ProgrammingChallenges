#include <bits/stdc++.h>
using namespace std;

const int MAXD = 70;
const int MAXF = 3;

long long memo[MAXF][MAXD][MAXD];
int num[MAXD], LimN;

long long DP(int fl, int pos, int manyones) {
	if (pos == LimN)
		return manyones;
	if (memo[fl][pos][manyones] != -1)
		return memo[fl][pos][manyones];
	long long sum = 0;
	for (int i = 0; i < 2; ++i) {
		if ((i > num[pos]) && (!fl))
			break;
		sum += DP(fl || (i < num[pos]), pos + 1, manyones + i);
	}
	return memo[fl][pos][manyones] = sum;
}

void inToBinArr(long long x) {
	LimN = 0;
	while (x) {
		num[LimN++] = x % 2LL;
		x >>= 1;
	}
	reverse(num, num + LimN);
}

void Limpia() {
	for (int i = 0; i < MAXF; ++i)
		for (int j = 0; j < MAXD; ++j)
			for (int k = 0; k < MAXD; ++k)
				memo[i][j][k] = -1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	long long A, B;
	while (cin >> A >> B) {
		Limpia();
		A--;
		inToBinArr(A);
		long long ans = DP(0, 0, 0);
		Limpia();
		inToBinArr(B);
		ans = DP(0, 0, 0) - ans;
		cout << ans << '\n';
	}
	return 0;
}