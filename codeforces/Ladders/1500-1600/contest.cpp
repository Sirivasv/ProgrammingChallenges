#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int vali = max(((3 * a) / 10), a - ((a / 250) * c)); 
	int valj = max(((3 * b) / 10), b - ((b / 250) * d)); 
	if (vali > valj) cout << "Misha\n";
	else if (valj > vali) cout << "Vasya\n";
	else cout << "Tie\n";
	return 0;
}