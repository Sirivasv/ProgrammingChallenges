#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<int, int> pii;
const int MAXN = 100009;

int N;
string s;
stack<pii> ST;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') ST.push(pii(i, 1));
		else {
			if ((!ST.empty()) && (ST.top().second == 1)) ST.pop();
			else ST.push(pii(i, 0));
		}
	}
	
	stack<pii> Ci;
	lli ans = ST.size();
	lli offset = 0;

	while (!ST.empty()) {
		pii tp = ST.top();
		ST.pop();
		if (tp.second == 1) Ci.push(tp);
		else {
			if ((Ci.top().first - tp.first) == 1) offset = 1;
			break;
		}
	}

	cout << ans - offset << '\n';

	return 0;
}
