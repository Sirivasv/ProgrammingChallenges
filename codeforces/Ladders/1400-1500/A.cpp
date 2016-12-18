#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string s;
	cin >> N;
	cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == 'A')
			a++;
		else 
			b++;
	if (a > b)
		cout << "Anton\n";
	else if (b > a)
		cout << "Danik\n";
	else
		cout << "Friendship\n";
	return 0;
}