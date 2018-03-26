#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

struct node{

	int val ;
	node *izq,*der;

	node(): izq(NULL),der(NULL),val(0) {}

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

	raiz -> val = __gcd(raiz->izq -> val,raiz -> der -> val);

}

int query(int ini,int fin, pnode raiz, int inir,int finr){

	if(fin < inir || finr < ini ) return -1;
	if(ini >= inir && fin <= finr) return raiz -> val;
	int mitad = (ini+fin)/2;
	int izq = query(ini,mitad,raiz -> izq, inir,finr);
	int der = query(mitad+1,fin,raiz -> der, inir,finr);
	if(izq == -1) return der;
	else if(der == -1) return izq;
	else return __gcd(izq,der);
	
}

int main(){

	int a, b;
	int N , M ;

	optimizar_io(0);

	cin >> N;
	vector<int> ar(N);

	for(int i = 0 ; i < N ; i++)
		cin >> ar[i];
	
	pnode raiz = NULL;
	construye(0,N-1,raiz,ar);

	cin >> M;
	for(int i = 0 ; i < M; i++){
		cin >> a >> b ;
		a--,b--;
		cout << query(0,N-1,raiz,a,b) << '\n';
	}

	return 0;

}
