#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int LOGN = 20;
const int MAXN = 100009;
const lli MINF = -(1LL << 60);

lli memo[MAXN][4];
lli SPMI[MAXN][LOGN];
lli A[MAXN];
int N, K;
int logs[MAXN];

void pre() {
    for(int i = 2; i <= N; i++) logs[i] = logs[i / 2] + 1;
    for(int i = 0; i < N; i++) SPMI[i][0] = A[i];
    
    for(int i = 0; i < logs[N]; i++)
        for(int j = 0; j < N; j++)
            SPMI[j][i + 1] = min(SPMI[j][i], SPMI[min(j + (1 << i), N - 1)][i]);
}

lli queryMI(int a, int b) {
    if(a == b) return SPMI[a][0];
    int L = logs[b - a + 1];
    return min(SPMI[a][L], SPMI[b - (1 << L) + 1][L]);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> A[i];
	pre();

	for (int cuantos = 1; cuantos <= N; ++cuantos) memo[cuantos][1] = queryMI(0, cuantos - 1);

	for (int ki = 2; ki <= K; ++ki)
		for (int cuantos = 1; cuantos <= N; ++cuantos) {
			lli ans = MINF;
			for (int tomaste = 1; tomaste < cuantos; ++tomaste)
				ans = max(ans, memo[cuantos - tomaste][(ki - 1) % 2] + queryMI(cuantos - 1, cuantos - tomaste));
			memo[cuantos][ki % 2] = ans;
		}

	cout << memo[N][K % 2] << '\n';
	return 0;
}