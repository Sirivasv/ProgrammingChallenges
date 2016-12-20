#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int xi = 0, yi = 0, zi = 0;
	
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int xj, yj, zj;
		cin >> xj >> yj >> zj;
		xi += xj;
		yi += yj;
		zi += zj;
	}
	
	cout << (((xi == 0) && (yi == 0) && (zi == 0))?("YES\n"):("NO\n"));
	
	return 0;
}