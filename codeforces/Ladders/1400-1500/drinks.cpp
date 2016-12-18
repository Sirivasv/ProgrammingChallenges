#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	
	cin >> N;
	
	double sum = 0;
	
	for (int i = 0; i < N; ++i) {
		double p;
		cin >> p;
		sum += p;
	}
	sum /= ((double)N);
	cout << fixed << setprecision(6) << sum << '\n';
	return 0;
}