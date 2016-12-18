#include <bits/stdc++.h>
using namespace std;


long long GetDigitSum(long long x) {
	long long sum = 0;
	while (x) {
		sum += (x % 10);
		x /= 10;
	}
	return sum;
}
int main() {
	//int N = 15;
	for (long long i = 1LL; i < 1000000000LL; ++i) { 
		cout << i << ": " << (11LL * i) << " - " << GetDigitSum(11 * i) << '\n';
		//cout << N;
	}
	return 0;
}