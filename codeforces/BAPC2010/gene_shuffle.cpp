#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arrA[MAXN];
int arrB[MAXN];
int posB[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> arrA[i];
		}
		for (int i = 1; i <= N; ++i) {
			cin >> arrB[i];
			posB[arrB[i]] = i;
		}
		int start = 1, end = 1, curmpos = 0, manyr = 0;
		for (int i = 1; i <= N; ++i) {
			end = i;
			curmpos = max(posB[arrA[i]], curmpos);
			if (i == curmpos) {
				if (manyr)
					cout << ' ';
				cout << start << '-' << end;
				start = i + 1;
				manyr++;
			}
		}
		cout << '\n';
	}
	return 0;
}