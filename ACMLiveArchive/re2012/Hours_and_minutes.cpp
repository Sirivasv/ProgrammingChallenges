#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		if ((N % 6) == 0)
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}