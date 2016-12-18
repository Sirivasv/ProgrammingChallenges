#include <bits/stdc++.h>
using namespace std;

const int MAXS = 10;
const int MAXD = 10;
const int MAXF = 3;
const int MAXFZ = 3;

int memo[MAXF][MAXFZ][MAXD][MAXS];
int num[MAXD];
int digb, limN;

int DP(int fl, int fz, int pos, int sum) {
	if (pos == limN)
		return sum;
	if (memo[fl][fz][pos][sum] != -1)
		return memo[fl][fz][pos][sum];
	int res = 0;
	for (int i = 0; i < 10; ++i) {
		if ((i > num[pos]) && (!fl))
			break;
		int benef = (i == digb);
		if ((digb == 0) && fz && (i == digb))
			benef = 0;
		res += DP((fl || (i < num[pos])), (fz && (i == 0)), pos + 1, sum + benef);
	}
	return memo[fl][fz][pos][sum] = res;
}

void Limpia() {
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for (int k = 0; k < MAXD; ++k)
				for (int l = 0; l < MAXS; ++l)
					memo[i][j][k][l] = -1;
}

int mnA[MAXD];

void inToArr(int x) {
	limN = 0;
	while (x) {
		num[limN++] = x % 10;
		x /= 10;
	}
	reverse(num, num + limN);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int A, B;
	while (cin >> A >> B) {
		if (!(A + B))
			break;
		A--;
		inToArr(A);
		for (int i = 0; i < 10; ++i) {
			Limpia();
			digb = i;
			mnA[i] = DP(0, 1, 0, 0);
		}
		inToArr(B);
		for (int i = 0; i < 10; ++i) {
			Limpia();
			digb = i;
			if (i)
				cout << ' ';
			cout << (DP(0, 1, 0, 0) - mnA[i]);
		}
		cout << '\n';
	}
	return 0;
}