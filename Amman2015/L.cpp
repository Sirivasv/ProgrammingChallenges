#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400009;
const int INF = 1000009; 
string S;
int N, K, ST[MAXN];

void Update(int pos, int val, int n = 1, int L = 1, int R = N + 1) {
	if ((L >= pos) && (R <= pos)) {
		ST[n] = val;
		return;
	}
	if ((R < pos) || (pos < L)) return;
	int lc = n << 1; int rc = lc + 1; int m = (L + R) >> 1;
	Update(pos, val, lc, L, m);
	Update(pos, val, rc, m + 1, R);
	ST[n] = min(ST[lc], ST[rc]);
}

int Query(int l, int r, int n = 1, int L = 1, int R = N + 1) {
	if ((L >= l) && (R <= r)) return ST[n];
	if ((R < l) || (L > r)) return INF;
	int lc = n << 1; int rc = lc + 1; int m = (L + R) >> 1;
	return min(Query(l, r, lc, L, m), Query(l, r, rc, m + 1, R));
}

int getID[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		cin >> S;
		int lim = S.size();
		int curr = N + 1; 
		for (int i = lim; i > 1; --i){
			getID[i] = curr;
			//cout << getID[i] << ' ';
			if (S[i - 1] == S[i - 2]) curr = i;
		}
		getID[1] = curr;
		//cout << getID[1] << '\n';
		Update(N + 1, 0);
		for (int i = N; i >= 1; --i) {
			int res = Query(i + 1, i + 1) + 1;
			//cout << res << ' ' << '\n';
			int right_lim = min(N, i + K - 1);
			int left_lim = getID[i];
			if (left_lim <= right_lim) res = min(res, Query(left_lim + 1, right_lim + 1) + 1);
			Update(i, res);
		}
		cout << Query(1, 1) - 1 << '\n';
	}
	return 0;
}