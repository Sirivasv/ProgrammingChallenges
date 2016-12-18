#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;
int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, G;
	while (cin >> N >> G) {
		for (int i = 0; i < N; ++i) {
			int S, R;
			cin >> S >> R;
			arr[i] = R - S;
		}
		sort(arr, arr + N);
		int tp = 0;
		for (int i = 0; i < N; ++i) {
			if (arr[i] < 0)
				tp += 3;
			else if (arr[i] == 0) {
				if (G) {
					G--;
					tp += 3;
				} else 
					tp++;
			} else {
				if (G >= (arr[i] + 1)) {
					G -= (arr[i] + 1);
					tp += 3;
				} else if (G >= arr[i]) {
					G -= arr[i];
					tp++;
				}
			}
		}
		cout << tp << '\n';
	}
	return 0;
}