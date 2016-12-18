#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> ranges;
bitset<1000> vis;
int N;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		int op, I, J;
		cin >> op >> I >> J;
		if (op == 1)
			ranges.push_back(pii(I, J));
		else {
			cout << ((Can(--I, --J))?("YES\n"):("NO\n"));
		}
	}
	return 0;
}