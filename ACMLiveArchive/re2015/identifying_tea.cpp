#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, aux, cnt;
	while (cin >> T) {
		cnt = 0;
		for (int i = 0; i < 5; ++i) {
			cin >> aux;
			if (aux == T)
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}