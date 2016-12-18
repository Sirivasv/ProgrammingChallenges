#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;

int BIT[MAXN];

void Update(int id) {
	while (id < MAXN) {
		BIT[id]++;
		id += (id & (-id));
	}
}

int Query(int id) {
	int res = 0;
	while (id) {
		res += BIT[id];
		id -= (id & (-id));
	}
	return res;
}

int Range(int I, int J) {
	return (Query(J) - Query(I - 1));
}

pii Ari[MAXN];
int ans[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> Ari[i].first;
		Ari[i].second = -(i + 1);
	}
	sort(Ari, Ari + N, greater<pii>());
	for (int i = 0; i < N; ++i) {
		ans[(-Ari[i].second) - 1] = Range(-Ari[i].second, MAXN - 1);
		Update(-Ari[i].second);
	}
	for (int i = 0; i < N; ++i) {
		if (i)
			cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}