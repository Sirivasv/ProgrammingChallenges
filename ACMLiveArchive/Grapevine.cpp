 #include <bits/stdc++.h>
 using namespace std;
 int R, C, Q, a, b, field[509][509];
 
 inline int FBusbinv(int cid, int ini, int fin, int x) {
	 int mid, ans = -1;
	 while (ini <= fin) {
		 mid = (fin + ini) >> 1;
		 if (field[mid][cid] >= x) {
			 ans = mid;
			 fin =  mid - 1;
		 } else ini = mid + 1;
	 }
	 return ans;
 }
 
 inline int LBusbinv (int cid, int ini, int fin, int x) {
	 if (!(cid < C)) return -1;
	 int mid, ans = -1;
	 while (ini <= fin) {
		 mid = (fin + ini) >> 1;
		 if (field[mid][cid] <= x) {
			 ans = mid;
			 ini = mid + 1;
		 } else fin = mid - 1;
	 }
	 return ans;
 }
  
 inline int LBusbinh (int rid, int ini, int fin, int x) { 
	int mid, ans = -1;
	while (ini <= fin) {
		mid = (fin + ini) >> 1;
		if (field[rid][mid] <= x) {
			ans = mid;
			ini = mid + 1;
		} else fin = mid - 1;
	}
	return ans;
 }
 
 inline int LBusbinvh (int ridini, int ridfin, int ini, int fin, int x) { 
	int mid, ans = ridini, orig = ridini, aux, a, b;
	while (ridini <= ridfin) {
		mid = (ridfin + ridini) >> 1;
		aux = LBusbinh(mid, ini, fin, x);
		b = (mid - orig + 1);
		if ((aux - ini + 2) >= b) {
			ans = b;
			//cout << " ** " << aux << '\n';
			ridini = mid + 1;
		} else ridfin = mid - 1;
	}
	return ans;
 }
 
 int mats = 0, ht, dwn, fst, fsth;
 inline int Query(int l, int h) {
	 mats = 0;
	 //cout << "L: " << l << " H: " << h << '\n';
	for (int i = 0; i < C; ++i) {
		ht = FBusbinv(i, 0, R - 1, l);
		if (ht == -1) continue;
		dwn = LBusbinv(i, ht, R - 1, h);
		//cout << "col: " << i << " ht: " << ht << " dwn: " << dwn << '\n'; 
		if (dwn == -1) continue;
		fst = LBusbinv(i + 1, ht, dwn, h);
		//cout << "fst: " << fst << '\n';
		if (fst == -1) {
			mats = max(mats, 1);
			continue;
		}
		fsth = LBusbinvh(ht, fst, i + 1, C - 1, h);
		//cout << "posv: " << fsth << " mats: " << mats << '\n';
		mats = max(mats, fsth);
	}
	return mats;
 }
 
 int main() {
	 
	 while (scanf("%d%d", &R, &C)) {
		 if (!(R + C)) break;
		 for (int i = 0; i < R; ++i)
			 for (int j = 0; j < C; ++j) cin >> field[i][j];
		 scanf("%d", &Q);
		 for (int i = 0; i < Q; ++i) {
			 scanf("%d%d", &a, &b);
			 printf("%d\n", Query(a, b));
			//cout << "***\n";
		 }
		 printf("-\n");
	 }
	 return 0;
 }