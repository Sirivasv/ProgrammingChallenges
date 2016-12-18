#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, S, J, D;
	cin >> N >> S >> J >> D;
	string pa;
	cin >> pa;
	int len_ = pa.size();
	int winA = 0, winB = 0;
	int totA = 0, totB = 0;
	for (int i = 0; i < len_; ++i) {
	    if (pa[i] == 'A') {
			winA++;
			if ((winA >= J) && ((winA - winB) >= D)) {
				totA++;
				winA = 0;
				winB = 0;
			}
		} else {
			winB++;
			if ((winB >= J) && ((winB - winA) >= D)) {
				totB++;
				winA = 0;
				winB = 0;
			}
		}
	}
	cout << totA << " " << totB << '\n';
	return 0;
}