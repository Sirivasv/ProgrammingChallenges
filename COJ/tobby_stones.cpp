#include <bits/stdc++.h>
using namespace std;

typedef int lli;

typedef pair<int, int> pii;

//lazy 1 ->flip colors
//lazy 2 ->set to a color

typedef struct treap {
	lli val, yi, ans, flip, setto; //ans its some function mats, etc.
  int size, reversed, scolor;
	treap *izq, *der;

	treap(lli VAL, lli YI = rand(), treap* I = NULL, treap* D = NULL) : 
	val(VAL), yi(YI), izq(I), der(D), size(1), ans(VAL), flip(0), setto(0) {}

	~treap() {
		free(izq);
		free(der);
	}
	
} treap;

typedef treap* ptreap; 

int SizeOf (ptreap t) { return (t) ? t->size : 0; }

void Recalc(ptreap t) { if(t) t->size = SizeOf(t->izq) + SizeOf(t->der) + 1; }

void Push(ptreap t) { 
  if (!t) return; //lazy can vary
  if (t->flip) {
    int tsize = SizeOf(t);
    t->val ^= 1;
    t->ans = tsize - (t->ans); //as the maximum stays just add lazy value; sum of range would involve multiply the size of the tree
    if (t->izq) t->izq->flip ^= 1;
    if (t->der) t->der->flip ^= 1;
    t->flip = 0;
  }
  if (t->setto) {
    int tsize = SizeOf(t);
    t->val = t->scolor;
    t->ans = (t->scolor)?(tsize):(0); //as the maximum stays just add lazy value; sum of range would involve multiply the size of the tree
    if (t->izq) { t->izq->setto = 1; t->izq->scolor = t->scolor; } 
    if (t->der) { t->der->setto = 1; t->der->scolor = t->scolor; }
    t->setto = 0;
  }
  if (t->reversed) {
    ptreap temp = t->izq;
    t->izq = t->der;
    t->der = temp;
    t->reversed = 0;
    if (t->izq) t->izq->reversed ^= 1;
    if (t->der) t->der->reversed ^= 1;
  }
}

void reset(ptreap t) { if (t) t->ans = t->val; } //as if the current node were new

void combine(ptreap& t, ptreap I, ptreap D) {
  if ((!I) && (!D)) return;
  if (!I || !D) { t->ans = I ? I->ans + t->val: D->ans + t->val; return; }
  t->ans = (I->ans + D->ans + t->val); //combine function like SegTree
}

void operation(ptreap t) {
  if (!t) return;
  
  reset(t);

  Push(t->izq); Push(t->der);
  combine(t, t->izq, t->der);
}

void Merge(ptreap &R, ptreap I, ptreap D) {
	Push(I); Push(D);
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
	Push(R);

  int curr_pos = add + SizeOf(R->izq) + 1;
  
  if (curr_pos <= pos) { 
    Split(R->der, R->der, D, pos, curr_pos); I = R;
	} else { Split(R->izq, I, R->izq, pos, add); D = R; }
	Recalc(R);
  operation(R);
}

inline void Insert(ptreap &R, ptreap item, int pos) {
	ptreap i = NULL, d = NULL;
  Split(R, i, d, pos - 1);
  Merge(i, i, item);
  Merge(R, i, d);
}

inline pii RangeQ(ptreap& R, int l, int r) {
  ptreap i = NULL, m = NULL, d = NULL;
  Split(R, i, m, l - 1);
  Split(m, m, d, r - l + 1); 
  lli res = m->ans;
  lli sz = SizeOf(m);
  Merge(m, m, d);
  Merge(R, i, m);
  return pii(sz - res, res);
}

inline void RangeU(ptreap& R, int l, int r, int opc, int sval = 0) {
  ptreap i = NULL, m = NULL, d = NULL;
  Split(R, i, m, l - 1);
  Split(m, m, d, r - l + 1);
  if (opc == 2) m->flip ^= 1;
  else { m->setto = 1; m->scolor = sval; }
  Merge(m, m, d);
  Merge(R, i, m);
}

inline void Reverse(ptreap& R, int l, int r) {
  ptreap i = NULL, m = NULL, d = NULL;
  Split(R, i, m, l - 1);
  Split(m, m, d, r - l + 1);
  m->reversed ^= 1;
  Merge(m, m, d);
  Merge(R, i, m);
}

int main(){
  //cin.tie(0); ios_base::sync_with_stdio(0);
  srand(time(NULL));
  int N, Q;
  while (scanf("%d%d", &N, &Q) != EOF) {
    ptreap myTreap = NULL;
    
    for (int i = 1; i <= N; ++i) Insert(myTreap, new treap(1), i);

    for (int i = 1; i <= Q; ++i) {
      int opc, I, J, S;
      //cin >> opc >> I >> J;
      scanf("%d%d%d", &opc, &I, &J);
      I++; J++;
      if (opc == 0) {
        pii res = RangeQ(myTreap, I, J);
        //cout << res.first << ' ' << res.second << '\n';
        printf("%d %d\n", res.first, res.second);
      } else if (opc == 1) Reverse(myTreap, I, J);
      else if (opc == 2) RangeU(myTreap, I, J, opc);
      else {
        //cin >> S;
        scanf("%d", &S);
        RangeU(myTreap, I, J, opc, S);
      }
    }

  }
  return 0;
}
