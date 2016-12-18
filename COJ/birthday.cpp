#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 100009;

pii Lazy[MAXN * 4];
lli ST[MAXN * 4], N, Q, P;

lli Query(lli L, lli R, lli n = 1LL, lli l = 1LL, lli r = N) {
	
	lli ls = (n << 1), rs = ls + 1LL, m = (l + r) >> 1;
	
	if (Lazy[n].first) {

		lli EI = Lazy[n].first, CE = r - l + 1LL;
		ST[n] = (ST[n] + (EI * CE) + ((((CE) * (CE - 1LL)) / 2LL) * (Lazy[n].second))) % P;
		
		//cout << "UPrD: " << l << ' ' << r << ' ' << ST[n] << '\n';

		if (l != r) {
			Lazy[ls].first += Lazy[n].first;
			Lazy[rs].first += (Lazy[n].first + ((Lazy[n].second) * ((m + 1LL) - l)));
			Lazy[ls].second += Lazy[n].second;
			Lazy[rs].second += Lazy[n].second;
		}
		
		Lazy[n].first = Lazy[n].second = 0;

	}
	if ((l > R) || (r < L))
		return 0;
	
	//cout << "Q: " << l << ' ' << r << ' ' << ST[n] << '\n';
	
	if ((l >= L) && (r <= R)) 
		return ST[n];
	
	return (Query(L, R, ls, l, m) + Query(L, R, rs, m + 1LL, r)) % P;
}

void Update(lli L, lli R, lli n = 1LL, lli l = 1LL, lli r = N) {
	//cout << "UPtD: " << l<< ' ' << r<< ' ' << ST[n] << '\n';
	lli ls = (n << 1), rs = ls + 1LL, m = (l + r) >> 1;
	
	if (Lazy[n].first) {
		
		lli EI = Lazy[n].first, CE = r - l + 1LL;
		ST[n] = (ST[n] + (EI * CE) + (((CE * (CE - 1LL)) / 2) * (Lazy[n].second))) % P;
		
		//cout << "UPrD: " << l << ' ' << r << ' ' << ST[n] << '\n';
		if (l != r) {
			Lazy[ls].first += Lazy[n].first;
			Lazy[rs].first += (Lazy[n].first + ((Lazy[n].second) * ((m + 1LL) - l)));
			Lazy[ls].second += Lazy[n].second;
			Lazy[rs].second += Lazy[n].second;
		}
		
		Lazy[n].first = Lazy[n].second = 0;
	}

	if ((l > R) || (r < L))
		return;
	
	//cout << "UPD: " << l << ' ' << r << ' ' << ST[n] << '\n';
	if ((l >= L) && (r <= R)) {
		lli MR, ML;
		MR = min(R, r);
		ML = max(L, l);
		lli CE = (MR - ML + 1LL), EI = (l - L + 1LL); 
		ST[n] = (ST[n] + (EI * CE) + ((CE * (CE - 1LL)) / 2LL)) % P;
		//cout << "UPiD: " << l << ' ' << r << ' ' << ST[n] << '\n';
        if (l != r) {
			Lazy[ls].first += EI;
			Lazy[rs].first += (EI + ((m + 1LL) - l));
			Lazy[ls].second++;
			Lazy[rs].second++;
		}
		
		return;
	}
	Update(L, R, ls, l, m);
	Update(L, R, rs, m + 1LL, r);
	ST[n] = (ST[ls] + ST[rs]) % P;
	//cout << "UPkD: " << l << ' ' << r << ' ' << ST[n] << '\n';
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> Q >> P;

	for (int i = 0; i < Q; ++i) {
		int op, I, J;
		cin >> op >> I >> J;
		if (!op)
			Update(I, J);
		else
			cout << Query(I, J) << '\n';
	}
	return 0;
}