#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;

const int MAXN = 1009;

ter arr[MAXN];
pii tables[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].first.first >> arr[i].first.second;
		arr[i].second = i + 1;
	}
	sort(arr, arr + N);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> tables[i].first;
		tables[i].second = i + 1;
	}
	sort(tables, tables + T);
	int currt = 0;
	priority_queue<pii> Q;
	vector<pii> accepted_requests;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (arr[i].first.first > tables[currt].first) {
			if (!Q.empty()) {
				ans += Q.top().first;
				accepted_requests.push_back(pii(Q.top().second, tables[currt].second));
				Q.pop();
			}
			currt++;
			if (currt == T)
				break;
			i--;
		} else
			Q.push(pii(arr[i].first.second, arr[i].second));
	}
	while (currt < T) {
		ans += Q.top().first;
		accepted_requests.push_back(pii(Q.top().second, tables[currt].second));
		Q.pop();
		if (Q.empty())
			break;
		currt++;
	}
	cout << accepted_requests.size() << ' ' << ans << '\n';
	for (const auto& request: accepted_requests)
		cout << request.first << ' ' << request.second << '\n';
	return 0;
}