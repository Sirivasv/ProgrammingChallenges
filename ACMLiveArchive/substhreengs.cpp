#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 1000009;

lli numb[MAXN];
int cub[5];
int idn;

lli Proc() {
	cub[0] = 1;
	cub[1] = 0;
	cub[2] = 0;
	lli acum = 0, ans = 0;
	for (int i = 0; i < idn; ++i) {
		acum += numb[i];
		int md = acum % 3;
		ans += cub[md];
		cub[md]++;
	}
	return ans;
}

int main() {
	string s;
	while (cin >> s) {
		lli tot = 0;
		int lim = s.size();
		idn = 0;
		for (int i = 0; i < lim; ++i) {
			if (!((s[i] >= '0') && (s[i] <= '9'))) {
				if (idn)
					tot += Proc();
				idn = 0;
			} else
				numb[idn++] = s[i] - '0';
		}
		if (idn)
			tot += Proc();
		cout << tot << '\n';
	}
	return 0;
}