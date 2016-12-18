#include <bits/stdc++.h>
using namespace std;

const int MAXC = 1000009;

int F[MAXC];
int lp[MAXC];
int luno[MAXC];
int Pos[MAXC];
int PosT[MAXC];
string P, T;

void CPos() {
	for (int i = 0; i < 26; ++i)
		lp[i] = -1;
	int lim = P.size();
	for (int i = 0; i < lim; ++i) {
		if (lp[P[i] - 'a'] == -1)
			Pos[i] = 0;
		else
			Pos[i] = i - lp[P[i] - 'a'];
		lp[P[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; ++i)
		lp[i] = -1;
	lim = T.size();
	for (int i = 0; i < lim; ++i) {
		if (lp[T[i] - 'a'] == -1)
			PosT[i] = 0;
		else
			PosT[i] = i - lp[T[i] - 'a'];
		lp[T[i] - 'a'] = i;
	}
}

void CF() {
	F[0] = -1;
	for (int i = 0, j = -1; P[i]; ) {
		while (~j && (((Pos[i]) != (Pos[j])) && (!((((Pos[i])) > (j)) && (Pos[j] == 0))))) j = F[j];
		F[++i] = ++j;
	}
}

int mch = 0;
int w = 0;
void KMPSearch() {
	int i = 0, j = 0;
	while (i < T.size()) {
		while (j >= 0 && (((PosT[i]) != (Pos[j])) && (!((((PosT[i])) > (j)) && (Pos[j] == 0))))) j = F[j];
		
		i++, j++;
		
		if (j == P.size()) {
			w = i - j;
			mch++;
			j = F[j];
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> T >> P;
	CPos();
	CF();
	KMPSearch();
	if (mch == 1)
		cout << T.substr(w, P.size()) << '\n';
	else
		cout << mch << '\n';
	return 0;
}