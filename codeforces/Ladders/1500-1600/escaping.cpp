#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;
int vi[MAXN], vj[MAXN];
int idi, idj;

string s;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> s;
	int lim = s.size();
	for (int i = 0; i < lim; i++) 
		if (s[i] == 'l')
			vi[idi++] = i + 1;
		else
			vj[idj++] = i + 1;
	
	for (int i = 0; i < idj; ++i)
		cout << vj[i] << '\n';
	
	for (int i = idi - 1; i >= 0; i--)
		cout << vi[i] << '\n';
	
	return 0;
}