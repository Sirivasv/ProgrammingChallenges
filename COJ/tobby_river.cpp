#include <cstdio>
//#include <bits/stdc++.h>
//using namespace std;
const int MAXN = 609;
int A[10], memo[10][MAXN];

bool Can(int id, int x) {
	//cout << id << " ** " << x << '\n';
	if (memo[id][x] != -1) return memo[id][x];
	if (id == 5) return memo[id][x] = ((x == 0) || (x - A[id] == 0));
	memo[id][x] = Can(id + 1, x);
	if (A[id] <= x)
		memo[id][x] |= Can(id + 1, x - A[id]);
	return memo[id][x];
}

void Limpia() {
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j <= MAXN; ++j) memo[i][j] = -1;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int sum = 0;
		for (int i = 0; i < 6; ++i) {
			scanf("%d", &A[i]);
			sum += A[i];
		}
		if (sum & 1) {
			printf("Tobby no puede cruzar\n");
			continue;
		}
		Limpia();
		sum >>= 1;
		//cout << sum << '\n';
		if (Can(0, sum)) printf("Tobby puede cruzar\n");
		else printf("Tobby no puede cruzar\n");
	}
	return 0;
}