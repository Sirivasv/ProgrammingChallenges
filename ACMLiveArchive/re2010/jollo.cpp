#include <bits/stdc++.h>
using namespace std;

int A, B, C, X, Y;
int prcss[3], prnc[3];
bitset<55> taken;

bool check(int m) {
	prcss[0] = A;
	prcss[1] = B;
	prcss[2] = C;
	
	prnc[0] = X;
	prnc[1] = Y;
	prnc[2] = m;
	
	sort(prcss, prcss + 3);
	
	do {
		
		sort(prnc, prnc + 3);
		
		do {
			
			int perdio = 0;
			for (int i = 0; i < 3; ++i)
				perdio += (prcss[i] > prnc[i]);
			if (perdio >= 2) return false;
			
		}while(next_permutation(prnc, prnc + 3));
		
	} while(next_permutation(prcss, prcss + 3));
	
	return true;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> A >> B >> C >> X >> Y) {
		if (! (A + B + C + X + Y))
			break;
		
		taken.reset();
		taken[A] = 1;
		taken[B] = 1;
		taken[C] = 1;
		taken[X] = 1;
		taken[Y] = 1;
		
		int ans = -1;
		for (int i = 1; i <= 52; ++i) 
			if ((!taken[i]) && (check(i))) {
				ans = i;			
				break;
			}
		cout << ans << '\n';
	}
	return 0;
}