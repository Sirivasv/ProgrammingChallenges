#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull; 

const int MAXN = 4000005;

const int MAXC = 2009;

ull MOD = 1000000007LL;

ull B = 71LL, HB[MAXN];

char Pa[MAXC][MAXC], Te[MAXC][MAXC];
ull HPa[MAXC][MAXC], HTe[MAXC][MAXC], PB[MAXC][MAXC];


ull F(char a) {
	if (a == 'x')
		return 3LL;
	return 7LL;
}

ull Mult(ull a, ull b) {
	/*ull result = 0;
	for (; b; b >>= 1) {
		if (b & 1) result = (result + a) % MOD;
		a = (a + a) % MOD;
	}
	return result;
	*/
	return (a * b) % MOD;
}

void CB() {
	HB[0] = 1LL;
	for (int i = 1; i < MAXN; ++i)
		HB[i] = Mult(HB[i - 1], B);
}

void MhashP(int limc, int limf, int limct) {
	int ori = limct - limc + 1;
	//cout << "P: \n";
	for (int i = 1; i <= limf; ++i) {
		ull acum = 0;
		for (int j = ori; j <= limct; ++j) {
			acum = Mult(acum, B);
			if ((j - (limct - limc)) >= 1) {
				acum = (acum + F(Pa[i - 1][(j - (limct - limc)) - 1])) % MOD;
			}
			//cout << i << ' ' << j << '\n';
			HPa[i][j] = Mult(HPa[i - 1][j], HB[j]);
			HPa[i][j] = (HPa[i][j] + acum) % MOD;
		}
		ori = 1;
	}
}


ull Euclides(ull a, ull b, ull& x, ull& y) {
    if (!b) { x = 1, y = 0; return a; }
    ull gcd = Euclides(b, a % b, x, y);
    x = !MOD? x - y * (a / b):
        (MOD + x - (y * (a / b)) % MOD) % MOD;
    swap(x, y);
    return gcd;
}

ull InvMod(ull xv) {
	ull res, tmpy;
	Euclides(xv, MOD, res, tmpy);
	return res;
}

void MhashT(int limc, int limf) {
	int cnt = 0, lim = (limc * limf) - 1;
	for (int i = 1; i <= limf; ++i) {
		ull acum = 0;
		for (int j = 1; j <= limc; ++j) {
			acum = (acum + Mult(F(Te[i - 1][j - 1]), HB[lim - cnt])) % MOD;
			//cout << i << ' ' << j << ' ' << ' ' << (lim - cnt) << '\n';
			PB[i][j] = HB[lim - cnt];
			HTe[i][j] = (HTe[i - 1][j] + acum) % MOD;
			cnt++;
		}
	}
}

ull Subs2D(int xi, int yi, int xj, int yj) {
	//cout << xi << ' ' << yi << ' ' << xj << ' ' << yj << '\n';
	ull vall = HTe[yj][xi - 1];
	ull valu = HTe[yi - 1][xj];
	ull vald = HTe[yi - 1][xi - 1];
	//cout << HTe[yj][xj] << ' ' << vall << ' ' << valu << ' ' << vald << ' ' << PB[yj][xj] <<'\n';
	//cout << Mult(((((((HTe[yj][xj] - vall + MOD) % MOD) - valu + MOD) % MOD) + vald + MOD) % MOD), PB[yj][xj]) << '\n';
	return ((((((HTe[yj][xj] - vall + MOD) % MOD) - valu + MOD) % MOD) + vald + MOD) % MOD);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	CB();
	int limfp, limcp, limft, limct;
	cin >> limfp >> limcp >> limft >> limct;
	for (int i = 0; i < limfp; ++i)
		for (int j = 0; j < limcp; ++j)
			cin >> Pa[i][j];
	for (int i = 0; i < limft; ++i)
		for (int j = 0; j < limct; ++j)
			cin >> Te[i][j];
	MhashP(limcp, limfp, limct);
	MhashT(limct, limft);
	//cout << HPa[limfp][limct] << '\n';
	int ans = 0;
	for (int i = 1; i <= limft; ++i) {
		for (int j = 1; j <= limct; ++j) {
			if (((i + limfp - 1) <= limft) && ((j + limcp - 1) <= limct)) {
				//cout << "** " << Subs2D(j, i, j + limcp - 1, i + limfp - 1) << '\n';
				if (Subs2D(j, i, j + limcp - 1, i + limfp - 1) == Mult(HPa[limfp][limct], PB[i + limfp - 1][j + limcp - 1]))
					ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}