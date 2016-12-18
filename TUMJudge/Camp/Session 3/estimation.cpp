#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20009;

int BITA[MAXN], BITM[MAXN], sz;

void Update(int idx, int v, int* BIT) {
	while (idx < MAXN) {
		BIT[idx] += v;
		idx += (idx & (-idx));
	}
}

int Query(int idx, int* BIT) {
	int sum = 0;
	while (idx) {
		sum += BIT[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}

int Range(int I, int J, int* BIT) {
	return (Query(J, BIT) - Query(I - 1, BIT));
}

int GetMed() {
	int ini = 1, fin = MAXN - 1, m, ans;
	int lim = (sz + 1) / 2;
	while (ini <= fin) {
		m = (ini + fin) >> 1;
		if (Query(m, BITM) >= lim) {
			ans = m;
			fin = m - 1;
		} else 
			ini = m + 1;
	}
	return ans;
}

int GetNMed() {
	int ini = 1, fin = MAXN - 1, m, ans;
	int lim = (sz + 1) / 2;
	while (ini <= fin) {
		m = (ini + fin) >> 1;
		if (Query(m, BITM) > lim) {
			ans = m;
			fin = m - 1;
		} else 
			ini = m + 1;
	}
	return ans;
}

int arr[MAXN];
map<int, int> mn, nm;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int cnt = 0;
	while (cin >> arr[cnt]) {
		mn[arr[cnt]] = 1;
		cnt++;
	}
	int ax = 1;
	for (map<int, int>::iterator it = mn.begin(); it != mn.end(); it++) {
		mn[it->first] = ax++;
		nm[ax - 1] = it->first;
	}
	for(int i = 0; i < cnt; ++i) {
		int ax = mn[arr[i]];
		Update(ax, 1, BITM);
		sz++;
		long long med = nm[GetMed()];
		if ((sz % 2) == 0) {
			long long nmed = nm[GetNMed()];
			cout << ((med + nmed) / 2) << '\n';
		} else
			cout << med << '\n';
	}
	return 0;
}