#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1000000007LL;

int main() {

	lli A, B;

	cin >> A >> B;

	if (A > B) swap(A, B);

	if ((!A) && (!B)) {
		cout << "1\n";
		return 0;
	}

	if (!A) {
		cout << "-1\n";
		return 0;
	} 

	cout << (((((B - 1LL) * (B - 1LL)) - ((A - 1LL) * (A - 1LL))) + (B - A + 1LL)) %  MOD) << '\n';

	return 0;
}