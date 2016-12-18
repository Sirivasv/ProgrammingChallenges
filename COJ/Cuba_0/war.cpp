#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
int qa[MAXN], na[MAXN];
int main() {
	int aux;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> qa[i];
	for (int i = 0; i < N; ++i) cin >> na[i];
	sort(qa, qa + N);
	sort(na, na + N);
	int j = 0;
	for (int i = 0; i < N; ++i)
		if (na[i] > qa[j]) ++j;
	cout << j << '\n';
	return 0;
}