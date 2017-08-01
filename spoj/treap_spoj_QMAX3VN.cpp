// SPOJ http://www.spoj.com/problems/QMAX3VN/en/ 

#include <bits/stdc++.h>
using namespace std;

typedef int lli;

typedef struct treap {
	lli val, yi, ans, lazy; //ans its some function mats, etc.
  int size;
	treap *izq, *der;

	treap(lli VAL, lli YI = rand(), treap* I = NULL, treap* D = NULL) : 
	val(VAL), yi(YI), izq(I), der(D), size(1), ans(VAL) {}

	~treap() {
		free(izq);
		free(der);
	}
	
} treap;

typedef treap* ptreap; 

int SizeOf (ptreap t) { return (t) ? t->size : 0; }

void Recalc(ptreap t) { if(t) t->size = SizeOf(t->izq) + SizeOf(t->der) + 1; }

void reset(ptreap t) { if (t) t->ans = t->val; } //as if the current node were new

void combine(ptreap& t, ptreap I, ptreap D) {
  if (!I || !D) { t->ans = I ? I->ans: D->ans; return; }
  t->ans = max(I->ans, D->ans); //combine function like SegTree
}

void operation(ptreap t) {
  if (!t) return;
  reset(t);
  combine(t, t->izq, t);
  combine(t, t, t->der);
}

void Merge(ptreap &R, ptreap I, ptreap D) {
	if ((!I) && (!D)) { R = NULL; return; }
	if (I == NULL) { R = D; return; }
	if (D == NULL) { R = I; return; }
	if ((I->yi) > (D->yi)) { Merge(I->der, I->der, D); R = I;
	} else { Merge(D->izq, I, D->izq); R = D; }
	Recalc(R);
  operation(R);
}

void Split(ptreap R, ptreap &I, ptreap &D, int pos, int add = 0) {
	if (!R) { I = NULL; D = NULL; return; }
	int curr_pos = add + SizeOf(R->izq) + 1;
  if (curr_pos <= pos) { Split(R->der, R->der, D, pos, curr_pos); I = R;
	} else { Split(R->izq, I, R->izq, pos, add); D = R; }
	Recalc(R);
  operation(R);
}

void Insert(ptreap &R, ptreap item, int pos) {
	ptreap i = NULL, d = NULL;
  Split(R, i, d, pos - 1);
  Merge(i, i, item);
  Merge(R, i, d);
}

lli RangeQ(ptreap& R, int l, int r) {
  ptreap i = NULL, m = NULL, d = NULL;
  Split(R, i, m, l - 1);
  Split(m, m, d, r - l + 1); 
  lli res = m->ans;
  Merge(m, m, d);
  Merge(R, i, m);
  return res;
}

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);

  int T, I, J;
  char opc;
  ptreap myTreap = NULL;
  cin >> T;
  while (T--) {
    cin >> opc >> I >> J;
    
    if (opc == 'A') Insert(myTreap, new treap(I), J);
    else cout << RangeQ(myTreap, I, J) << '\n';

  }
  return 0;
}
