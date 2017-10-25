#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10009;

string P[MAXN];

int DIFF(int A, int B) {
	int cnt = 0;
	for (int i = 0; i < 20; ++i) 
		cnt += (P[A][i] != P[B][i]);
	return cnt;
} 

int getSum(int I, int J, int K) {
	return DIFF(I, J) + DIFF(I, K) + DIFF(J, K);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		for (int i = 0; i < N; ++i) cin >> P[i];
		sort(P, P + N);
		int SUMT = 1000000;
		string ansA, ansB, ansC;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				for (int k = j + 1; k < N; ++k) {
					if ((P[i] == P[j]) || (P[i] == P[k]) || (P[j] == P[k])) continue;
					int val = getSum(i, j, k);
					if (val < SUMT) {
						SUMT = val;
						ansA = P[i];
						ansB = P[j];
						ansC = P[k];
					}
				}
			}
		}
		cout << SUMT << '\n';
		cout << ansA << '\n'; 
		cout << ansB << '\n'; 
		cout << ansC << '\n'; 
	}

	return 0;
}