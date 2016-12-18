#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<int, pii> ter;

#define X first
#define Y second.first
#define Z second.second

const int MAXN = 6009;

vpii grafo[MAXN];
ter Case[MAXN];
bitset<MAXN> vis;
int TopoSort[MAXN], idtopo;
int Dist[MAXN];
int valz[MAXN];
int tmp[5], aux[5];

void Limpia(int n) {
	int lim = (n * 6);
	for (int i = 0; i < lim; ++i) {
		grafo[i].clear();
		Dist[i] = 0;
	}
	idtopo = 0;
}

void BuildGraph(int n) {
	for (int i = 0; i < n; ++i) {
		tmp[0] = Case[i].X;
		tmp[1] = Case[i].Y;
		tmp[2] = Case[i].Z;
		sort(tmp, tmp + 3);
		int u = i * 6;
		do {
			int x_ = tmp[0];
			int y_ = tmp[1];
			int z_ = tmp[2];
			for (int j = 0; j < n; ++j) {
				aux[0] = Case[j].X;
				aux[1] = Case[j].Y;
				aux[2] = Case[j].Z;
				sort(aux, aux + 3);
				int v = j * 6;
				do {
					int _x = aux[0];
					int _y = aux[1];
					int _z = aux[2];
					if ((_x < x_) && (_y < y_)) {
						grafo[u].push_back(pii(v, _z));
						//cout << u << ' ' << v << ' ' << _z << '\n';
					}
					v++;
				} while (next_permutation(aux, aux + 3));
			}
			valz[u] = z_;
			//cout << u << ' ' << z_ << "--\n";
			u++;
		} while (next_permutation(tmp, tmp + 3));
	}
}


void TopoDFS(int u) {
	vis[u] = 1;
	for (int i = 0; i < (int)grafo[u].size(); ++i) {
		int v = grafo[u][i].first;
		if (!vis[v])
			TopoDFS(v);
	}
	TopoSort[idtopo++] = u;
}

void GetTopoSort(int n){
	int lim = (n * 6);
	for (int i = 0; i < lim; ++i)
		if (!vis[i])
			TopoDFS(i);
	//reverse(TopoSort, TopoSort + idtopo);
}

int GetMaxD(int n) {
	vis.reset();
	GetTopoSort(n);
	int mats = 0;
	for (int i = 0; i < idtopo; ++i) {
		int u = TopoSort[i];
		int res = 0;
		for (int j = 0; j < (int)grafo[u].size(); ++j) {
			int v = grafo[u][j].first;
			res = max(res, Dist[v]);
		}
		Dist[u] = res + valz[u];
		mats = max(mats, Dist[u]);
	}
	return mats;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0); //cout.tie(0);
	int T, N, H;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		cin >> H >> N;
		Limpia(N);
		for (int i = 0; i < N; ++i)
			cin >> Case[i].X >> Case[i].Y >> Case[i].Z;
		BuildGraph(N);
		cout << "Case #" << nc << ": ";
		int gd = GetMaxD(N);
		if (H > gd)
			cout << "no\n";
		else
			cout << "yes\n";
	}
	return 0;
}
