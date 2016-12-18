#include <bits/stdc++.h>
using namespace std;

int IsL(long long x) {
	return ((!(x % 400LL)) || ((!(x % 4LL)) && ((x % 100LL)))); 
}

long long Ndays (long long x) {
	if(IsL(x)) return 366LL;
	return 365LL;
} 

int main() {
	long long y;
	cin >> y;
	int isl = IsL(y);
	int mod = (Ndays(y) - 1) % 7LL;
	long long ny, nmod = (Ndays(y) - 1LL) % 7LL;
	int nisl;
	ny = y;
	while (true) {
		ny++;
		nmod = (nmod + Ndays(ny)) % 7LL;
		//cout << nmod << '\n';
		//cout << Ndays(ny) << '\n';
		nisl = IsL(ny);
		if ((nmod == mod) && (nisl == isl)) 
			break;
	}
	cout << ny << '\n';
	return 0;
}