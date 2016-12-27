#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > Reg;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int prev = 2000000000;
	for (int i = 0; i < N; ++i) {
		int nw;
		cin >> nw;
		if (nw <= prev) Reg.push_back(vector<int>());
		Reg[Reg.size() - 1].push_back(nw);
		prev = nw;
	}
	int ans = 1;
	for (int i = 1; i < Reg.size(); ++i) {
		if ((Reg[i - 1].size() == 1) || (Reg[i].size() == 1)) {
			ans = max(ans, (int)(Reg[i].size() + Reg[i - 1].size()));
			continue;
		}
		int ival = Reg[i - 1][Reg[i - 1].size() - 1];
		int nival = Reg[i - 1][Reg[i - 1].size() - 2] + 1;
		int rval = Reg[i][0];
		int nrval = Reg[i][1] - 1;
		if ((nival < rval) || (nrval > ival))
			ans = max(ans, (int)(Reg[i].size() + Reg[i - 1].size()));
		else
			ans = max(ans, max((int)(Reg[i].size() + 1), (int)(Reg[i - 1].size() + 1)));
	}
	if (Reg.size() == 1)
		ans = Reg[0].size();
	cout << ans << '\n';
	return 0;
}