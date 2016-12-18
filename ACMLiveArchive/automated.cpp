#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> arr[0]) {
		for (int i = 1; i < 5; ++i)
			cin >> arr[i];
		int cnt = 0;
		for (int i = 0; i < 5; ++i) {
			int ax;
			cin >> ax;
			if (ax != arr[i])
				cnt++;
		}
		cout << ((cnt == 5)?("Y\n"):("N\n"));
	}
	return 0;
}