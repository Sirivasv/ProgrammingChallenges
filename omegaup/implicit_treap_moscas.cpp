#include <bits/stdc++.h>
using namespace std;

typedef int lli;

typedef struct treap {
	lli val, yi, ans, lazy; //ans its some function mats, etc.
  int size;
	treap *izq, *der;

	treap(lli VAL, lli YI = rand(), treap* I = NULL, treap* D = NULL) : 
	val(VAL), yi(YI), izq(I), der(D), size(1), ans(VAL), lazy(0) {}

	~treap() {
		free(izq);
		free(der);
	}
	
} treap;

typedef treap* ptreap; 

int SizeOf (ptreap t) { return (t) ? t->size : 0; }

void Recalc(ptreap t) { if(t) t->size = SizeOf(t->izq) + SizeOf(t->der) + 1; }

void Push(ptreap t) { 
  if (!t || (t->lazy == 0)) return; //lazy can vary
  t->val += t->lazy;
  t->ans += t->lazy; //as the maximum stays just add lazy value; sum of range would involve multiply the size of the tree
  if (t->izq) t->izq->lazy += t->lazy;
  if (t->der) t->der->lazy += t->lazy;
  t->lazy = 0;
}

void reset(ptreap t) { if (t) t->ans = t->val; } //as if the current node were new

void combine(ptreap& t, ptreap I, ptreap D) {
  if (!I || !D) { t->ans = I ? I->ans: D->ans; return; }
  t->ans = max(I->ans, D->ans); //combine function like SegTree
}

void operation(ptreap t) {
  if (!t) return;
  reset(t);
  Push(t->izq); Push(t->der);
  combine(t, t->izq, t);
  combine(t, t, t->der);
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

void Remove(ptreap &R, int pos) {
	ptreap i, m, d;
  Split(R, i, m, pos - 1);
  Split(m, m, d, pos);
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

void RangeU(ptreap& R, int l, int r, lli val) {
  ptreap i = NULL, m = NULL, d = NULL;
  Split(R, i, m, l - 1);
  Split(m, m, d, r - l + 1);
  m->lazy += val;
  Merge(m, m, d);
  Merge(R, i, m);
}

const int MAXL = 60003;

int expo[MAXL];

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);

  int N;
  cin >> N;
  ptreap myTreap = NULL;
  for (int i = 1; i < MAXL; ++i) Insert(myTreap, new treap(0), i);
  for (int i = 0; i < N; ++i) {
    int ini, fin;
    cin >> ini >> fin;
    RangeU(myTreap, ini, fin - 1, 1);
  }

  int max_cnt = -1;

  for (int i = 1; i < MAXL; ++i) {
    expo[i] = RangeQ(myTreap, i, i);
    max_cnt = max(max_cnt, expo[i]);
  }
  cout << max_cnt << '\n';
  
  int ini = 1, fin = 1;

  while ((ini < MAXL) && (fin < MAXL)) {
    while ((ini < MAXL) && (expo[ini] != max_cnt)) ++ini;
    fin = ini;
    while ((fin < MAXL) && (expo[fin] == max_cnt)) ++fin;
    if ((ini != MAXL) && (fin != MAXL)) cout << ini << ' ' << fin << '\n';
    ini = fin; 
  }
  return 0;
}
