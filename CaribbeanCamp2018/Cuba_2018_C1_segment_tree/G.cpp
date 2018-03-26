#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;	

struct trio{

	int x , y , z;

	trio() : x(0) , y(0) , z(0) {}

};

trio operator+(trio a,trio b){

	trio ret;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;

	return ret;

}

struct node{

	trio val ;
	node *izq,*der;

	node(): izq(NULL),der(NULL),val() {}

};
typedef node* pnode;

void construye(int ini,int fin,pnode &raiz, string &str){
	raiz = new node();
	if(ini == fin){
		if(str[ini] == '(') (raiz -> val).x = 1;
		else (raiz -> val).z = 1;
		return;
	}

	int mitad = (ini+fin)/2;
	construye(ini,mitad,raiz->izq,str);
	construye(mitad+1,fin,raiz->der,str);

	trio &t = raiz -> val;
	trio &izq = raiz -> izq -> val;
	trio &der = raiz -> der -> val;
	
	t.y = izq.y + der.y;
	int c = min(izq.x,der.z);
	t.y += c;
	t.x = izq.x-c + der.x;
	t.z = der.z-c + izq.z;

}

trio query(int ini,int fin, pnode raiz, int inir,int finr){

	if(fin < inir || finr < ini ) {
		trio ret;
		return ret;
	}
	if(ini >= inir && fin <= finr) return raiz -> val;
	int mitad = (ini+fin)/2;
	trio t;
	trio izq = query(ini,mitad,raiz -> izq, inir,finr);
	trio der = query(mitad+1,fin,raiz -> der, inir,finr);

	t.y = izq.y + der.y;
	int c = min(izq.x,der.z);
	t.y += c;
	t.x = izq.x-c + der.x;
	t.z = der.z-c + izq.z;

	return t;
	
}

int main(){
	
	int N,Q;
	int a,b;
	string S;
	optimizar_io(0);

	cin >> S ;
	N = S.size();
	cin >> Q;
	pnode raiz = NULL;
	construye(0,N-1,raiz,S);

	for(int i = 0 ; i < Q; i++){

		cin >> a >> b ;
		a-- , b --;
		cout << query(0,N-1,raiz,a,b).y*2 << '\n';

	}

	return 0;

}
