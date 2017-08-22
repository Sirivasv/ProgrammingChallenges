#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int ans = 0;
	int manynov = 0;
	int currs = 0;
	stack<int> myst;
	myst.push(1000);
	for (int i = 0; i < N; ++i) {
		int opc;
		cin >> opc;
		if (opc == 1) { //set new speed
			cin >> currs;
			while (currs > myst.top()) {
				ans++;
				myst.pop();
			}
		} else if (opc == 2) {	//overtook a car
			ans += manynov;
			manynov = 0;
		} else if (opc == 3) { //new speed limit
			int val;
			cin >> val;
			myst.push(val);
			while (currs > myst.top()) {
				ans++;
				myst.pop();
			}
		} else if (opc == 4) { //overtake is allowed
			manynov = 0;
		} else if (opc == 5) { //no speed limit
			myst.push(1000);
		} else if (opc == 6) { //overtake is not allowed
			manynov++;
		}
	}
	cout << ans << '\n';
	return 0;
}