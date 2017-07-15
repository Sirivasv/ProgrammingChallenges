//Div 2 C - Estructuras
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;
const int LOGN = 18;
const int INF = 1 << 30;
const int MINF = -INF;

int sparsePOS[MAXN][LOGN], sparseNEG[MAXN][LOGN], arr[MAXN], POS[MAXN], NEG[MAXN];
int logs[MAXN];
int N, Q;

void PRE() {
	logs[1] = 0;
	for (int i = 2; i < MAXN; ++i) logs[i] = logs[i >> 1] + 1;
	for(int i = 0; i < N; i++) {
		sparsePOS[i][0] = POS[i];
		sparseNEG[i][0] = NEG[i];
	}
	for(int i = 0; i < logs[N]; i++)
		for(int j = 0; j < N; j++) {
			sparsePOS[j][i + 1] = max(sparsePOS[j][i], sparsePOS[min(j + (1<<i), N - 1)][i]);
			sparseNEG[j][i + 1] = min(sparseNEG[j][i], sparseNEG[min(j + (1<<i), N - 1)][i]);
		}
}

int QueryPOS (int a, int b) {
	if(a == b) return sparsePOS[a][0];
	int L = logs[b - a + 1];
	return max(sparsePOS[a][L], sparsePOS[b - (1 << L) + 1][L]);
}

int QueryNEG (int a, int b) {
	if(a == b) return sparseNEG[a][0];
	int L = logs[b - a + 1];
	return min(sparseNEG[a][L], sparseNEG[b - (1 << L) + 1][L]);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> Q;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		POS[i] = MINF;
		NEG[i] = INF;
	}
	for (int i = 0; i < (N - 1); ++i) {
		if ((arr[i + 1] - arr[i]) > 0) POS[i] = i;
		if ((arr[i + 1] - arr[i]) < 0) NEG[i] = i;
	}

	PRE();

	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (a == b) {
			cout << "Yes\n";
		} else {
			b--;
			if (QueryPOS(a, b) < QueryNEG(a, b)) cout << "Yes\n";
			else cout << "No\n";
		}
	}

	return 0;
}