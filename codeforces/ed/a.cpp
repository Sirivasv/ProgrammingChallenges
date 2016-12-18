#include <bits/stdc++.h>
using namespace std;

int main () {
	long long n, k;
	cin >> n >> k;
	long long times = n / k;
	times++;
	cout << times * k;
	return 0;
}