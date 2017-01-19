#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

lli Pot(lli n, lli b, lli pot) {
	lli mv = 1LL;
	for (int i = 1; i <= pot; ++i) mv *= b;
	return n * mv;
}

int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	lli N;
	string K;
	
	cin >> N >> K;
	
	lli res = 0;
	int lim = K.size();
	
	lli currsum = 0;
	lli cp = 0, tp = 0;
	
	for (int i = lim - 1; i >= 0; --i) {
		lli num = K[i] - '0';
		if (num == 0LL) {
			res += Pot(currsum, N, tp); currsum = 0; cp = 0; tp += 2LL; continue;}
		lli nsum = Pot(num, 10LL, cp) + currsum;
		if (nsum >= N) {
			res += Pot(currsum, N, tp);
			tp++;
			cp = 0;
			currsum = 0;
			i++;
		} else {
			currsum = nsum;
			cp++;
			continue;
		}
	}
	res += Pot(currsum, N, tp);
	
	cout << res << '\n';
	
	return 0;
}