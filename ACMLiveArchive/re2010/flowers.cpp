#include <bits/stdc++.h>
using namespace std;

int main() {
	string l, w;
	while (true) {
		getline(cin, l);
		if (l[0] == '*') 
			break;
		stringstream is(l);
		char C = toupper(l[0]);
		bool is_t = true;
		while (is >> w) {
			if (toupper(w[0]) != C) {
				is_t = false;
				break;
			}
		}
		if (is_t)
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}