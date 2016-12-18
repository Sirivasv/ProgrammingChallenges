#include <bits/stdc++.h>
using namespace std;

int main () {
	cin.tie(0)
	ios_base::sync_with_stdio(0);
	unsigned long long a, b, c;
	
	cin >> a;
	a++;
	b = a >> 1;
	a--;
	c = (b * (a - b));
	cout << c
	return 0;
}