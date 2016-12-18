#include <bits/stdc++.h>
using namespace std;

int arr[5];

int main() {
	for (int i = 0; i < 4; ++i) 
		cin >> arr[i];
	int d;
	cin >> d;
	set<int> vals;
	for (int i = 0; i < 4; ++i) {
		int n = arr[i];
		while (n <= d) {
			vals.insert(n);
			n += arr[i];
		}
	}
	cout << vals.size() << '\n';
	return 0;
}