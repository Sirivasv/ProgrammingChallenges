#include <bits/stdc++.h>
using namespace std;

const int MAXC = 10;

string arr[MAXC];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	for (int i = 0; i < 8; ++i)
		cin >> arr[i];
	
	int ok = 0;
	
	for (int i = 0; i < 8; ++i) {
		char val = arr[i][0];
		for (int j = 1; j < 8; ++j) {
			if (arr[i][j] == val)
				ok = 0;
			val = arr[i][j];
		}
	}
	
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}