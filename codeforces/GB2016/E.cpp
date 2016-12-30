#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;

string s;

int acumsx[MAXN], acums[MAXN];
int nesttu[MAXN], nestz[MAXN], nesto[MAXN];

int Range(int l, int r) {
	if (l > r) return -1;
	if (!(acums[r] - acums[l - 1])) return -1;
	return (acumsx[r] - acumsx[l - 1]);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N, Q;
	cin >> N >> Q;
	
	cin >> s;
	
	int lim = s.size();

	for (int i = 1; i <= lim; ++i) {
		acumsx[i] += acumsx[i - 1];
		acumsx[i] += (s[i - 1] == '6');
		acums[i] += acums[i - 1];
		acums[i] += (s[i - 1] == '7');
	}
	
	nesto[lim + 1] = nesttu [lim + 1] = nestz[lim + 1] = MAXN;
	
	for (int i = lim; i >= 1; --i) {
		nesto[i] = nesto[i + 1]; 
		nesttu[i] = nesttu[i + 1]; 
		nestz[i] = nestz[i + 1]; 
		if (s[i - 1] == '1') nesto[i] = i;
		if (s[i - 1] == '2') nesttu[i] = i;
		if (s[i - 1] == '0') nestz[i] = i;
	}
	
	for (int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		l = nesttu[l];
		if (l == MAXN) {
			cout << "-1\n";
			continue;
		}
		l = nestz[l];
		if (l == MAXN) {
			cout << "-1\n";
			continue;
		}
		l = nesto[l];
		if (l == MAXN) {
			cout << "-1\n";
			continue;
		}
		cout << Range(l, r) << '\n';
	}
	
	return 0;
}