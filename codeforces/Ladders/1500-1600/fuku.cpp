#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;
lli arr[MAXN], acum[MAXN], acumsort[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) { 
		cin >> arr[i];
		acum[i] = arr[i] + acum[i - 1];
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; ++i)
		acumsort[i] = arr[i] + acumsort[i - 1];
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int T, I, J; 
		cin >> T >> I >> J;
		if (T == 1)
			cout << (acum[J] - acum[I - 1]) << '\n';
		else
			cout << (acumsort[J] - acumsort[I - 1]) << '\n';
	}
	return 0;
}