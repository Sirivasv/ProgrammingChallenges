#include <bits/stdc++.h>
using namespace std;


string s;
int main() {
	int acum = 0;
	int N;
	cin >> N;
	int ans = 0;
	
	cin >> s;
	
	int alive = N;
	
	for (int i = 0; i < N; ++i) {
		if (s[i] == '<')
			alive--;
		else
			break;
	}
	
	for (int i = N - 1; i >= 0; --i) {
		if (s[i] == '>')
			alive--;
		else
			break;
	}
		
	cout << (N - alive) << '\n';
	
	return 0;
}