#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int> uro;
	uro.insert(8);
	uro.insert(10);
	uro.erase(11);
	cout << "UO\n";
	for (set<int>::iterator it = uro.end(); it != uro.begin(); it--) {
		if (it == uro.end())
			continue;
		cout << (*it) << '\n';
	}
	return 0;
}