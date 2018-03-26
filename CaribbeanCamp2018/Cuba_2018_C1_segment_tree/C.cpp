#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef pair<int,int> Par;

struct cuad{

	int f,ini,fin,tipo;
	cuad(int F,int Ini,int Fin,int Tipo) : f(F),ini(Ini),fin(Fin),tipo(Tipo) {}
};

struct punto{
	int f,c;
	punto() : f(0),c(0){}
};

bool operator<(cuad a,cuad b){
	if(a.f == b.f) return a.tipo > b.tipo;
	return a.f < b.f;
}

struct node{
	Par valor;
	int lazy;
	node *izq,*der;
	node() : valor(), lazy(0),izq(NULL),der(NULL) {}
};
typedef node* pnode;

void ifcreate(int ini,int fin,pnode &raiz){
	if(raiz == NULL){
		raiz = new node();
		raiz -> valor = Par(0,ini);
	}
}

void push(int ini,int fin, pnode &raiz){
	int mitad = (ini+fin)/2;
	if(raiz -> lazy != 0){
		(raiz -> valor).first += raiz -> lazy;
		if(ini != fin){
			ifcreate(ini,mitad,raiz->izq);
			ifcreate(mitad+1,fin,raiz->der);
			raiz -> izq -> lazy += raiz -> lazy;
			raiz -> der -> lazy += raiz -> lazy;
		}
		raiz -> lazy = 0;
	}
}

void update(int ini,int fin,pnode &raiz,int inir,int finr,int v){
	
	int mitad = (ini+fin)/2;
	ifcreate(ini,fin,raiz);
	push(ini,fin,raiz);

	if(finr < ini || fin < inir) return ;
	if(ini >= inir && fin <= finr) {
		(raiz -> valor).first += v;
		if(ini != fin){
			ifcreate(ini,mitad,raiz->izq);
			ifcreate(mitad+1,fin,raiz->der);
			raiz -> izq -> lazy += v;
			raiz -> der -> lazy += v;
		}
		return;
	}
	
	update(ini,mitad,raiz->izq,inir,finr,v);
	update(mitad+1,fin,raiz->der,inir,finr,v);
	raiz -> valor = max(raiz->izq->valor,raiz->der->valor);

}

int maxR(int R,int &f,int &c, int L, vector<punto> &puntos,int &N){

	vector<cuad> eventos;

	for(int i = 0; i < N; i++){
		int fi = puntos[i].f-R+1;
		int ci = puntos[i].c-R+1;
		fi = max(1,fi);
		ci = max(1,ci);
		eventos.push_back(cuad(fi,ci,puntos[i].c,1));
		eventos.push_back(cuad(puntos[i].f,ci,puntos[i].c,-1));
	}

	int ret = 0;
	pnode ST = NULL;
	Par p;
	sort(eventos.begin(),eventos.end());
	for(int i = 0; i< eventos.size();i++){
		cuad &act = eventos[i];
		update(1,L,ST,act.ini,act.fin,act.tipo);
		p = ST -> valor;
		if(p.first > ret){
			ret = p.first;
			f = act.f;
			c = p.second;
		}
	}

	return ret;
}

int main(){

	int N,K;
	int L = 0;
	optimizar_io(0);

	cin >> N >> K; 
	vector<punto>puntos(N);
	for(int i = 0 ; i < N ; i ++){
		cin >> puntos[i].f >> puntos[i].c;
		if(puntos[i].f > L) L = puntos[i].f;
		if(puntos[i].c > L) L = puntos[i].c;
	}

	int f,c;
	int ini = 1 , fin = L;
	int mitad = (ini+fin)/2;
	while(ini != fin){
		if(maxR(mitad,f,c,L,puntos,N) >= K) fin = mitad;
		else ini = mitad+1;
		mitad = (ini+fin)/2;
	}
	maxR(mitad,f,c,L,puntos,N);
	
	cout << ini-1 << '\n' << f << ' ' << c << '\n';

	return 0;
}