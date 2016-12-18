#include <bits/stdc++.h>
using namespace std;

int mat[3][3];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int R, l, nr, sc;
	double lkm, km;
	cin >> R;
	
	while (R--) {
		cin >> nr;
		cin >> l;
		lkm = -(1.0);
		sc = 0;
		for (int i = 0; i < nr; ++i) {
			cin >> km;
			if (lkm == -1.0) {
				lkm = km;
				continue;
			}
			
			if ((km - lkm) > (0.1) * lkm)
				sc = 1;
			
			lkm = km;
		}
		
		mat[l][sc]++;
	}
	
	cout << mat[1][1] << '\n';
	cout << mat[1][0] << '\n';
	cout << mat[0][1] << '\n';
	cout << mat[0][0] << '\n';
	
	return 0;
}