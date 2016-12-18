#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int arr[MAXN];
vector<int> ali[MAXN];

int main() {
	for (int i = 0; i < MAXN; ++i)
		arr[i] = -1;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		int a;
		cin >> a;
		arr[a] = i;
		ali[i].push_back(a);
	}
	int lim = N * K;
	int cnt = 0;
	for (int i = 1; i <= lim; ++i) {
		if (arr[i] == -1) {
			arr[i] = cnt;
			ali[cnt].push_back(i);
			cnt++;
			cnt %= K;
		}
	}
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < ali[i].size(); ++j) {
			if (j)
				cout << ' ';
			cout << ali[i][j];
		}
		cout << '\n';
	}
	return 0;
}