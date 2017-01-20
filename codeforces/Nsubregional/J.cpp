#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("java2016.in", "r", stdin);
	//freopen("java2016.out", "w", stdout);
	int N;
	cin >> N;
	if (N == 0) {
		cout << "? /?/ ?\n";
		return 0;
	}
	
	cout << "z = ? max ?\n";	
	
	for (int i = 1; i < 15; ++i) {
		cout << char('z' - i) << " = " << char('z' - i + 1) << " max " << char('z' - i + 1) << '\n';
	} 

	cout << "b = l / l\n";
	
	for (int i = 1; i < 8; ++i) {
		if ((1 << i) <= N) {
			cout << char(i + 'b') << " = " << char(i + 'b' - 1) << " + " << char(i + 'b' - 1) << '\n';
		} else break;
	}
	
	cout << "( ";
	
	int cnt = 0;
	
	for (int i = 0; i < 8; ++i) {
		if ((1 << i) & N) {
			if (cnt++) cout << " + ";
			cout << char(i + 'b');
		} 
	}
	
	cout << " )\n";
	
	
	return 0;
}