#include<bits/stdc++.h>
using namespace std;
const int MAXN = 50009;
typedef pair<int, int> pii;
typedef pair<pii, char> piic;

piic examinee[MAXN];
int acum[MAXN];

inline int Find(int x, int N) {
	int ini = 0, fin = N, mid, ans = N;
	while (ini <= fin) {
		mid = (ini + fin) >> 1;
		if (examinee[mid].first.first > x) {
			ans = mid;
			fin = mid - 1;
		} else ini = mid + 1;
	}
	return ans;
}

inline void Count(int N) {
	int ans = 0;
	acum[N] = 0;
	for (int i = N - 1; i >= 0; --i)
		acum[i] = acum[i + 1] + (int)(examinee[i].first.second && (examinee[i].second == 'c'));
	for (int i = 0; i < N; ++i)
		if ((examinee[i].first.second == 0) && (examinee[i].second == 'i')) ans += acum[Find(examinee[i].first.first, N)];
	cout << ans << '\n';
	return ;
}

int main() {
	int T, Q;
	cin >> T;
	while (T--) {
		cin >> Q;
		for (int i = 0; i < Q; ++i)
			cin >> examinee[i].first.first >> examinee[i].first.second >> examinee[i].second;
		sort(examinee, examinee + Q);
		Count(Q);
	}
	return 0;
}