#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = (1LL << 34);
const int MAXN = 100009;

ll arr[MAXN];
ll base[MAXN];
ll ST[MAXN * 3];
vector<pll> lvl[MAXN];

int N, M;
void Build(int n = 1, int l = 1, int r = N + 1) {
	if (l == r) {
		ST[n] = base[l];
		return;
	}
	int ls = n << 1, rs = ls + 1, m = (l + r) >> 1;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = min(ST[ls], ST[rs]);
}

void Update(int L, ll val, int n = 1, int l = 1, int r = N + 1) {
	int R = L;
	if ((l > R) || (r < L))
		return;
	if ((l >= L) && (r <= R )) {
		ST[n] = val;
		return;
	}
	int ls = n << 1, rs = ls + 1, m = (l + r) >> 1;
	Update(L, val, ls, l, m);
	Update(L, val, rs, m + 1, r);
	ST[n] = min(ST[ls], ST[rs]);
}

ll Query(int L, int R, int n = 1, int l = 1, int r = N + 1) {
	if ((l > R) || (r < L))
		return INF;
	if ((l >= L) && (r <= R ))
		return ST[n];
	int ls = n << 1, rs = ls + 1, m = (l + r) >> 1;
	ll vl = Query(L, R, ls, l, m);
	ll vr = Query(L, R, rs, m + 1, r);
	return min(vl, vr);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N >> M) {
		for (int i = 1; i <= N; ++i) {
			cin >> arr[i];
			arr[i] += arr[i - 1];
			lvl[i].clear();
			base[i] = INF;
			lvl[i].push_back(pll(0, 0));
		}
		base[N + 1] = 0;
		Build();
		for (int i = 0; i < M; ++i) {
			ll l, s, c;
			cin >> l >> s >> c;
			lvl[l].push_back(pll(s, c));
		}
		ll mint;
		for (int i = N; i >= 1; --i) {
			mint = INF;
			for (int j = 0; j < lvl[i].size(); ++j) {
				int id = upper_bound(arr + 1, arr + N + 1, arr[i - 1] + lvl[i][j].first) - arr;
				mint = min(mint, lvl[i][j].second + Query(i, id));
			}
			Update(i, mint);
		}
		if (mint >= INF) 
			cout << "-1\n";
		else 
			cout << mint << '\n';
	}
	return 0;
}