#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int id = -1;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
		if (arr[i] != 0) id = i;
	}
	
	if (arr[N] != 0) cout << "YES\n1\n1 " << N << '\n';
	else if (id != -1) cout << "YES\n2\n1 " << id << '\n' << (id + 1) << ' ' << N << '\n';
	else cout << "NO\n";
	
	return 0;
}
