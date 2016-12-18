#include <bits/stdc++.h>
using namespace std;

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int a, c, m, x;
	while ( cin >> a >> c >> m >> x) {
		map<int, int> many;
		many[x]++;
		int cont = 1;
		int contl = 0;
		int val = x;
		int flagl = 0;
 		while (true) {
			val = (val * a + c) % m;
			if (flagl) {
				if (many[val] == 2) {
					break;
				} else {
					contl++;
					many[val]++;
				}
			} else {
				if (many[val] == 1) {
					flagl++;
					contl++;
					many[val]++;
				} else {
					cont++;
					many[val]++;
				}
			}
		}
		
		int allm = 1;
		int manyonce = 0;
		for (int i = 0; i < m; ++i)
			if (!many.count(i))
				allm = 0;
			else if (many[i] == 1)
				manyonce++;
		
		if (allm)
			cout << "YES ";
		else 
			cout << "NO ";
		
		cout << cont << ' ' << manyonce << ' ' << contl << '\n';
		
	}
	return 0;
}