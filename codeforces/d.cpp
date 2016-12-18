#include <bits/stdc++.h>
using namespace std;
int tamA;
int matit[200], mats[200], maT;
int pot[] = {1, 8, 27, 64, 125, 216,343,512,729,1000};
int Calc(int X) {
	int many = 0;
	while (X) {
		int id = upper_bound(pot, pot + 10, X) - pot;
		id--;
		X -= pot[id];
		many++;
	}
	return many;
}

void Pre() {
	maT = 0;
	for (int  i = 1; i < 1000; ++i) {
		int ans = Calc(i);
		if (ans >= maT) {
			matit[i] = ans;
			mats[i] = i;
			maT = ans;
		} else {
			matit[i] = matit[i - 1];
			mats[i] = mats[i - 1];
		}
		cout << i << ' ' << matit[i] << ' ' << mats[i] << '\n'; 
	}
	return;
}

int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	Pre();
	long long m;
	cin >> m;
	//if (m >= 106LL) {
		//cout << "10 106\n";
		//return 0;
	//}
	cout << matit[(int)m] << ' ' << mats[(int)m] << '\n';
	return 0;
}