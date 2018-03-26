#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef long long lli;
const int INF = 1<<30;
typedef pair<int, int> pii;

struct node{

	pii val;
	node *izq,*der;

	node(): izq(NULL),der(NULL),val() {}

};
typedef node* pnode;

void construye(int ini,int fin,pnode &raiz, vector<int> &ar){
	raiz = new node();
	if(ini == fin){
		raiz -> val = pii(ar[ini], ar[ini]);
		return;
	}

	int mitad = (ini+fin)/2;
	construye(ini,mitad,raiz->izq,ar);
	construye(mitad+1,fin,raiz->der,ar);

	raiz->val = pii( min(raiz->izq->val.first, raiz->der->val.first), max(raiz->izq->val.second, raiz->der->val.second));

}

pii query(int ini,int fin, pnode raiz, int inir,int finr){

	if(fin < inir || finr < ini ) return pii(-INF, -INF);
	if(ini >= inir && fin <= finr) return raiz->val;
	int mitad = (ini+fin)/2;
	pii izq = query(ini,mitad,raiz -> izq, inir,finr);
	pii der = query(mitad+1,fin,raiz -> der, inir,finr);
	if(izq.first == -INF) return der;
	else if(der.first == -INF) return izq;
	
	return pii(min(izq.first, der.first), max(izq.second, der.second));	
}

void Update(int ini,int fin, pnode raiz, int at,int val){
	if(fin < at || at < ini ) return;
	if(ini >= at && fin <= at) {
		raiz -> val = pii(val, val);
		return;
	}
	
	int mitad = (ini+fin)/2;
	Update(ini,mitad,raiz->izq, at, val);
	Update(mitad + 1,fin,raiz->der, at, val);
	raiz->val = pii( min(raiz->izq->val.first, raiz->der->val.first), max(raiz->izq->val.second, raiz->der->val.second));
}

const lli MOD = 12345LL;
const lli MOD2 = 23456LL;

int main(){

	int a, b;
	int N , M ;

	optimizar_io(0);

	N = 500000;
	vector<int> ar(N, 0);
	for( int i = 0; i < N; i++ ){
		lli val = i+1;
		lli val2 = (val * val) %  MOD;
		lli val3 = (val * val * val) % MOD2;
		ar[i] = val2 + val3;
	}

	
	pnode raiz = NULL;
	construye(0,N-1,raiz,ar);
	cin >> M;
	for(int i = 0 ; i < M; i++){
		cin >> a >> b ;
		if (a < 0) {
			Update(0, N-1, raiz, -a - 1, b);	
		} else {
			pii res = query(0,N-1,raiz,a - 1,b - 1);
			cout << res.second - res.first << '\n';
		}
	}

	return 0;

}
