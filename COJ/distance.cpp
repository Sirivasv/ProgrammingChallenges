#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<ld, ld> pdd;
typedef pair<int, pdd> ter;

const int MAXN = 100009;

ter P[MAXN];
int N;

ld Pot(ld x, int ex) {
	ld res = 1.0;
	for (int i = 0; i < ex; ++i)
		res *= x;
	return res;
}

ld CalcDist(ld v, int tp) {
	ld res = 0;
	for (int i = 0; i < N; ++i) {
		if (tp == 1)
			res += Pot(fabs(v - P[i].second.first), P[i].first);
		else
			res += Pot(fabs(v - P[i].second.second), P[i].first);
	}
	return res;
}

ld Ternaria(int tp) {
	
	ld ini = -(1LL << 40), fin = (-ini);
	
	for (int i = 0; i < 100; ++i) {
		
		ld m1 = ((2.0 * ini) + fin) / 3.0;
		ld m2 = ((2.0 * fin) + ini) / 3.0;
		
		ld a1 = CalcDist(m1, tp);
		ld a2 = CalcDist(m2, tp);
		
		if (a1 < a2)
			fin = m2;
		else
			ini = m1;
		
	}
	
	return CalcDist((ini + fin) / 2.0, tp);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	cout << fixed << setprecision(3);
	while (T--) {
		
		cin >> N;
		
		for (int i = 0; i < N; ++i)
			cin >> P[i].second.first >> P[i].second.second >> P[i].first;
		
		cout << (Ternaria(1) + Ternaria(2)) << '\n';
		
	}
	return 0;
}