#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int cards[] = {0, 1, 10, 100, 1000, 10000};
	int N, M;
	while (cin >> N >> M) {
		int TD = 0;
		for (int i = 0; i < M; ++i) {
			int valM, acum = 0, mine, ax;
			cin >> valM >> mine;
			for (int j = 1; j < N; ++j) {
				cin >> ax;
				acum += ax;
			}
			if (acum < valM) {
				int j;
				for (j = 0; j < 6; ++j)
					if ((cards[j] + acum) > valM)
						break;
				j--;
				if ((mine + acum) <= valM)
					TD += cards[j] - mine;
				else
					TD += cards[j];
			}
		}
		cout << TD << '\n';
	}
	return 0;
}