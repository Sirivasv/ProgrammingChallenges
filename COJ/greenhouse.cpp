#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2009;

int mtr[MAXN][MAXN];
int acumP[MAXN][MAXN], acumF[MAXN][MAXN];

int Subs2DP(int xi, int yi, int xj, int yj) {
	int vall = acumP[yj][xi - 1];
	int valu = acumP[yi - 1][xj];
	int vald = acumP[yi - 1][xi - 1];
	return (acumP[yj][xj] - vall - valu + vald);
}

int Subs2DF(int xi, int yi, int xj, int yj) {
	int vall = acumF[yj][xi - 1];
	int valu = acumF[yi - 1][xj];
	int vald = acumF[yi - 1][xi - 1];
	return (acumF[yj][xj] - vall - valu + vald);
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int columnas, filas, pines, fru;
	cin >> columnas >> filas >> pines >> fru;
	for (int i = 0; i < pines; ++i) {
		int xi, yi;
		cin >> xi >> yi;
		mtr[filas - yi][xi - 1] = 2;
	}
	
	for (int i = 0; i < fru; ++i) {
		int xi, yi;
		cin >> xi >> yi;
		mtr[filas - yi][xi - 1] = 1;
	}
	
	//acum de pinos
	for (int i = 1; i <= filas; ++i) {
		int acum = 0;
		for (int j = 1; j <= columnas; ++j) {
			if (mtr[i - 1][j - 1] == 2)
				acum++;
			acumP[i][j] = acumP[i - 1][j] + acum;
		}
	}
	
	//acum de fru
	for (int i = 1; i <= filas; ++i) {
		int acum = 0;
		for (int j = 1; j <= columnas; ++j) {
			if (mtr[i - 1][j - 1] == 1)
				acum++;
			acumF[i][j] = acumF[i - 1][j] + acum;
		}
	}
	
	//Recorrido de empezar en cada Celda
	
	int adistod, adistou, asi = (1 << 30), af = -1;
	
	for (int i = 1; i <= filas; ++i) {
		for (int j = 1; j <= columnas; ++j) {
			if (mtr[i - 1][j - 1] == 2)
				continue;
			int ini = 1, fin = min(columnas - j + 1, filas - i + 1), ans = min(columnas - j + 1, filas - i + 1);
			while (ini <= fin) {
				int m = (ini + fin) >> 1;
				if (Subs2DP(j, i, j + m - 1, i + m - 1)) {
					fin = m - 1;
				} else {
					ini = m + 1;
					ans = m;
				}
			}
			
			int val = Subs2DF(j, i, j + ans - 1, i + ans - 1);
			
			ini = 1, fin = ans;
			
			while (ini <= fin) {
				int m = (ini + fin) >> 1;
				if (Subs2DF(j, i, j + m - 1, i + m - 1) == val) {
					ans = m;
					fin = m - 1;
				} else {
					ini = m + 1;
				}
			}
			
			if (val > af) {
				asi = ans;
				af = val;
				adistod = j - 1;
				adistou = filas - (i + ans) + 1;
			} else if ((val == af) && (ans < asi)){
				asi = ans;
				af = val;
				adistod = j - 1;
				adistou = filas - (i + ans) + 1;
			}
			
		}
	}
	cout << adistod << ' ' << adistou << '\n';
	cout << asi << '\n';
	cout << af << '\n';
	return 0;
}