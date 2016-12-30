#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200009;
const lli INF = 10000000000LL;
const lli MINF = -10000000000LL;

lli dif[MAXN];
int DIV[MAXN], N;

lli GetNewRating(lli xi) {
	for(int i = 0; i < N; ++i) xi += dif[i];
	return xi;
}

int Check(lli xi) {
	for (int i = 0; i < N; ++i) {
		int curd = ((xi >= 1900LL)?(1):(2));
		if (curd < DIV[i]) return -1;
		if (curd > DIV[i]) return 1;
		xi += dif[i];
	}
	return 0;
}

lli BusBin() {
	lli ini = MINF, fin = INF, ans = MINF;
	while (ini <= fin) {
		
		lli m = (ini + fin) / 2LL;
		
		int val = Check(m);
		
		if (val == 0) {
			ans = m;
			ini = m + 1;
		}
		
		if (val == 1)
			ini = m + 1;
		
		if (val == -1)
			fin = m - 1;	
		
	}
	
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N; 
	
	for (int i = 0; i < N; ++i) cin >> dif[i] >> DIV[i];
	
	lli ans = BusBin();
	
	if (ans == MINF) {
		cout << "Impossible\n";
		return 0;
	}
	
	if (ans == INF) {
		cout << "Infinity\n";
		return 0;
	}
	
	cout << GetNewRating(ans) << '\n';
	return 0;
}