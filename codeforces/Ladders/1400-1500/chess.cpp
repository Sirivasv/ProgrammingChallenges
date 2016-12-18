#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
int N;

const int MAXN = 2009;

lli mtr[MAXN][MAXN], mtrDD[MAXN][MAXN];

void ProcessA(int OI, int OJ) {
	int I = OI;
	int J = OJ;
	lli sum = 0;
	do {
		sum += mtr[I][J];
		I++; J++;
	} while ((I >= 0) && (I < N) && (J >= 0) && (J < N));
	I = OI;
	J = OJ;
	do {
		mtrDD[I][J] += sum;
		I++; J++;
	} while ((I >= 0) && (I < N) && (J >= 0) && (J < N));
}

void ProcessB(int OI, int OJ) {
	int I = OI;
	int J = OJ;
	lli sum = 0;
	do {
		sum += mtr[I][J];
		I++; J--;
	} while ((I >= 0) && (I < N) && (J >= 0) && (J < N));
	I = OI;
	J = OJ;
	do {
		mtrDD[I][J] += sum;
		I++; J--;
	} while ((I >= 0) && (I < N) && (J >= 0) && (J < N));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> mtr[i][j];
	//Primer repason de brocha
	for (int i = 0; i < N; ++i) {
		ProcessA(0, i);
		ProcessB(0, i);
	}
	for (int i = 1; i < N; ++i) {
		ProcessA(i, 0);
		ProcessB(i, N - 1);
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			mtrDD[i][j] -= mtr[i][j];
	lli matsw = -1, matsb = -1;
	int xw, yw, xb, yb;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (i & 1) {
			for (int j = N - 1; j >= 0; --j) {
				if (cnt & 1) { //negr
					if (mtrDD[i][j] >  matsb) {
						matsb = mtrDD[i][j];
						xb = i + 1;
						yb = j + 1;
					}
				} else {
					if (mtrDD[i][j] >  matsw) {
						matsw = mtrDD[i][j];
						xw = i + 1;
						yw = j + 1;
					}
				}
				cnt++;
			}
		}  else {
			for (int j = 0; j < N; ++j) {
				if (cnt & 1) { //negr
					if (mtrDD[i][j] >  matsb) {
						matsb = mtrDD[i][j];
						xb = i + 1;
						yb = j + 1;
					}
				} else {
					if (mtrDD[i][j] >  matsw) {
						matsw = mtrDD[i][j];
						xw = i + 1;
						yw = j + 1;
					}
				}
				cnt++;
			}
		}
	}
	
	cout << (matsb + matsw) << '\n';
	cout << xb << ' ' << yb << ' ' << xw << ' ' << yw << '\n';
	return 0;
}