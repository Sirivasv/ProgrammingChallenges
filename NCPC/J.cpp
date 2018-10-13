#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	lli a, b, c, d;
	cin >> a >> b >> c >> d;

	if ((c == 1) && (!a) && (!d)) {
		cout << "10\n";
		return 0; 
	}

	if (b && (!a) && (!d)) {
		cout << "01\n";
		return 0; 
	}

	if ((!b) && (!c) && (!a) && (!d)) {
		cout << "0\n";
		return 0; 
	}

	if ((!b) && (!c) && (!a) && (d == 1)) {
		cout << "11\n";
		return 0; 
	}

	if ((!b) && (!c) && (a == 1) && (!d)) {
		cout << "00\n";
		return 0; 
	}

	// if ((c == 1) && (!a) && (d == 1)) {
	// 	cout << "011\n";
	// 	return 0; 
	// }

	// if ((c == 1) && (!a) && (d == 1)) {
	// 	cout << "011\n";
	// 	return 0; 
	// }

	int flag = 1;

	lli aRt = ceil(sqrt(double(a * 2ll)));
	if (((aRt * (aRt - 1LL)) >> 1) != (a)) {
		flag = 0;
	}
	if (!aRt) aRt++;
	// cout << flag << ' ' << aRt << '\n';

	lli dRt = ceil(sqrt(double(d * 2ll)));
	if (((dRt * (dRt - 1LL)) >> 1) != (d)) {
		flag = 0;
	}
	if (!dRt) dRt++;
	// cout << flag << ' ' << dRt << '\n';

	if ((b + c) != (aRt * dRt)) {
		flag = 0;
	}
	// cout << flag << '\n';

	if (flag == 0) {
		cout << "impossible\n";
	} else {


		lli firstOnes = (aRt)?(c / aRt):(0);
		lli residualZeroes = (aRt)?(c % aRt):(0);
		lli firstZeroes = aRt;
		lli middleOne = 0;
		if (residualZeroes) {
			firstZeroes = firstZeroes - residualZeroes;
			middleOne = 1;
		}

		lli lastOnes = dRt - firstOnes - middleOne;

		// cout << firstOnes << ' ' << aRt << ' ' << residualZeroes << ' ' << middleOne << '\n';

		lli bRt = (aRt * lastOnes) + (firstZeroes * middleOne);
		if (bRt != b) { flag = 0; }	
		// cout << flag << ' ' << bRt << '\n';

		lli cRt = (firstOnes * aRt) + (residualZeroes * middleOne);
		if (cRt != c) { flag = 0; }
		// cout << flag << ' ' << cRt << '\n';

		// if (!flag) {
		// 	cout << "impossible\n";
		// } else {
			for (int i = 0; i < firstOnes; ++i) {  cout << '1'; }
			for (int i = 0; i < firstZeroes; ++i) {  cout << '0'; }
			if (middleOne) {  cout << '1'; }
			for (int i = 0; i < residualZeroes; ++i) {  cout << '0'; }
			for (int i = 0; i < lastOnes; ++i) {  cout << '1'; }
			cout << '\n';	
		// }
	}

	return 0;
}