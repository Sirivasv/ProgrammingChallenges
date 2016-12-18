#include <bits/stdc++.h>
using namespace std;

const int MAXN = 309;

long long mtr[MAXN][MAXN];
long long rowacum[MAXN];
long long rowacumans[MAXN];
long long colacum[MAXN];
long long colacumans[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		bool fcorrect = true;
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i)
			rowacum[i] = colacum[i] = rowacumans[i] = colacumans[i] = 0;
		
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j) {
				long long tmp;
				cin >> tmp;
				mtr[i][j] = tmp;
				rowacum[i] += tmp;
				colacum[j] += tmp;
			}
		
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j) {
				long long tmp;
				cin >> tmp;
				rowacumans[i] += tmp;
				colacumans[j] += tmp;
			}
		for (int i = 1; i <= N; ++i) {
			long long acumtest = 0;
			for (int j = 1; j <= N; ++j)
				acumtest += mtr[i][j] * rowacum[j];
			
			if (acumtest != rowacumans[i]) {
				fcorrect = false;
				break;
			}
			acumtest = 0;
			for (int j = 1; j <= N; ++j)
				acumtest += mtr[j][i] * colacum[j];
			
			if (acumtest != colacumans[i]) {
				fcorrect = false;
				break;
			}
		}
		cout << "Case #" << nc << ": " << ((fcorrect)?("YES\n"):("NO\n"));
	}
	return 0;
}