#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int pd[MAXN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, G, S, R;
	
	while (cin >> N >> G) {
	
		for (int i = 0; i < N; ++i) {
			cin >> S >> R;
			pd[i] = R - S;
		}
		
		sort(pd, pd + N);
		
		int score = 0;
		
		for (int i = 0; i < N; ++i) {
			if (pd[i] < 0) {
				score += 3;
				continue;
			}
			if (G - (pd[i] + 1) >= 0) {
				score += 3;
				G -= (pd[i] + 1);
				continue;
			}
			if (G - pd[i] >= 0) {
				score += 1;
				G -= pd[i];
			}
		}
		
		cout << score << '\n';
	}
	
	return 0;
}