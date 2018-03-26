#include <bits/stdc++.h>
using namespace std;

int cubeta[500009];

struct SegTree{
	int dato;
	SegTree* izq, *der;
	SegTree(): izq(NULL), der(NULL), dato(0){}
	~SegTree(){
		if(izq) delete izq;
		if(der) delete der;
	}

	void Update(int left, int right, int val, int L, int R){
		if( L > right || R < left ) return;
		if( !izq ){
			izq = new SegTree();
			der = new SegTree();
		}
		if( dato != 0 && L != R ){
			izq->dato = dato;
			der->dato = dato;
			dato = 0;
		}

		if( L >= left && R <= right ){
			dato = val;
			return;
		}
		int m = (L+R)>>1;
		izq->Update( left, right, val, L, m );
		der->Update( left, right, val, m+1, R );

		return;
	}

	void recorre( int L, int R ){
		if( dato != 0 ){
			cubeta[dato] += R-L+1;
			return;
		}
		int m = (L+R)>>1;
		if( izq ){
			izq->recorre(L, m);
			der->recorre(m+1, R);
		}
	}
};

int main(){

	int N, C, Q, color, i, d;
	SegTree *seg = new SegTree();
	cin >> N >> C >> Q;

	while( Q-- ){
		cin >> color >> i >> d;
		seg->Update(i, d, color, 1, N);
	}

	seg->recorre(1, N);
	for( int i = 0; i < C; i++ ){
		if( i ) cout << ' ';
		cout << cubeta[i+1];
	}
	cout << '\n';

	return 0;
}