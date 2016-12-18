#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 10009;

pii dr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, S;
	cin >> S >> N;
	for (int i = 0; i < N; ++i)
		cin >> dr[i].first >> dr[i].second;
	sort(dr, dr + N);
	int ok = 1;
	for (int i = 0; i < N; ++i) {
		if (dr[i].first >= S) {
			ok = 0;
			break;
		}
		S += dr[i].second;
	}
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}