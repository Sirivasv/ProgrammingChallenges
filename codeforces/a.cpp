#include <bits/stdc++.h>
using namespace std;

int arr[1000], many[1000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int mats = 0, sum = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> arr[i];
		many[arr[i]]++;
		sum += arr[i];
	}
	for (int i = 0; i < 5; ++i) 
		if (many[arr[i]] >= 2)
			mats = max(((min(many[arr[i]], 3)) * arr[i]), mats);
	cout << sum - mats << '\n';
	return 0;
}