#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pli;
 
const int MAXN = 300000;

lli arr[MAXN], acum[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		arr[i] *= -1LL;
	}
	sort(arr, arr + N);
	for (int i = 0; i < Q; ++i) {
		int I, J;
		cin >> I >> J;
		acum[I]++;
		acum[J + 1]--;
	}
	set<pli> numb;
	for (int i = 1; i <= N; ++i) {
		acum[i] += acum[i - 1];
		numb.insert(pli(-acum[i], i - 1));
	}
	lli sum = 0;
	set<pli>::iterator it = numb.begin();
	for (int i = 0; i < N; ++i, it++)
		sum += (it->first) * arr[i];
	cout << sum << '\n';
	return 0;
}