#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

string mat[MAXN];
char marked[MAXN];
vector<int> ansPath;
int N;

void Process(int u) {

	for (int i = 0; i < N; ++i) {
		if ((mat[u][i] == '1') && (!marked[i])) {
			marked[i] = 1;
			Process(i);
		}
	}

	ansPath.push_back(u);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i) { cin >> mat[i]; }
	
	marked[0] = 1;
	Process(0);

	if (ansPath.size() == N) {
		for (int i = 0; i < N; ++i) {
			if (i) cout << ' ';
			cout << ansPath[i];
		}
		cout << '\n';
	} else {
		cout << "impossible\n";
	}
	return 0;
}