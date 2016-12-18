#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const long double ERROR = (1e-25);

bool Igual(long double a, long double b) {
	return fabs(a - b) < ERROR;
}

struct Double {
	long double d;
	bool operator<(const Double& cmp) const{
		if (Igual(d, cmp.d)) return false;
		return d < cmp.d;
	}
};

lli GCD(lli a, lli b) {
	if (!b) 
		return a;
	return GCD(b, a % b);
}

const int MAXN = 30;

lli arr[MAXN], PGCD[MAXN][MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, lim, ans = 0;
	cin >> N;
	
	lli xi;
	cin >> xi;
	
	set<lli> numb;
	
	set<Double> numbs;
	
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		if (arr[i] == 1LL) {
			long double sum = log((long double)xi);
			Double DD;
			DD.d = sum;
			numbs.insert(DD);
		}
		else
			numb.insert(arr[i]);
	}
	
	int cnt = 0;
	
	for (set<lli>::iterator it = numb.begin(); it != numb.end(); it++) {
		arr[cnt++] = (*it);
	}
	
	N = cnt;
	lim = (1 << N);
	
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			PGCD[i][j + 1] = GCD(arr[i], arr[j]);
			//cout << i << ' ' << j << ' ' << PGCD[i][j + 1] << '\n';
			PGCD[j][i + 1] = PGCD[i][j + 1];
		}
		
		PGCD[i][0] = GCD(arr[i], xi);
		//cout << "** " << i << ' ' << xi << ' ' << PGCD[i][0] << '\n';
	}
	
	for (int i = 1; i < lim; ++i) {
		int ok = 1;
		for (int j = 0; (1 << j) <= i; ++j) {
			if ((1 << j) & i) {			
				for (int k = j + 1; (1 << k) <= i; ++k) {
					if (j == k)
						continue;
					if (((1 << j) & (i)) && ((1 << k) & (i)))
						if ((PGCD[j][k + 1] != 1LL) || ((PGCD[j][0] != 1LL)) || ((PGCD[k][0] != 1LL)))
							ok = 0;
				}
				if (PGCD[j][0] != 1LL)
					ok = 0;
			}
		}
		if (ok) {
			
			long double sum = log((long double)xi);
			
			for (int j = 0; (1 << j) <= i; ++j) {
				if ((1 << j) & i) {			
					sum += log((long double)arr[j]);
				}
			}
			
			//cout << sum << '\n';
			
			//cout << i << '\n';
			Double DD;
			DD.d = sum;
			//cout << DD.d << '\n';
			numbs.insert(DD);
		}
	}
	cout << (numbs.size()) << '\n';
	return 0;
}