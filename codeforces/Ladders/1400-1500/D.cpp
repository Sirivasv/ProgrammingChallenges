#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;
typedef pair<char, pii> pli;

pli Bdi1, Bdi2, Bdi3, Bdi4, Bizq, Bder, Bup, Bdwn;
int fBdi1, fBdi2, fBdi3, fBdi4, fBizq, fBder, fBup, fBdwn;

lli Abs(lli xi) { return ((xi < 0)?(-xi):(xi)); }

lli Dist(lli xi, lli yi, pii a) {
	lli xj = a.first;
	lli yj = a.second;
	
	return ((xi - xj) * (xi - xj)) + ((yi - yj) * (yi - yj));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli posx, posy;
	int N;
	cin >> N;
	cin >> posx >> posy;
	
	//B mas cercano en di1, di2, di3, di 4, izq, der, up, dwn
	
	for (int i = 0; i < N; ++i) {
		char pi; lli pxj, pyj;
		cin >> pi >> pxj >> pyj;
		if (fBder) {
			if ((pyj == posy) && (posx < pxj)) {
				if ((Bder.second.first - posx) > (pxj - posx)) {
					Bder.second.first = pxj;
					Bder.first = pi;
				}
			} 
		} else {
			if ((pyj == posy) && (posx < pxj)) {
				Bder.second.first = pxj;
				Bder.first = pi;
				fBder = 1;
			} 
		}
		if (fBizq) {
			if ((pyj == posy) && (posx > pxj)) {
				if ((posx - Bizq.second.first) > (posx - pxj)) {
					Bizq.second.first = pxj;
					Bizq.first = pi;
				}
			} 
		} else {
			if ((pyj == posy) && (posx > pxj)) {
				Bizq.second.first = pxj;
				Bizq.first = pi;
				fBizq = 1;
			} 
		}
		if (fBup) {
			if ((pxj == posx) && (posy < pyj)) {
				if ((Bup.second.first - posy) > (pyj - posy)) {
					Bup.second.first = pyj;
					Bup.first = pi;
				}
			} 
		} else {
			if ((pxj == posx) && (posy < pyj)) {
				Bup.second.first = pyj;
				Bup.first = pi;
				fBup = 1;
			} 
		}
		if (fBdwn) {
			if ((pxj == posx) && (posy > pyj)) {
				if ((posy - Bdwn.second.first) > (posy - pyj)) {
					Bdwn.second.first = pyj;
					Bdwn.first = pi;
				}
			} 
		} else {
			if ((pxj == posx) && (posy > pyj)) {
				Bdwn.second.first = pyj;
				Bdwn.first = pi;
				fBdwn = 1;
			} 
		}
		
		if (fBdi1) {
			if (((pyj > posy) && (posx > pxj)) && (Abs(posx - pxj) == Abs(posy - pyj))) {
				if ((Dist(posx, posy, Bdi1.second)) > (Dist(posx, posy, pii(pxj, pyj)))) {
					Bdi1.second.first = pxj;
					Bdi1.second.second = pyj;
					Bdi1.first = pi;
				}
			} 
		} else {
			if (((pyj > posy) && (posx > pxj)) && (Abs(posx - pxj) == Abs(posy - pyj))) {
				Bdi1.second.first = pxj;
				Bdi1.second.second = pyj;
				Bdi1.first = pi;
				fBdi1 = 1;
			} 
		}
		
		if (fBdi2) {
			if (((pyj > posy) && (posx < pxj)) && (Abs(posx - pxj) == Abs(posy - pyj))) {
				if ((Dist(posx, posy, Bdi2.second)) > (Dist(posx, posy, pii(pxj, pyj)))) {
					Bdi2.second.first = pxj;
					Bdi2.second.second = pyj;
					Bdi2.first = pi;
				}
			} 
		} else {
			if (((pyj > posy) && (posx < pxj)) && (Abs(posx - pxj) == Abs(posy - pyj))) {
				Bdi2.second.first = pxj;
				Bdi2.second.second = pyj;
				Bdi2.first = pi;
				fBdi2 = 1;
			} 
		}
		
		if (fBdi3) {
			if (((pyj < posy) && (posx < pxj)) && (Abs(posx - pxj) == Abs(posy - pyj))) {
				if ((Dist(posx, posy, Bdi3.second)) > (Dist(posx, posy, pii(pxj, pyj)))) {
					Bdi3.second.first = pxj;
					Bdi3.second.second = pyj;
					Bdi3.first = pi;
				}
			} 
		} else {
			if (((pyj < posy) && (posx < pxj)) && (Abs(posx - pxj) == Abs(posy - pyj))) {
				Bdi3.second.first = pxj;
				Bdi3.second.second = pyj;
				Bdi3.first = pi;
				fBdi3 = 1;
			} 
		}
		
		if (fBdi4) {
			if (((pyj < posy) && (posx > pxj)) && (Abs(posx - pxj) == Abs(posy - pyj))) {
				if ((Dist(posx, posy, Bdi4.second)) > (Dist(posx, posy, pii(pxj, pyj)))) {
					Bdi4.second.first = pxj;
					Bdi4.second.second = pyj;
					Bdi4.first = pi;
				}
			} 
		} else {
			if (((pyj < posy) && (posx > pxj)) && (Abs(posx - pxj) == Abs(posy - pyj))) {

				Bdi4.second.first = pxj;
				Bdi4.second.second = pyj;
				Bdi4.first = pi;
				fBdi4 = 1;

			} 
		}
		
	}
	int ok = 1;
	if (fBder)
		if ((Bder.first == 'Q') || (Bder.first == 'R'))
			ok = 0;
	if (fBizq)
		if ((Bizq.first == 'Q') || (Bizq.first == 'R'))
			ok = 0;
	if (fBup)
		if ((Bup.first == 'Q') || (Bup.first == 'R'))
			ok = 0;
	if (fBdwn)
		if ((Bdwn.first == 'Q') || (Bdwn.first == 'R'))
			ok = 0;
	
	if (fBdi1)
		if ((Bdi1.first == 'Q') || (Bdi1.first == 'B'))
			ok = 0;
	if (fBdi2)
		if ((Bdi2.first == 'Q') || (Bdi2.first == 'B'))
			ok = 0;
	if (fBdi3)
		if ((Bdi3.first == 'Q') || (Bdi3.first == 'B'))
			ok = 0;
	if (fBdi4)
		if ((Bdi4.first == 'Q') || (Bdi4.first == 'B'))
			ok = 0;
	cout << ((!ok)?("YES\n"):("NO\n"));
	return 0;
}