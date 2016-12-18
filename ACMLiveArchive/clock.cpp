#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		cout << (((N % 6) == 0)?("Y\n"):("N\n"));
	}
	return 0;
}