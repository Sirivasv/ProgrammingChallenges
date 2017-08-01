#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 8009;
const int INF = (1 << 30);
const int MAXQ = 500009;

map<pii, int> ans;
set<pii> squeries;
pii arr[MAXQ];
int A[MAXN];
int SUM[MAXN];
map<pii, pii> SUMOFOC;
set<int> numbas;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0); 
	int N, Q;
	cin >> N >> Q;
	
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		numbas.insert(A[i]);
	}

	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b;
		if (b < a) swap(a, b);
		pii Qi = pii(a, b);
		squeries.insert(Qi);
		arr[i] = Qi;
	}
	
	pii cv = pii(A[1], 0);
	SUMOFOC[cv].first = INF;
	SUMOFOC[cv].second = INF;
	SUM[A[1]]++;
	cv = pii(A[1], 1);
	SUMOFOC[cv].first = 1;
	SUMOFOC[cv].second = INF;

	for (int i = 2; i <= N; ++i) {
		cv = pii(A[i], 0);
		if (SUMOFOC.count(cv)) continue;
		SUMOFOC[cv].first = 1;
		SUMOFOC[cv].second = INF;
	} 

	for (int i = 2; i <= N; ++i) {
		cv = pii(A[i], SUM[A[i]]);
		SUMOFOC[cv].second = i - 1;
		
		for (auto j = numbas.begin(); j != numbas.end(); ++j) {
			
			int a, b;
			a = min(A[i], (*j));
			b = max(A[i], (*j));
			pii ci = pii(a, SUM[A[i]]);
			pii cj = pii(b, SUM[A[i]]);
			if ((SUMOFOC.count(ci)) && (SUMOFOC.count(cj))) {
				int limle = max(SUMOFOC[ci].first, SUMOFOC[cj].first);
				int limri = min(SUMOFOC[cj].second, SUMOFOC[cj].second);
				if (!(limle <= limri)) continue;
				ans[pii(a, b)] += limri - limle + 1;
				//cout << a << ' ' << b << '\n';
			}

		}

		SUM[A[i]]++;
		cv = pii(A[i], SUM[A[i]]);
		SUMOFOC[cv].first = i;
	}

	for (auto i = numbas.begin(); i != numbas.end(); ++i) {
		for (auto j = i; j != numbas.end(); ++j) {
			
			int a, b;
			a = min((*i), (*j));
			b = max((*i), (*j));
			cout << a << ' ' << b << '\n';

			pii ci = pii(a, SUM[(*i)]);
			pii cj = pii(b, SUM[(*i)]);
			if ((SUMOFOC.count(ci)) && (SUMOFOC.count(cj))) {
				int limle = max(SUMOFOC[ci].first, SUMOFOC[cj].first);
				int limri = min(SUMOFOC[cj].second, SUMOFOC[cj].second);
				if (!(limle <= limri)) continue;
				if (limri == INF) limri = N;
				ans[pii(a, b)] += limri - limle + 1;
				
			}

		}
	}

	//cout << ans[pii(1, 2)] << '\n';

	for (auto it = ans.begin(); it != ans.end(); ++it) 
		ans[it->first] = ((it->second) * (it->second + 1)) >> 1;
	
	for (int i = 0; i < Q; ++i) {
		if(arr[i].first == arr[i].second) {
			cout << ((N * (N + 1)) >> 1) << '\n';
			continue;
		}
		if (ans.count(arr[i]))
			cout << ans[arr[i]] << '\n';
		else {
			pii res = pii(arr[i].first, 0);
			if (SUMOFOC.count(res)) {
				int len = SUMOFOC[res].second - SUMOFOC[res].first + 1;
				cout << ((len * (len + 1)) >> 1) << '\n'; 
			} else {
				res = pii(arr[i].second, 0);
				if (SUMOFOC.count(res)) {
					int len = SUMOFOC[res].second - SUMOFOC[res].first + 1;
					cout << ((len * (len + 1)) >> 1) << '\n';
				} else {
					cout << ((N * (N + 1)) >> 1) << '\n';
				}
			}
		}
	}
	
	return 0;
}