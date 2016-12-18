#include <bits/stdc++.h>
using namespace std;

vector<int> LuckyN;


bool IsLucky(int x) {
	while (x) {
		if (((x % 10) != 4) && ((x % 10) != 7))
			return false;
		x /= 10;
	}
	return true;
}

void GetLuckyN() {
	for (int i = 1; i <= 1000; ++i)
		if (IsLucky(i))
			LuckyN.push_back(i);
}

int main() {
	GetLuckyN();
	int N, lim = LuckyN.size();
	cin >> N;
	int ok = 0;
	for (int i = 0; i < lim; ++i) {
		if (LuckyN[i] > N)
			break;
		if ((N % LuckyN[i]) == 0) {
			ok = 1;
			break;
		}
	}
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}