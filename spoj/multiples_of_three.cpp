#include <bits/stdc++.h>
using namespace std;
const int SIZE = 400000 + 5; // MAXN << 2
//ST indexado desde uno
int ST[SIZE][4], Lazy[SIZE];

inline void Update_i(int a, int b, int v, int n, int L, int R) {
    if (L > b || R < a) return;
    if (L >= a && R <= b) {
        ST[n][v] = 1;
        return;
    }
    int mid = (L + R) >> 1, lc = (n << 1), rc = (n << 1) + 1;
    Update_i(a, b, v, lc, L, mid);
    Update_i(a, b, v, rc, mid + 1, R);    
    ST[n][0] = ST[lc][0] + ST[rc][0];
	return;
}

inline void Update(int a, int b, int v, int n, int L, int R) {
    if (L > b || R < a) return;
    int mid = (L + R) >> 1;
	int tmp, lc = (n << 1), rc = (n << 1) + 1;
	if ((Lazy[n]) && (L != R)) {
		while (Lazy[n]){
			//rolling left child
			tmp = ST[lc][2];
			ST[lc][2] = ST[lc][1];
			ST[lc][1] = ST[lc][0];
			ST[lc][0] = tmp;
			//rolling right child
			tmp = ST[rc][2];
			ST[rc][2] = ST[rc][1];
			ST[rc][1] = ST[rc][0];
			ST[rc][0] = tmp;
			//updating lazy flags
			Lazy[lc]++;
			Lazy[lc] %= 3;
			Lazy[rc]++;
			Lazy[rc] %= 3;
			Lazy[n]--;
		}	
	}
    if (L >= a && R <= b) {
		Lazy[n] += 1;
		Lazy[n] %= 3;
		//rolling this node lol
		tmp = ST[n][2];
		ST[n][2] = ST[n][1];
		ST[n][1] = ST[n][0];
		ST[n][0] = tmp;
        return;
    }
    Update(a, b, v, lc, L, mid);
    Update(a, b, v, rc, mid + 1, R);    
    for (int i = 0; i < 3; ++i) ST[n][i] = ST[lc][i] + ST[rc][i];
	return;
}   

inline int Query(int a, int b, int n, int L, int R) {
    if (L > b || R < a) return 0;
    int mid = (L + R) >> 1;
	int tmp, lc = (n << 1), rc = (n << 1) + 1;
    if ((Lazy[n]) && (L != R)) {
		while (Lazy[n]){
			//rolling left child
			tmp = ST[lc][2];
			ST[lc][2] = ST[lc][1];
			ST[lc][1] = ST[lc][0];
			ST[lc][0] = tmp;
			//rolling right child
			tmp = ST[rc][2];
			ST[rc][2] = ST[rc][1];
			ST[rc][1] = ST[rc][0];
			ST[rc][0] = tmp;
			//updating lazy flags
			Lazy[lc]++;
			Lazy[lc] %= 3;
			Lazy[rc]++;
			Lazy[rc] %= 3;
			Lazy[n]--;
		}	
	}
    if (L >= a && R <= b) return ST[n][0];
    return Query(a, b, lc, L, mid) + Query(a, b, rc, mid + 1, R);
}

int main() { 
    int Q, opc, N, a, b;
	scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; ++i) Update_i(i + 1, i + 1, 0, 1, 1, N);
    for (int j = 0; j < Q; ++j) {
		scanf("%d %d %d", &opc, &a, &b);
        if (opc) printf("%d\n", Query(a + 1, b + 1, 1, 1, N));
        else Update(a + 1, b + 1, 1, 1, 1, N); 
    }
	return 0;
}