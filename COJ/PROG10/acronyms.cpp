#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	while (getline(cin, s)) {
		stringstream is(s);
		vector<char> v1, v2;
		while (is >> s)
			v1.push_back(s[0]);
		getline(cin, s);
		stringstream iss(s);
		int i = 0, flag = 1;
		while (iss >> s) {
			if (s[0] != v1[i])
				flag = 0;
			i++;
		}
		if (flag)
			cout << "yes\n";
		else 
			cout << "no\n";
	}
	return 0;
}