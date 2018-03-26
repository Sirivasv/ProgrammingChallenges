#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
const int INF = 1e9;

struct node{

	int val,lazy ;
	node *izq,*der;

	node(): izq(NULL),der(NULL),val(0),lazy(1) {}

};
typedef node* pnode;

void construye(int ini,int fin,pnode &raiz, vector<int> &ar){
	raiz = new node();
	if(ini == fin){
		raiz -> val = ar[ini];
		return;
	}

	int mitad = (ini+fin)/2;
	construye(ini,mitad,raiz->izq,ar);
	construye(mitad+1,fin,raiz->der,ar);

	raiz -> val = max(raiz->izq -> val,raiz -> der -> val);

}

int get(int ini,int fin, pnode raiz){

	if(raiz -> lazy != 1){
		raiz -> val *= raiz -> lazy;
		if( ini != fin) {
			raiz -> izq -> lazy *= raiz -> lazy;
			raiz -> der -> lazy *= raiz -> lazy;
		}
		raiz -> lazy = 1;
	}

	return raiz -> val;

}


int query(int ini,int fin, pnode raiz, int x){

	if(raiz -> lazy != 1){
		raiz -> val *= raiz -> lazy;
		if( ini != fin) {
			raiz -> izq -> lazy *= raiz -> lazy;
			raiz -> der -> lazy *= raiz -> lazy;
		}
		raiz -> lazy = 1;
	}

	if(ini == fin) return ini;
	int mitad = (ini+fin)/2;

	int izq = get(ini,mitad,raiz -> izq);
	if(izq >= x){
		query(ini,mitad,raiz-> izq,x);
	} else {	
		query(mitad+1,fin,raiz-> der,x);
	}
	
}

void update(int ini,int fin,pnode raiz,int pos,int val){

	if(raiz -> lazy != 1){
		raiz -> val *= raiz -> lazy;
		if( ini != fin) {
			raiz -> izq -> lazy *= raiz -> lazy;
			raiz -> der -> lazy *= raiz -> lazy;
		}
		raiz -> lazy = 1;
	}

	if( pos < ini || fin < pos ) return;
	if(ini == pos && fin == pos){
		raiz -> val = val;
		return;
	}	

	int mitad = (ini+fin)/2;
	update(ini,mitad,raiz->izq,pos,val);
	update(mitad+1,fin,raiz->der,pos,val);

	raiz -> val = max(raiz->izq -> val,raiz -> der -> val);

}

void updateL(int ini,int fin,pnode raiz,int inir,int finr){


	if(raiz -> lazy != 1){
		raiz -> val *= raiz -> lazy;
		if( ini != fin) {
			raiz -> izq -> lazy *= raiz -> lazy;
			raiz -> der -> lazy *= raiz -> lazy;
		}
		raiz -> lazy = 1;
	}

	if(finr < ini || fin < inir) return;
	if( ini >= inir && fin <= finr){

		raiz -> val *= -1;
		if( ini != fin) {
			raiz -> izq -> lazy *= -1;
			raiz -> der -> lazy *= -1;
		}
		return;
	}

	int mitad = (ini+fin)/2;

	updateL(ini,mitad,raiz->izq,inir,finr);
	updateL(mitad+1,fin,raiz->der,inir,finr);
	
	raiz -> val = max(raiz->izq -> val,raiz -> der -> val);


}

int main(){
	
	int N , M ;
	int tipo, a, b;

	optimizar_io(0);

	cin >> N >> M;
	vector<int> ar(N);

	for(int i = 0 ; i < N ; i++)
		cin >> ar[i];
	
	pnode raiz = NULL;
	construye(0,N-1,raiz,ar);

	for(int i = 0 ; i < M; i++){
		cin >> tipo >> a >> b ;
		a--;
		if(tipo == 0 ){			
			update(0,N-1,raiz,a,b);
		} else {

			if( b == 0 ) cout << a + 1 << '\n';
			else {
				if(a) updateL(0,N-1,raiz,0,a-1);

				if(get(0,N-1,raiz) >= b) cout << query(0,N-1,raiz,b) + 1 << '\n';
				else cout << "-1\n";

				if(a) updateL(0,N-1,raiz,0,a-1);
			}

		}
 	}

	return 0;

}
