#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1000009;

int arr[MAXN];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, K;
		scanf("%d%d", &N, &K);
		set<pii> ST;
		int ini = 0, fin = K;
		for (int i = 0; i < K; ++i) {
			scanf("%d", &arr[i]);
			ST.insert(pii(arr[i], i));
		}
		//for (auto it : ST) cout << it.first << ' ' << it.second << '\n';
		cout << (ST.rbegin())->first;
		while (fin < N) {
			ST.erase(pii(arr[ini], ini));
			scanf("%d", &arr[fin]);
			ST.insert(pii(arr[fin], fin));
			cout << ' ' << (ST.rbegin())->first;
			ini++;
			fin++;
		}
		cout << '\n';
	}
	return 0;
}