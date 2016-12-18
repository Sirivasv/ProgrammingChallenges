#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pll;

int N, mint;
map<pll, int> color;
int mc[5];

double Dist(pll a, pll b) {
	return sqrt(((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second))); 
}

void BFS(pll o) {
	mc[0] = 1;
	mc[1] = 0;
	color[o] = 0;
	queue<pll> Q;
	Q.push(o);
	pll aux;
	while (!Q.empty()) {
		pll p = Q.front();
		Q.pop();
		long long x_ = p.first;
		long long y_ = p.second;
		for (long long ny = y_ - 5; ny <= y_ + 5; ++ny)
			for (long long nx = x_ - 5; nx <= x_ + 5; ++nx) {
				aux.first = nx;
				aux.second = ny;
				if ((Dist(aux, p) <= 5.0) && (color.count(aux)) && (color[aux] == -1)) {
					color[aux] = (color[p] + 1) % 2;
					mc[color[aux]]++;
					Q.push(aux);
				}
			}
	}
	mint += min(mc[0], mc[1]);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio();
	while (cin >> N) {
		color.clear();
		mint = 0;
		pll aux;
		for (int i = 0; i < N; ++i) {
			cin >> aux.first >> aux.second;
			color[aux] = -1; 
		}
		for (map<pll, int>::iterator p = color.begin(); p != color.end(); ++p)
			if (p->second == -1)
				BFS(p->first);
		cout << mint << '\n';
	}
	return 0;
}