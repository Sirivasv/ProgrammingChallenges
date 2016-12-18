#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10009;

int arr[MAXN], N, l[MAXN], r[MAXN];
bitset<MAXN> taken;

void Process(int le = 0, int ri = N - 1) {
	if (((le + 1) <= ri) && (!taken[le + 1])) {
		l[le] = le + 1;
		taken[le + 1] = 1;
	}
	int ans = 0, ini = le + 1, fin = ri, m;
	while (ini <= fin) {
		m = (ini + fin) >> 1;
		if (arr[m] > arr[le]) {
			ans = m;
			fin = m - 1;
		} else 
			ini = m + 1;
	}
	if (!taken[ans]) {
		taken[ans] = 1;
		r[le] = ans;
	}
	
	//cout << le << ' ' << l[le] << ' ' << r[le] << '\n';
	
	if (r[le]) {
		if (l[le])
			Process(l[le], r[le] - 1);
		Process(r[le], ri);
	} else if (l[le])
		Process(l[le], ri);
}

void PosOrder(int u = 0) {
	if (l[u])
		PosOrder(l[u]);
	if (r[u])
		PosOrder(r[u]);
	cout << arr[u] << '\n';
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int aux;
	while (cin >> aux) {
		arr[N++] = aux;
	}
	Process();
	PosOrder();
	return 0;
}