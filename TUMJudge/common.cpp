#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	cout << ((1LL << N) * (1LL << (N << 1))) << '\n';
	return 0;
}