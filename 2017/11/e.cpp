#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;

vector<int> A, B;
int a, b, c;
int memo[5][3][10][10][5][5];
int flag[5][3][10][10][5][5];
int ID;

int DP(int turno, int quien, int mimask, int hismask, int mispuntos, int suspuntos) {
	if (flag[turno][quien][mimask][hismask][mispuntos][suspuntos] == ID) return memo[turno][quien][mimask][hismask][mispuntos][suspuntos];
	flag[turno][quien][mimask][hismask][mispuntos][suspuntos] = ID;
	if (turno == 4) return memo[turno][quien][mimask][hismask][mispuntos][suspuntos] = (mispuntos >= 2);
	if (quien == 0) { //mi turno debo ganar con alguno de mis movimientos
		int res = 0;
		for (int i = 0; i < 3; ++i) {
			if (mimask & (1 << i)) continue; //ya lo tome
			int inner_win = 1;
			for (int j = 0; j < 3; ++j) { //su eleccion no importa cual debo ganarle
				if (hismask & (1 << j)) continue; //ya lo tomo el
				
				inner_win &= DP(turno + 1, 1 - (A[i] < B[j]), mimask | (1 << i), hismask | (1 << j), mispuntos + (A[i] < B[j]), suspuntos + (B[j] < A[i]));

			}
			res |= inner_win;
		}
		return memo[turno][quien][mimask][hismask][mispuntos][suspuntos] = res;
	} else { //Su turno debo ganarle en todos sus movimientos
		int res = 1;
		for (int i = 0; i < 3; ++i) {
			if (hismask & (1 << i)) continue; //ya lo tomo
			int inner_win = 0;
			for (int j = 0; j < 3; ++j) { //mi eleccion debo ganarle con al menos uno
				if (mimask & (1 << j)) continue; //ya lo tome
				
				inner_win |= DP(turno + 1, 1 - (A[j] < B[i]), mimask | (1 << j), hismask | (1 << i), mispuntos + (A[j] < B[i]), suspuntos + (B[i] < A[j]));

			}
			res &= inner_win;
		}
		return memo[turno][quien][mimask][hismask][mispuntos][suspuntos] = res;
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> a >> b >> c;
	A.push_back(a);
	A.push_back(b);
	A.push_back(c);

	for (int i = 1; i <= 7; ++i) {
		int found = 0;
		for (int j = 0; j < 3; ++j) if (A[j] == i) found = 1;
		if (!found) B.push_back(i);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int can = 1;

	do {

		ID++;
		can &= DP(1, 0, 0, 0, 0, 0);

	} while(next_permutationn(B.begin(), B.end()));

	if (can) cout << "S\n";
	else cout << "N\n";
	return 0;
}