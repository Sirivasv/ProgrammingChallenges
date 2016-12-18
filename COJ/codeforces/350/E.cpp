#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500009;
int nleft[MAXN], nright[MAXN], pare[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, m, p;
	int fvp = 0;
	string s, op;
	
	cin >> n >> m >> p;
	cin >> s;
	cin >> op;
	p--;
	
	for (int i = 1; i < n; ++i) nleft[i] = i - 1;
	for (int i = 0; i < n; ++i) nright[i] = i + 1;
	nright[n - 1] = -1;
	
	stack<int> st;
	int tp;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') st.push(i);
		else {
			tp = st.top();
			st.pop();
			pare[tp] = i;
			pare[i] = tp;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		if (op[i] == 'L') p = nleft[p];
		else if (op[i] == 'R') p = nright[p];
		else {
			if (s[p] == '(') { 
				int aux = nright[pare[p]];
				nright[nleft[p]] = aux;
				if (p == fvp) fvp = aux;
				if (aux != -1) {
					nleft[nright[pare[p]]] = nleft[p];
					p = aux;
				} else p = nleft[p];
				
			} else {
				int aux = nright[p];
				nright[nleft[pare[p]]] = aux;
				if (pare[p] == fvp) fvp = nright[p];
				if (aux != -1) {
					nleft[nright[p]] = nleft[pare[p]];
					p = aux;
				} else p = nleft[pare[p]];
			}
		}
	}
	
	while (fvp != -1) {
		cout << s[fvp];
		fvp = nright[fvp];
	}
	cout << '\n';
	return 0;
}