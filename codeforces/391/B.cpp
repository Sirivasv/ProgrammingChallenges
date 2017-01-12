#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009; 
const int MAXC = 109;

int N, xi, pc[MAXN];

vector<int> Criba(int n) {
	int raiz = sqrt(n); vector<int> criba(n + 1);
	for (int i = 4; i <= n; i += 2) criba[i] = 2;
	for (int i = 3; i <= raiz; i += 2) if (!criba[i])
		for (int j = i * i; j <= n; j += i)
			if (!criba[j]) criba[j] = i;
	return criba;
}
int main() {
	scanf("%d", &N);
	
	vector<int> Cb = Criba(MAXN);
	
	int mats = 1;
	
	for (int i = 0; i < N; ++i) {
		scanf("%d", &xi);
		if (xi == 1) continue;
		//cout << "++\n";
		set<int> ps;
		while (xi != 1) {
			
			if (Cb[xi] == 0) {
				if (ps.find(xi) == ps.end())
					pc[xi]++;
				break;
			}
			if (ps.find(Cb[xi]) == ps.end()) {
				ps.insert(Cb[xi]);
				pc[Cb[xi]]++;
			}
			xi /= Cb[xi];
		}
	}
	for (int i = 2; i < MAXN; ++i)
		mats = max(pc[i], mats);
	
	printf("%d\n", mats);
	return 0;
}
