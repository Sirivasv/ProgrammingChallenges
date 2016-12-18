#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;

int N, M, idT;

int Arr[MAXN], Brr[MAXN], Trr[MAXN * 2];

int BusBin(int *arr, int val, int lim) {
	int ini = 0, fin = lim, m, ans = -1;
	while (ini <= fin) {
		m = (ini + fin) / 2;
		if (arr[m] <= val) {
			ans = m;
			ini = m + 1;
		} else 
			fin = m - 1;
	}
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	Trr[idT++] = 0;
	for (int i = 0; i < N; ++i) {
		cin >> Arr[i];
		Trr[idT++] = Arr[i];
	}
	cin >> M;
	for (int j = 0; j < M; ++j) {
		cin >> Brr[j];
		Trr[idT++] = Brr[j];
	}
	sort(Arr, Arr + N);
	sort(Brr, Brr + M);
	sort(Trr, Trr + idT);
	int mats = -2000000001, matsa, matsb, matsv;
	for (int i = 0; i < idT; ++i) {
		int val = Trr[i];
		int I = BusBin(Arr, val, N - 1);
		int J = BusBin(Brr, val, M - 1);
		I++; J++;
		int puntA = (I * 2) + ((N - I) * 3);
		int puntB = (J * 2) + ((M - J) * 3);
		if ((puntA - puntB) >= mats) {
			if ((puntA - puntB) > mats) {
				mats = (puntA - puntB);
				matsa = puntA;
				matsb = puntB;
				matsv = val;
			} else {
				if (puntA > matsa) {
					matsa = puntA;
					matsb = puntB;
					matsv = val;
 				}
			}
		}
	}
	
	cout << matsa << ':' << matsb << '\n';
	return 0;
}