#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5009;
const long long MOD = 1000000007;
long long C[MAXN];

//numeros catalanes
//para n = 0: C[0] = 1
//para n = 1: C[1] = 1
//para n = 2: C[2] = 2
//para n = 3: C[3] = 5
//C[n] da el numero de arboles binarios posibles con n nodos || el numero de mergeos posibles hasta llegar a uno de n + 1 objetos

inline void CAT () { // O(n ^ 2) 
    C[0] = C[1] = 1;    
    for(int i = 2; i < MAXN; ++i)
        for(int j = 0; j < i; ++j) 
            C[i] = (C[i] + C[j] * C[i - j - 1])% MOD;
    return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int S, T;
	cin >> T;
	CAT();
	while (T--) {
		cin >> S;
		if (S == 1) {
			cout << "0\n";
			continue;
		}
		cout << C[S - 1] << '\n';
	}	
	return 0;
}