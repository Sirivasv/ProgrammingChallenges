#include <bits/stdc++.h>
using namespace std;

int mtr[3009][3009], amtr[3009][3009];
int nz, nneg, npo, R, C, R_, C_, special;

inline int Range(int yi, int xi, int yj, int xj) {
	return amtr[yj][xj] + amtr[yi - 1][xi - 1] - amtr[yi - 1][xj] - amtr[yj][xi - 1];
}

inline int Checa(int X) {	
	int sum;
	for (int i = 1; i <= R; ++i) {
		sum = 0;
		for (int j = 1; j <= C; ++j) {
			sum += (mtr[i][j] > X);
			amtr[i][j] = amtr[i - 1][j] + sum;
		}
	}
	sum = nneg = npo = nz = 0;
	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j) { 
			int nx = j + C_ - 1, ny = i + R_ - 1;
			if (!((nx >= 0) && (nx <= C) && (ny >= 0) && (ny <= R)))continue;
			sum = Range(i, j, ny, nx);
			if (sum == special) nz++;
			else if (sum > special) npo++;
			else nneg++;
		}
	return 0;
}

inline int BusBin(){
	int mid, ini = 1, fin = R * C, ans;
	while (ini <= fin) {
		mid = (ini + fin) >> 1;
		Checa(mid);
		if ((npo) && (nz) && (!nneg)) {
			ans = mid;
			fin = mid - 1;
		} else if ((npo) && (!nz) && (!nneg)) {
			ini = mid + 1;
		} else if ((!npo) && (nz) && (nneg)) {
			ans = mid;
			fin = mid - 1;
		} else if ((!npo) && (!nz) && (nneg)) {
			fin = mid - 1; 
		} else if ((npo) && (!nz) && (nneg)) {
			fin = mid - 1;
		} else if ((npo) && (nz) && (nneg)) {
			ans = mid;
			fin = mid - 1;
		}
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> R >> C >> R_ >> C_;
	for (int i = 1; i <= R; ++i) 
		for (int j = 1; j <= C; ++j)
			cin >> mtr[i][j];
	special = (R_ * C_ - 1) >> 1;
	cout << BusBin() << '\n'; 
	return 0;
}