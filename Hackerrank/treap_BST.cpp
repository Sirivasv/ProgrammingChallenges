//Median Update Hackerrank https://www.hackerrank.com/challenges/median

#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

typedef struct treap {
	lli xi, yi, size;
	treap *izq, *der;

	treap(lli XI, lli YI = rand(), treap* I = NULL, treap* D = NULL) : 
	xi(XI), yi(YI), izq(I), der(D), size(1) {}

	~treap() {
		free(izq);
		free(der);
	}
	
} treap;

typedef treap* ptreap; 

lli SizeOf (ptreap t) { return (t == NULL) ? 0: t->size; }

void Recalc(ptreap t) { t->size = SizeOf(t->izq) + SizeOf(t->der) + 1; }

void Push(ptreap &R) { if (R == NULL) return; Recalc(R); }

void Merge(ptreap &R, ptreap I, ptreap D) {
	if ((I == NULL) && (D == NULL)) { R = NULL; return; }
	if (I == NULL) { Push(D); R = D; return; }
	Push(I);
	if (D == NULL) { R = I; return; }
	Push(D);
	if ((I->yi) > (D->yi)) { Merge(I->der, I->der, D); R = I;
	} else { Merge(D->izq, I, D->izq); R = D; }
	Push(R);
}

void Split(ptreap R, ptreap &I, ptreap &D, lli val) {
	if (R == NULL) { I = NULL; D = NULL; return; }
	Push(R);
	if (R->xi <= val) { Split(R->der, R->der, D, val); I = R;
	} else { Split(R->izq, I, R->izq, val); D = R; }
	Push(I); Push(D);
}

void Add(ptreap &R, ptreap item) {
	if (R == NULL) { R = item; return; }
	Push(R);
	if (item->yi > R->yi) { Split(R, item->izq, item->der, item->xi); R = item;
	} else Add(((R->xi <= item->xi) ? (R->der) : (R->izq)), item); 
	Push(R);
}

void Remove(ptreap &R, lli val) {
	if (R == NULL) return;
	Push(R);
	if (R->xi == val) {
		ptreap temp = R;
		Merge(R, R->izq, R->der);
		if (R == NULL) { return; }
		if (temp->size != R->size) free(temp);
	} else Remove(((R->xi < val) ? (R->der): (R->izq)), val);
	Push(R);
}

lli KthElement (ptreap &R, lli k) { 
	Push(R);
	lli sizeCur = SizeOf(R->izq) + 1;
	if (sizeCur == k) return R->xi;
	if (sizeCur > k) return KthElement(R->izq, k);
	return KthElement(R->der, k - sizeCur);
}

void median(vector<char> s,vector<lli> X) {
    lli lim = s.size();
    
    ptreap myTreap = NULL;
   	
    for (lli i = 0; i < lim; ++i) {
        if (s[i] == 'r') {
            if (myTreap == NULL) {
                cout << "Wrong!\n";
                continue;
            }
            lli tst = myTreap->size;
            Remove(myTreap, X[i]);
        	if ((myTreap != NULL) && (myTreap->size == tst)) {
                cout << "Wrong!\n";
                continue;
            }
        } else Add(myTreap, new treap(X[i]));

        if (myTreap == NULL) { cout << "Wrong!\n"; continue; }
        lli SZ = myTreap->size;
        if ((SZ & 1) == 0) {
            lli ELEI = KthElement(myTreap, SZ >> 1);
            lli ELED = KthElement(myTreap, (SZ >> 1) + 1);
            lli SUM = ELEI + ELED; 
            if (SUM & 1) cout << fixed << setprecision(1) << (double(SUM) / 2.0);
            else cout << (SUM >> 1);
            cout << '\n';
        } else
        	cout << KthElement(myTreap, (SZ >> 1) + 1) << '\n';
    }
    
}

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(0);
   lli N;
   cin >> N;
   
   vector<char> s;
    vector<lli> X;
   char temp;
    lli templli;
   for(lli i = 0; i < N; i++){
      cin >> temp >> templli;
        s.push_back(temp);
        X.push_back(templli);
   }
   
   median(s,X);
   return 0;
}
