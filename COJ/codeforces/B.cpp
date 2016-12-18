#include <bits/stdc++.h>
using namespace std;
typedef pair <long long, int> pii;
const int MAXN = 200009; 
long long terminos[MAXN];
int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, B;
	cin >> N >> B;
	long long x, y;
	cin >> x >> y;
	pii machine = pii(x + y, 0);
	queue< pii > cola;
	for (int i = 1; i < N; ++i) {
		cin >> x >> y;
		while (x >= machine.first) {
			terminos[machine.second] = machine.first;
			if (cola.empty()) {
				machine.first = -1;
				break;
			} else {
				machine.first += cola.front().first;
				machine.second = cola.front().second;
				cola.pop();
			}
		}
		if (machine.first == -1) {
			machine.first = x + y;
			machine.second = i;
		} else {
			if (cola.size() < B) {
				cola.push(pii(y, i));
			} else terminos[i] = -1;
		}
	}
	while (!cola.empty()) {
		terminos[machine.second] = machine.first;
		machine.first += cola.front().first;
		machine.second = cola.front().second;
		cola.pop();
	}
	terminos[machine.second] = machine.first;
	for (int i = 0; i < N; ++i) cout << terminos[i] << ' ';
	cout << '\n';
	return 0;
}	