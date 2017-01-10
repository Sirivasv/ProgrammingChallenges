#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;

int Narr[MAXN], Marr[MAXN], F[MAXN], N, M;

void preKMP() {
	F[0] = -1; int j = -1, p = M;
	for (int i = 0; i < p; ++i) {
		while (Marr[i] != Marr[j] && j >= 0) j = F[j];
		F[i + 1] = ++j;
	}
}

int searchKMP() {
	int matches = 0, t = N, p = M;
	for (int i = 0, j = 0; i < t; ++i) {
		while (Narr[i] != Marr[j] && j >= 0) j = F[j];
		if (++j == p) {
			matches++;
			j = F[j];
		}
	}
	return matches;
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	int pval, cval;
	
	for (int i = 0; i < N; ++i) {
		scanf("%d", &cval);
		if (i) Narr[i - 1] = cval - pval;
		pval = cval;
	}
	
	for (int i = 0; i < M; ++i) {
		scanf("%d", &cval);
		if (i) Marr[i - 1] = cval - pval;
		pval = cval;
	}
	
	if (M == 1) printf("%d\n", N);
	else if (N == 1) printf("0\n");
	else {
		N--; M--;
		preKMP();
		printf("%d\n", searchKMP());
	}
	
	return 0;
}