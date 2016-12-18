#include <bits/stdc++.h>
using namespace std;

int mat[4][4];

int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	int N, llantas = 0, cofres = 0, cajuelas = 0, quemacocos = 0, puertas = 0;
	cin >> N;
	string name;
	char ax;
	while (N--) {
		cin.ignore();
		getline(cin, name);
		//cout << name << '\n';
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> ax;
				//cout << ax << ' ';
				mat[i][j] = (ax == '#');
			}
			//cout << '\n';
		}
		llantas += mat[0][0] + mat[2][0] + mat[2][2] + mat[0][2]; 
		cofres += mat[1][2];
		cajuelas += mat[1][0];
		quemacocos += mat[1][1];
		puertas += mat[0][1] + mat[2][1];
	}
	cout << llantas << '\n';
	cout << puertas << '\n';
	cout << cofres << '\n';
	cout << quemacocos << '\n';
	cout << cajuelas << '\n';
	
	return 0;
}