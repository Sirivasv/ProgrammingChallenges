#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<int, int> pii;
typedef pair<pii, lli> ter;

const int MAXN = 100009;

ter operations[MAXN];
lli barr[MAXN], sum[MAXN], multiplier[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N, M, K;
	
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; ++i)
		cin >> barr[i];
	
	for (int i = 1; i <= M; ++i)
		cin >> operations[i].first.first >> operations[i].first.second >> operations[i].second;
	
	for (int i = 0; i < K; ++i) {
		int a, b;
		cin >> a >> b;
		multiplier[a]++;
		multiplier[b + 1]--;
	}
	
	for (int i = 1; i <= M; ++i)
		multiplier[i] += multiplier[i - 1];
	
	for (int i = 1; i <= M; ++i) {
		int a = operations[i].first.first;
		int b = operations[i].first.second;
		lli val = operations[i].second;
		sum[a] += val * multiplier[i];
		sum[b + 1] -= val * multiplier[i];
	}
	
	for (int i = 1; i <= N; ++i) {
		sum[i] += sum[i - 1];
		if (i > 1) cout << ' ';
		cout << (barr[i] + sum[i]);
	}
	cout << '\n';
	
	return 0;
}