#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long N, a, b, p, q;
	cin >> N >> a >> b >> p >> q;
	unsigned long long ans1 = (((N / a) * (p)) + ((N / b) * (q)) - ((N / (a * b)) * (q)));
	unsigned long long ans2 = (((N / a) * (p)) + ((N / b) * (q)) - ((N / (a * b)) * (p)));
	cout << max(ans1, ans2) << '\n';
	return 0;
}