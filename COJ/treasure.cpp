#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ter; 

const int MAXN = 505;

int filas, columnas;
int mapa[MAXN][MAXN];
int visitado[MAXN][MAXN];
int movI[] = { -1, 1, 0, 0 };
int movJ[] = { 0, 0, 1, -1 };

bool valido( int xi, int yi ){
	if((xi < filas) && (xi >= 0) && (yi < columnas) && (yi >= 0)) return true;
	return false;
}

int bfs(int t){
	visitado[0][0] = 1;
	queue<ter> Q;
	Q.push(ter(t, pii(0, 0)));
	
	while (!Q.empty()) {
		int xi = Q.front().second.first;
		int yi = Q.front().second.second;
		int t  = Q.front().first;
		Q.pop();
		
		if (t >= mapa[xi][yi])
			continue;
		
		if((xi == (filas - 1)) && (yi == (columnas - 1))) 
			return 1;
		
		for( int k = 0; k < 4; k++ ) {
			if(valido(xi + movI[k], yi + movJ[k]) && (visitado[xi + movI[k]][yi + movJ[k]] == -1)){
				visitado[xi + movI[k]][yi + movJ[k]] = 1;
				Q.push(ter(t + 1, pii(xi + movI[k], yi + movJ[k])));
			}
		}
	}
	return 0;
}

void limpia(){
	for( int i = 0; i < MAXN; i++ )
		for( int j = 0; j < MAXN; j++ )
			visitado[i][j] = -1;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> filas >> columnas;
	for( int i = 0; i < filas; i++ )
		for( int j = 0; j < columnas; j++ )
			cin >> mapa[i][j];

	int ini = 0, fin = 1000000, mid, res = -1;

	while( ini <= fin ){
		limpia();
		mid = ( ini + fin ) / 2;
		
		int busca = bfs(mid);
		//cout << mid << ' ' <<busca << endl;

		if( busca == 1){
			res = mid;
			ini = mid + 1;
		}
		else{
			fin = mid - 1;
		}
	}
	cout << res << '\n';

	return 0;
}
