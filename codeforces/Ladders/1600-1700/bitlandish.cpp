#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string si, sj;
	
	cin >> si >> sj;
	
	int ok = 0, onesi = 0, onesj = 0, lim = si.size();
	
	for (int i = 0; i < lim; ++i) if (si[i] == '1') onesi = 1;
	lim = sj.size();
	for (int i = 0; i < lim; ++i) if (sj[i] == '1') onesj = 1;
	
	ok = (((onesi && (si.size() >= 2)) || (onesi == onesj)) && (!(onesi && (onesj == 0))) && (si.size() == sj.size()));
	
	cout << ((ok)?("YES\n"):("NO\n"));
	
	return 0;
}