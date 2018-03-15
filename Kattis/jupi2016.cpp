#include <bits/stdc++.h>
using namespace std;

typedef int Flujo;
typedef int Costo;
typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef vector<Flujo> Flujo1D;
typedef vector<Flujo1D> Flujo2D;
const Flujo FINF = 1000000009;
const Flujo FMAX = 1e8;

struct GrafoFlujo{
    struct AristaFlujo {
        int dst; AristaFlujo* residual;
        Flujo cap, flujo; 
        AristaFlujo(int d, Flujo f, Flujo c) : dst(d), flujo(f), cap(c) {}
        void AumentarFlujo(Flujo f) {
            residual->flujo -= f;
            this->flujo += f;            
        } 
    };
    int n; Lista dist , iter;
    vector< vector<AristaFlujo*> > aristas;
    GrafoFlujo(int N) : n(N), aristas(N), dist(N), iter(N) {}
    ~GrafoFlujo() {
        for(int i = 0; i < n; ++i)
            for (int j = 0; j < aristas[i].size(); ++j)
                delete aristas[i][j];
    }
    
    void AgregarArista(int u, int v, Flujo c, Costo p = 0) {
        AristaFlujo* uv = new AristaFlujo(v, 0, c);
        AristaFlujo* vu = new AristaFlujo(u, c, c);
        uv->residual = vu, vu->residual = uv;        
        aristas[u].push_back(uv);
        aristas[v].push_back(vu);
    }

    Flujo FlujoBloqueante(int u, int t, Flujo f) {        
        if (u == t) return f;
        for (int &i = iter[u] ; i < aristas[u].size(); ++i) {            
            AristaFlujo* v = aristas[u][i];
            if (v -> cap - v -> flujo > 0 && dist[u] + 1 == dist[v->dst]) {
                Flujo fv = FlujoBloqueante(v->dst, t, min(f, v->cap - v->flujo));
                if(fv > 0 ){
                    v->AumentarFlujo(fv);
                    return fv;
                }
            }
        }
        return 0;
    }
    
    Flujo Dinic(int s, int t) {
        Flujo flujo_maximo = dist[t] = 0;
        while (dist[t] < INT_MAX) {
            fill(dist.begin(), dist.end(), INT_MAX);
            queue<int> q; q.push(s); dist[s] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < aristas[u].size(); ++i) {
                
                    AristaFlujo* v = aristas[u][i];
                    if (dist[v->dst] < INT_MAX) continue;
                    if (v->flujo == v->cap) continue;
                    dist[v->dst] = dist[u] + 1;
                    q.push(v->dst);
                    
                }
            }
            if (dist[t] < INT_MAX){
                Flujo fluido;
                iter.assign(n, 0);
                while((fluido = FlujoBloqueante(s, t, FINF)) != 0){                    
                    
                    flujo_maximo += fluido;
                }
            }
        }
        return flujo_maximo;
    }
    
    
};

int toQ[MAXN];
Flujo capQ[MAXN], sumQ[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N, Q, S;

	cin >> N >> Q >> S;

	Flujo sum = 0;

	for (int i = 1; i <= S; ++i) cin >> toQ[i];
	for (int i = 1; i <= Q; ++i) cin >> capQ[i];

	int cnt = 1;
	int lim = N * Q;
	int FD = lim * 2;
	int limT = FD + N + 1;
	
	GrafoFlujo myF(limT + 1);

	//cout << limT << " LT\n";

	
	for (int j = 1; j <= N; ++j) {
		for (int i = 1; i <= Q; ++i) {
			//AGREGAR ARISTA DE nodo a nodo2 con capQ
			int nodo = (Q * (j - 1)) + i;
			int nodo2 = nodo + lim;
			myF.AgregarArista(nodo, nodo2, capQ[i]);
			if (j != 1) {
				int pnodo = (Q * (j - 2)) + i;
				int pnodo2 = pnodo + lim;
				myF.AgregarArista(pnodo2, nodo, capQ[i]);
				//cout << "PREVN: " << prevn << " -- " << INF << "-->" << "NODO: " << nodo << '\n';
			}
			//cout << "NODO: " << nodo << " -- " << capQ[i] << "-->" << "NODO2: " << nodo2 << '\n'; 
		}
	}

	for (int i = 1; i <= N; ++i) {
		Flujo diCap;
		cin >> diCap;
		for (int j = 1; j <= S; ++j) {
			Flujo siCap;
			cin >> siCap;
			sum += siCap;
			int nodo = (Q * (i - 1)) + toQ[j];
			int nodo2 = nodo + lim;
			//AGREGAR ARISTA DE S A nodo con siCap
			myF.AgregarArista(0, nodo, siCap);
			//cout << "S: " << 0 << "-- " << sumQ[j] << "-->" << "NODO: " << nodo << '\n';
			//AGREGAR ARISTA DE nodo2 A ? con INF	
		}
		for (int j = 1; j <= Q; ++j) {
			int nodo = (Q * (i - 1)) + j;
			int nodo2 = nodo + lim;
			myF.AgregarArista(nodo2, FD + i, diCap);
			//cout << "NODO2: " << nodo2 << " -- " << INF << "-->" << "FDi: " << (FD + i) << '\n';
		}
		//AGREGAR ARISTA DE ? A T con diCap
		myF.AgregarArista(FD + i, limT, diCap);
		//cout << "NODO2: " << (FD + i) << " -- " << diCap << "-->" << "T: " << (limT) << '\n';
	}

	Flujo res = myF.EdmondsKarp(0, limT);

	//cout << res << ' ' << sum << '\n';
	if (sum == res) cout << "possible\n";
	else cout << "impossible\n";

	return 0;
}