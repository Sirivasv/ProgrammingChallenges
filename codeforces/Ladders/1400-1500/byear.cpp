#include <bits/stdc++.h>
using namespace std;

bool HasDistinctD(int x) {
	set<int> digits;
	int N = 0;
	while (x) {
		digits.insert(x % 10);
		x /= 10;
		N++;
	}
	return (digits.size() == N);
}

int main() {
	int y;
	cin >> y;
	for (int i = y + 1; i < 90001; ++i)
		if (HasDistinctD(i)) {
			cout << i << '\n';
			break;
		}
	return 0;
}