#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ter;

const int MAXN = 10001;

vector<int> arr[MAXN];


bool Can(int S) {
	priority_queue< pii, vector<pii>, greater<pii> > pq;
	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			pq.push(pii(arr[i][j], S));
		}
		
		if (!pq.empty()) {
			pii tp = pq.top();
			while (tp.first <= i) {
				if (tp.second)
					return false;
				pq.pop();
				if (pq.empty())
					break;
				tp = pq.top();
			}
		}
		
		if (!pq.empty()) {
			pii tp = pq.top();
			pq.pop();
			tp.second--;
			
			if (tp.second)
				pq.push(tp);
		}
	}
	if (pq.empty())
		return true;
	return false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int I, J;
		cin >> I >> J;
		arr[I].push_back(J);
	}
	
	int ini = 1, fin = 10000, ans = 0;
	
	while (ini <= fin) {
		int m = (ini + fin) >> 1;
		if (Can(m)) {
			ans = m;
			ini = m + 1;
		} else
			fin = m - 1;
	}
	
	cout << (ans * N) << '\n';
	
	return 0;
}