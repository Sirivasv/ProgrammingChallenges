#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	double N;
	cin >> N;
	int ans = (N / 7.0);
	ans <<= 1;
	int mint = 0, mats = 0;
	int modd = ((int)N) % 7;
	if (modd == 6) mint = 1;
	if (modd >= 2) mats = 2;
	if (modd == 1) mats = 1;
	cout << ans + mint << ' ' << ans + mats << '\n';
	return 0;
}