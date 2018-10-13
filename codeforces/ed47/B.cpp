#include <bits/stdc++.h>
using namespace std;

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	string s;
	cin >> s;

	vector<int> zpb;

	int inz = 0;
	int cb = 0;
	int mn2 = 0;
	int mn1 = 0;
	int mnzb = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '2') {
			mn2++;
			cb++;
			if (cb != 0) {
				zpb.push_back(mnzb);
			} 
			mnzb = 0;
		} else if (s[i] == '1') {
			mn1++;
		} else if (s[i] == '0') {
			if (cb == 0){
				inz++;
			} else {
				mnzb++;
			}
		}
	}

	if (cb != 0) {
		zpb.push_back(mnzb);
	}

	if (inz) {
		for (int i = 0; i < inz; ++i) cout << '0';
	}
	if (mn1) {
		for (int i = 0; i < mn1; ++i) cout << '1';
	}
	for (int i = 0; i < zpb.size(); ++i) {
		for (int j = 0; j < zpb[i]; ++j) cout << '0';
		if (mn2) {
			cout << '2';
			mn2--;
		}	
	}

	return 0;
}