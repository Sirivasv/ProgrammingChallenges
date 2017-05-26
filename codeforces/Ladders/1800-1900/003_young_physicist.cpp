#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	lli xi = 0, yi = 0, zi = 0;
	int N;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		lli rx, ry, rz;
		cin >> rx >> ry >> rz;
		xi += rx;
		yi += ry;
		zi += rz;
	} 
	if ((xi == 0) && ( yi== 0) && (zi == 0)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}