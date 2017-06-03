#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;
#define px second
#define py first
const int MAXN = 100009;
const long long INF = 2000000000000000009LL;
pll puntos[MAXN];
int N;
int CompX(pll a, pll b) { return a.px < b.px; }

//namekus
long long K;

long long Dista(pll a, pll b) {
	return (((a.px - b.px) * (a.px - b.px))  + ((a.py - b.py) * (a.py - b.py)));
}

vector<pll> ClosestPair(int np) {
	vector<pll> ans(2);
	sort(puntos, puntos + np, CompX);
	int lind = 0;
	long long mindist = INF;
	set<pll> candidates; 
	candidates.insert(puntos[0]);
	for (int i = 1; i < np; ++i) {
		
		while ((lind < i) && (puntos[i].px - puntos[lind].px > mindist)) 
			candidates.erase(puntos[lind++]);
		
		for (set<pll>::iterator it = candidates.lower_bound(pll(puntos[i].py - mindist, puntos[i].px - mindist)); 
			 it != candidates.end() && puntos[i].py + mindist >= it->py; ++it) {
			 long long dis = Dista(puntos[i], (*it));
			 if (dis < mindist) {
				mindist = dis;
				ans[0] = puntos[i];
				ans[1] = (*it);
			 }
		}
		candidates.insert(puntos[i]);
	}
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	int tam, cx, cnt = 0;
	for (int i = 0; i < N; ++i) {
		cin >> tam;
		for (int j = 0; j < tam; ++j) {
			cin >> cx;
			puntos[cnt++] = pll((long long)i, (long long)cx);
		}
	}
	vector<pll> res = ClosestPair(cnt);
	long long answ = (Dista(res[0], res[1]) * K);
	cout << answ << '\n';
	return 0;
}