#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli LIM = 1000000000LL;

lli S(lli n) {
	lli res = 0;
	while (n) {
		res += (n % 10LL);
		n /= 10LL;
	}
	return res;
}

int main() {
	lli a, b, c;
	cin >> a >> b >>c;
	vector<lli> ans;
	for (lli i = 1LL; i < 82LL; ++i) {
		lli val = i;
		for (lli j = 2LL; j <= a; ++j)
			val *= i;
		val *= b;
		val += c;
		if ((S(val) == i) && (val < LIM))
			ans.push_back(val);
	}
	cout << ans.size() << '\n';
	for (auto it : ans) {
		if (it != ans[0])
			cout << ' ';
		cout << it; 
	}
	if (ans.size())
		cout << '\n';
	return 0;
}