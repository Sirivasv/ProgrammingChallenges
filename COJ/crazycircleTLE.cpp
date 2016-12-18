#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		int M; 
		cin >> M;
		for (int i = 0; i < M; ++i) {
			cin >> arr[i];
			arr[M + i] = arr[i];
		}
		int ans = (1 << 30);
		for (int i = 0; i < M; ++i) {
			int flag = 1;
			for (int j = i; j < (M + i); ++j) {
				if (arr[(arr[j] - 1) + i] != (j - i + 1)) {
					flag = 0;
					break;
				}
				if ((((arr[j] - 1) + i) > (j + 1)) && (!((((arr[j] - 1) + i) == (M + i - 1)) && (j == i)))) {
					//cout << j << ' ' << arr[j] << '\n';
					flag = 0;
					break;
				}
			}
			if (flag) {
				int tmp = 0;
				for (int j = i; j < (M + i); ++j)
					if (arr[j] != (j - i + 1))
						tmp++;
				ans = min(tmp, ans);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}