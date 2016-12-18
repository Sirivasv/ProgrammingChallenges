#include <bits/stdc++.h>
using namespace std;
const int MAXD = 15;
const int MAXS = 100;
int tamA;
int nA[MAXD];
long long memo[MAXD][4][MAXS];


long long DP(int id, int fl, int sum) {
	if (id == tamA)
		return (long long)sum;
	if (memo[id][fl][sum] != -1)
		return memo[id][fl][sum];
	long long ans = 0;
	for (int i = 0; i < 10; ++i) {
		if (fl) {
			ans += DP(id + 1, fl, sum + i);
		} else if (i < nA[id]){
			ans += DP(id + 1, 1, sum + i);
		} else  if (i == nA[id]) {
			ans += DP(id + 1, 0, sum + i);
		}
	}
	return memo[id][fl][sum] = ans;
}

void Calc(long long X) {
	tamA = 0;
	if (X == 0) {
		nA[0] = 0;
		tamA++;
	}
	while (X) {
		nA[tamA++] = (X % 10LL);
		X /= 10LL;
	}
	reverse(nA, nA + tamA);
	//for (int i = 0; i < tamA; ++i)
		//cout << nA[i] << ' ';
	//cout << '\n';
}

void Limpia() {
	for (int i = 0; i < MAXD; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < MAXS; ++k)
				memo[i][j][k] = -1;
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long long A, B;
	cin >> A >> B;
	A = max(0LL, A - 1);
	Calc(A);
	Limpia();
	long long ansA = DP(0, 0, 0);
	Calc(B);
	Limpia();
	//cout << tamA << '\n';
	long long ansB = DP(0, 0, 0);
	cout << ansB - ansA << '\n';
	return 0;
}
