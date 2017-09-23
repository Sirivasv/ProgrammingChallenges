#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109;
const int MAXM = 209;

int idN, idM, ID, DParrN[MAXN], DParrM[MAXM], memo[MAXN][MAXM], flag[MAXN][MAXM];

int DP(int ide, int idc) {
	if (ide == idN) return 1;
	if (flag[ide][idc] == ID) return memo[ide][idc];
	flag[ide][idc] = ID;
	int res = 0;
	for (int i = idc; i < idM; ++i)
		if (DParrN[ide] <= DParrM[i]) 
			res |= DP(ide + 1, i + 1);
	return memo[ide][idc] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		map<int, int> mpN, mpM;
		for (int i = 0; i < N; ++i) {
			int val;
			cin >> val;
			mpN[val]++;
		}
		for (int i = 0; i < M; ++i) {
			int val;
			cin >> val;
			mpM[val]++;
		}
		idN = idM = 0;
		for (auto it = mpN.begin(); it != mpN.end(); ++it) DParrN[idN++] = it->second;
		for (auto it = mpM.begin(); it != mpM.end(); ++it) DParrM[idM++] = it->second;
		ID++;
		if (DP(0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}