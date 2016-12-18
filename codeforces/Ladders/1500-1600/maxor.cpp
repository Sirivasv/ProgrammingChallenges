#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli L, R;
	cin >> L >> R;
	int mats = 62;
	while ((mats >= 0) && ((L & (1LL << mats)) == (R & (1LL << mats))))
		mats--;
	mats++;
	cout << ((1LL << mats) - 1LL) << '\n';
	return 0;
}