#include <bits/stdc++.h>
using namespace std;
const int MAXN = 509;
int parent[MAXN], N, phone[MAXN];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	parent[Find(x)] = Find(y);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0;i < N; ++i) {
		parent[i] = i;
		cin >> phone[i];
	}
	int u, v;
	while (cin >> u >> v) {
		u--, v--;
		Union(u, v);
	}
	for (int i = 0; i < N; ++i)
		if ((phone[i]) && (!phone[Find(i)])) 
			phone[Find(i)] = phone[i];
	for (int i = 0; i < N; ++i) 
		cout << phone[Find(i)] << '\n';
	return 0;
}