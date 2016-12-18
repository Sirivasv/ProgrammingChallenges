#include <bits/stdc++.h>
using namespace std;

struct trie {
	int palabra;
	map<char, int> enlace;
	trie() {
		palabra = 0;
	}
	~trie() {
		enlace.clear();
	}
};

struct tries {
	int disponible;
	vector<trie> tree;
	vector<int> Dist;
	tries() { }
	tries(int tamano) {
		disponible = 1;
		tree.resize(tamano);
		Dist.resize(tamano);
	}
	void clear(int n) {
		tree.clear();
		Dist.clear();
		disponible = 1;
		tree.resize(n);
		Dist.resize(n);
	}
	void add(const string& palabra, int ID) {
		int nodo = 0;
		int tam = palabra.size();
		for (int i = 0; i < tam; ++i) {
			if (tree[nodo].enlace.count(palabra[i])) 
				nodo = tree[nodo].enlace[palabra[i]];
			else {
				tree[nodo].enlace[palabra[i]] = disponible;
				nodo = disponible;
				disponible++;
			}
		}
		tree[nodo].palabra++;
	}
	void InOrder(int nodo) {
		for (map<char, int>::iterator it = tree[nodo].enlace.begin(); it != tree[nodo].enlace.end(); it++) {
			cout << it->first << '\n';
			InOrder(it->second);
		}
	}
	void tam(int s) {
		tree.resize(s);
	}
	int sum(){
		int res = 0;
		Dist[0] = 1;
		queue<int> Q;
		Q.push(0);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			int val = (((tree[u].enlace.size() > 1) && u) || (tree[u].palabra > 0));
			//cout << val << '\n';
			for (map<char, int>::iterator it = tree[u].enlace.begin(); it != tree[u].enlace.end(); it++) {
				//cout << it->first << '\n';
				
				Dist[it->second] = Dist[u] + val;
				
				res += (tree[it->second].palabra) * Dist[it->second];
				
				/*if (tree[it->second].palabra) {
					cout << it->second << ' ' << Dist[it->second] << '\n';
					//Dist[it->second]++;
				}*/
				Q.push(it->second);
			}
		}
		return res;
	}
};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	tries TR;
	while (cin >> N) {
		string s;
		TR.clear(N * 83);
		//TR.tam(N * 90);
		for (int i = 0; i < N; ++i) {
			cin >> s;
			TR.add(s, 1);
		}
		//TR.InOrder(0);
		
		cout << fixed << setprecision(2) << (((double)TR.sum()) / ((double)N)) << '\n';;
		//cout << "*******\n";
	}
	return 0;
}