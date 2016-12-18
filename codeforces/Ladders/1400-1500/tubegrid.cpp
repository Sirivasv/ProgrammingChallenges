#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 90000;

vector<pii> tubes[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, K;
	cin >> N >> M >> K;
	int cnt = 0;
	
	for (int i = 1; i <= N; ++i) {
		if (i & 1) {
			for (int j = 1; j <= M; ++j) {
				tubes[cnt / 2].push_back(pii(i, j));
				cnt++;
				if ((cnt / 2) == K)
					cnt--;
			}
		} else {
			for (int j = M; j >= 1; --j) {
				tubes[cnt / 2].push_back(pii(i, j));
				cnt++;
				if ((cnt / 2) == K)
					cnt--;
			}
		}
		if ((cnt / 2) == K)
			cnt--;
	}
	for (int i = 0; i < K; ++i) {
		cout << tubes[i].size() << ' ';
		for (int j = 0; j < tubes[i].size(); ++j) {
			if (j)
				cout << ' ';
			cout << tubes[i][j].first << ' ' << tubes[i][j].second;
		}
		cout << '\n';
	}
	return 0;
}