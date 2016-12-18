#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	while (getline(cin, s)) {
		if (s[0] == '*')
			break;
		stringstream iss(s);
		string aux;
		iss >> aux;
		char comp = toupper(aux[0]);
		int fl = 1;
		while (iss >> aux) {
			fl &= (toupper(aux[0]) == comp);
		}
		cout << ((fl)?("Y\n"):("N\n"));
	}
	return 0;
}