#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500009;

char pos[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	if (M == 2) {
		int ac = 0, bc = 0;
		for (int i = 0; i < N; ++i) 
			if ((i % 2) != (s[i] - 'A'))
				ac++;
		for (int i = 0; i < N; ++i) 
			if (((i + 1) % 2) != (s[i] - 'A'))
				bc++;
		if (ac < bc) {
			cout << ac << '\n';
			for (int i = 0; i < N; ++i)
				cout << ((char)((i % 2) + 'A'));
		} else {
			cout << bc << '\n';
			for (int i = 0; i < N; ++i)
				cout << ((char)(((i + 1) % 2) + 'A'));
		}
		cout << '\n';
		return 0;
	}
	int lim = N - 1;
	pos[lim] = s[lim];
	int mint = 0;
	for (int i = 0; i < lim; ++i) {
		pos[i] = s[i];
		if (s[i] == s[i + 1]) {
			pos[i + 1] = 0;
			i++;
			mint++;
		}
	}
	cout << mint << '\n';
	for (int i = 0; i < N; ++i) {
		if (pos[i] != 0)
			continue;
		char l = -1;
		if (i >= 1)
			l = pos[i - 1] - 'A';
		char r = -1;
		if ((i + 1) < N)
			r = pos[i + 1] - 'A';
		
		for (int k = 0; k < M; ++k)
			if ((k != l) && (k != r))
				pos[i] = k + 'A'; 
	}
	for (int i = 0; i < N; ++i)
		cout << pos[i];
	cout << '\n';
	return 0;
}