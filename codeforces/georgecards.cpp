#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000009;

typedef long long lli;

int pos[MAXN];
bitset<MAXN> alive;
int BIT[MAXN];

void Update(int idx) {
	while (idx < MAXN) {
		BIT[idx]++;
		idx += (idx & (-idx));
	}
}

lli Query(int idx) {
	lli res = 0;
	while (idx) {
		res += BIT[idx];
		idx -= (idx & (-idx));
	}
	return res;
}

lli Range(int I, int J) {
	return (Query(J) - Query(I - 1));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K;
	
	cin >> N >> K;
	
	for (int i = 1; i <= N; ++i) {
		int ax;
		cin >> ax;
		pos[ax] = i;
	}
	
	for (int i = 0; i < K; ++i) {
		int tmp;
		cin >> tmp;
		alive[tmp] = 1;
	}

	lli ans = 0;
	
	set<int> posal;
	
	for (int i = 1; i <= N; ++i) {
		if (alive[i]) {
			posal.insert(pos[i]);
		} else {
			int rans, lans; // que tanto izq o fder te puedes extender
			set<int>::iterator it = posal.upper_bound(pos[i]);
			
			if (it != posal.end())
				rans = (*it) - 1;
			else 
				rans = N;
			
			if (it != posal.begin()) {
				it--;
				lans = (*it) + 1;
			} else 
				lans = 1;
			
			lli posans = (rans - lans  + 1);
			posans -= Range(lans, rans); //restar los muertos en ese rango
			ans += posans;
			Update(pos[i]);
		}
	}
	
	cout << ans << '\n';
	return 0;
}