#include <bits/stdc++.h>
using namespace std;

int arr[15];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int k;
	cin >> k;
	k += k;

	for (int i = 0; i < 4; ++i) {
		string s;
		cin >> s;
		for (char c : s) if ((c >= '0') && (c <= '9')) arr[c - '0']++;			
	}
	
	int ans = 1;
	for (int i = 1; i <= 9; ++i) if (arr[i] > k) ans = 0; 

	cout << ((ans)?("YES"):("NO")) << '\n';

	return 0;
}