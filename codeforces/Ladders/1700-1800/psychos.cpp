#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arr[MAXN];
int td[MAXN];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);

	int ans = 0;
	stack<int> S;
	S.push(0);
	td[0] = -1;
	for (int i = 1; i < N; ++i) {
		int tp = S.top();
		while (arr[tp] < arr[i]) {
			td[i] = max(td[i], td[tp] + 1);
			S.pop();
			if (S.empty()) break;
			tp = S.top();
		}
		if (S.empty()) td[i] = -1;
		S.push(i);
		ans = max(ans, td[i] + 1);
	}

	printf("%d\n", ans);
	
	return 0;
}