#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1000000;
//ST indexado desde uno
int ST[SIZE][4], Lazy[SIZE];
//ST[0] maximo espacio
//ST[1] ceros a partir del lado izq
//ST[2] ceros a partir del lado der

void Update(int a, int b, int v, int n, int L, int R) {
    if (L > b || R < a) return;
    int mid = (L + R) >> 1;
	int tmp, lc = (n << 1), rc = (n << 1) + 1;
	
	if ((Lazy[n] == 1) && (L != R)) {
		for (int i = 0; i < 3; ++i) ST[lc][i] = 0;
		for (int i = 0; i < 3; ++i) ST[rc][i] = 0;
		Lazy[lc] = 1;
		Lazy[rc] = 1;
		Lazy[n] = -1;
	} else if ((Lazy[n] == 0) && (L != R)) {
		for (int i = 0; i < 3; ++i) ST[lc][i] = mid - L + 1;
		for (int i = 0; i < 3; ++i) ST[rc][i] = R - mid;
		Lazy[lc] = 0;
		Lazy[rc] = 0;
		Lazy[n] = -1;
	}
	
    if (L >= a && R <= b) {
		Lazy[n] = v;
		if (v == 1) for (int i = 0; i < 3; ++i) ST[n][i] = 0;
		else for (int i = 0; i < 3; ++i) ST[n][i] = R - L + 1;
        return;
    }
	
    Update(a, b, v, lc, L, mid);
    Update(a, b, v, rc, mid + 1, R);    
    
	if ((mid - L + 1) == (ST[lc][1])) ST[n][1] = ST[lc][1] + ST[rc][1];
	else ST[n][1] = ST[lc][1];
	
	if ((R - (mid + 1) + 1) == (ST[rc][2])) ST[n][2] = ST[rc][2] + ST[lc][2];
	else ST[n][2] = ST[rc][2];	
	
	ST[n][0] = max(ST[lc][0], max(ST[rc][0], ST[lc][2] + ST[rc][1]));
	
	return;
}   

int Query(int a, int b, int n, int L, int R, int sval) {
    //if (L > b || R < a) return 0;
    int mid = (L + R) >> 1;
	int tmp, lc = (n << 1), rc = (n << 1) + 1;
    if ((Lazy[n] == 1) && (L != R)) {
		for (int i = 0; i < 3; ++i) ST[lc][i] = 0;
		for (int i = 0; i < 3; ++i) ST[rc][i] = 0;
		Lazy[lc] = 1;
		Lazy[rc] = 1;
		Lazy[n] = -1;
	} else if ((Lazy[n] == 0) && (L != R)) {
		for (int i = 0; i < 3; ++i) ST[lc][i] = mid - L + 1;
		for (int i = 0; i < 3; ++i) ST[rc][i] = R - mid;
		Lazy[lc] = 0;
		Lazy[rc] = 0;
		Lazy[n] = -1;
	}
	
	if (ST[n][0] < sval) return 0;
	if (L == R) return L;
	if (ST[lc][0] >= sval) return Query(a, b, lc, L, mid, sval);
	if (ST[lc][2] + ST[rc][1] >= sval) return mid - ST[lc][2] + 1;
	if (ST[rc][0] >= sval) return Query(a, b, rc,  mid + 1, R, sval);
}

int main() { 
    int Q, opc, N, a, b;
	scanf("%d%d", &N, &Q);
    Update(1, N, 0, 1, 1, N);
    for (int j = 0; j < Q; ++j) {
		scanf("%d%d", &opc, &a);
        if (opc == 1) {
			int pos = Query(1, N, 1, 1, N, a);
			printf("%d\n", pos);
			if (pos) Update(pos, pos + a - 1, 1, 1, 1, N);
		} else {
			scanf("%d", &b);
			Update(a, a + b - 1, 0, 1, 1, N); 
		}
    }
	return 0;
}