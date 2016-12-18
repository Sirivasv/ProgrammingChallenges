#include <bits/stdc++.h>
using namespace std;

int Abs(int x) { return ((x < 0)?(-x):(x)); }

int main() {
	int x;
	cin >> x;
	if (x >= 0) 
		cout << x << '\n';
	else 
		cout << -min(Abs(x), min(Abs(x) / 10, ((Abs(x) / 100) * 10) + (Abs(x) % 10)));
	return 0;
}