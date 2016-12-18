#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;
const int LOGV = 21;

int distToRoot[MAXN], P[MAXN][LOGV];
char letter[MAXN];
int N;

char GetKthLetter(int u, int k) {
	for (int i = LOGV - 1; i >= 0; --i)
		if (distToRoot[P[u][i]] >= k)
			u = P[u][i];
	return letter[u];
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	
	int currN = 1;
	
	for (int i = 1; i <= N; ++i) {
		char op, v;
		int k;
		
		cin >> op;
		
		if (op == 'T') {
			cin >> v;
			letter[currN] = v;
			distToRoot[currN] = distToRoot[currN - 1] + 1;
			P[currN][0] = currN - 1;
			//UPD PARENTS
			for (int d = 1; d < LOGV; ++d)
				P[currN][d] = P[P[currN][d - 1]][d - 1];
			currN++;
		} else if (op == 'P') {
			cin >> k;
			cout << GetKthLetter(currN - 1, k + 1) << '\n';
		} else {
			cin >> k;
			distToRoot[currN] = distToRoot[currN - k - 1];
			letter[currN] = letter[currN - k - 1];
			P[currN][0] = currN - k - 1;
			//UPD Parents
			for (int d = 1; d < LOGV; ++d)
				P[currN][d] = P[P[currN][d - 1]][d - 1];
			currN++;
		}
		
	}
	
	return 0;
}