#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		int M; 
		cin >> M;
		for (int i = 0; i < M; ++i)
			cin >> arr[i];
		int ans = 0;
		M--;
		for (int i = 0; i < M; ++i)
			if (arr[i] > arr[i + 1])
				ans += 2;
		if (arr[M] < arr[0])
			ans -= 2;
		cout << ans << '\n';
	}
	return 0;
}