#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXC = 105;
typedef unsigned long long ull;
int T, N;
ull sport[MAXN], music[MAXN];
char gender[MAXN];
int height[MAXN];
string axm, axs;
vector<int> grafo[MAXN], l, r;
ull HB[MAXC], B = 71;

ull F(char c){
    return c - 'a' + 1;
}

void CB(){
    HB[0] = 1; HB[1] = B;
    for (int i = 2; i < MAXC; ++i) 
        HB[i] = HB[i - 1] * B;
	return;
}

ull MakeHash(string s){
    ull hash = 0;
    for (int i = 1; i <= s.size(); ++i) 
        hash = hash * B + F(s[i - 1]); 
    return hash;
}

int pareja[MAXN];
bool visitado[MAXN];

int CaminoIncremental(int u) {
    visitado[u] = true;
    for (int i = 0; i < grafo[u].size(); ++i) {
        int v = grafo[u][i];
        if (pareja[v] == -1) 
            return pareja[v] = u;
        if (visitado[pareja[v]]) continue;
        if (CaminoIncremental(
            pareja[v]) != -1) return pareja[v] = u;
    }
    return -1;
}

int MEB() {
    int n = l.size() + r.size();
    fill(pareja, pareja + n, -1);
    for (int i = 0; i < l.size(); ++i) {
        fill(visitado, visitado + n, false);
        CaminoIncremental(l[i]);
    }
    int parejas = 0;
    for (int i = 0; i < r.size(); ++i)
        if (pareja[r[i]] != -1) parejas++;
    return parejas;
}

int Avs(int x) {
	return x > 0 ? x : -x;
}

bool Match(int a, int b) {
	return ((gender[a] != gender[b]) && (!(Avs(height[a] - height[b]) > 40)) && (music[a] == music[b]) && (sport[a] != sport[b]));
}

void Limpia() {
	for (int i = 0; i < N; ++i)
		grafo[i].clear();
	l.clear();
	r.clear();
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	CB();
	cin >> T;
	while (T--) {
		cin >> N;
		Limpia();
		for (int i = 0; i < N; ++i) {
			cin >> height[i] >> gender[i] >> axm >> axs;
			music[i] = MakeHash(axm);
			sport[i] = MakeHash(axs);
			if (gender[i] == 'M')
				r.push_back(i);
			else
				l.push_back(i);
		}
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j) 
				if (Match(i, j)) {
					grafo[i].push_back(j);
					grafo[j].push_back(i);
				}
		cout << N - MEB() << '\n'; 
	}
	return 0;
}