#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int>pii;

const int MAXA = 25;
const int MAXN = 1300;
const pii MU = pii(-1, -1);

int A, M;
int MN[MAXN], C[MAXA][MAXN], ANS[MAXA];

pii memo[MAXA][MAXN];

pii DP(int ida, int llevas) {
	if (ida == A)
		return pii(0, -llevas);
	if (memo[ida][llevas] != MU)
		return memo[ida][llevas];
	pii res = pii(0, -llevas);
	int acum = 0;
	for (int tkn = 0; tkn <= MN[ida]; ++tkn) {
		if (tkn)
			acum += C[ida][tkn - 1];
		if ((tkn + llevas) > M)
			break;
		pii ndp = DP(ida + 1, llevas + tkn);
		ndp.first += (10 * tkn) - acum;
		res = max(res, ndp);
	}
	return memo[ida][llevas] = res;
}

void RECON(int ida, int llevas) {
	if (ida == A)
		return;
	if (memo[ida][llevas] == pii(0, -llevas))
		return;
	int acum = 0;
	for (int tkn = 0; tkn <= MN[ida]; ++tkn) {
		if (tkn)
			acum += C[ida][tkn - 1];
		if ((tkn + llevas) > M)
			break;
		pii ndp = DP(ida + 1, llevas + tkn);
		ndp.first += (10 * tkn) - acum;
		if (memo[ida][llevas] == ndp) {
			ANS[ida] = tkn;
			RECON(ida + 1, llevas + tkn);
			return;
		}
	}
	return;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> A >> M;
	for (int i = 0; i <= A; ++i)
		for (int j = 0; j <= M; ++j)
			memo[i][j] = MU;
	for (int i = 0; i < A; ++i) {
		cin >> MN[i];
		for (int j = 0; j < MN[i]; ++j)
			cin >> C[i][j];
	} 
	pii res = DP(0, 0);
	RECON(0, 0);
	cout << res.first << ' ' << (-res.second) << '\n';
	for (int i = 0; i < A; ++i) {
		if (i)
			cout << ' ';
		cout << ANS[i];
	}
	cout << '\n';
	return 0;
}