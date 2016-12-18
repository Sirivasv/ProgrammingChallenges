#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;

pii arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, mint = 1000000009, mats = -1;
	
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		mint = min(a, mint);
		mats = max(mats, b);
		arr[i].first = a;
		arr[i].second = b;
	}
	
	int found = 0;
	
	for (int i = 0; i < N; ++i) {
		if ((arr[i].first == mint) && (arr[i].second == mats)) {
			cout << (i + 1) << '\n';
			found = 1;
			break;
		}
	}
	
	if (not(found))
		cout << "-1\n";
	
	return 0;
}