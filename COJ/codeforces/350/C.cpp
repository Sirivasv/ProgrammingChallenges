#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200009;
int movie[MAXN];
map<int, int> many;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, m, aux;
	int maxp = -1, maxap = -1, id;
	int a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		many[aux]++;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) cin >> movie[i];
	for (int i = 0; i < m; ++i) {
		cin >> aux;
		if (many.count(movie[i])) a = many[movie[i]];
		else a = 0;
		if (many.count(aux)) b = many[aux];
		else b = 0;
		if (a > maxp) {
			maxp = a;
			maxap = b;
			id = i + 1;
		} else if (a == maxp) {
			if (b > maxap) {
				maxap = b;
				id = i + 1;
			}
		}		
	}
	cout << id << '\n';
	return 0;
}