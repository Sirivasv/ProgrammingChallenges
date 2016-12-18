#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; j++) {
			if ((s[j] == 'B') && (s[j + 1] == 'G')) {
				swap(s[j], s[j + 1]);
				j++;
			}
		}
	}
	cout << s << '\n';
	return 0;
}