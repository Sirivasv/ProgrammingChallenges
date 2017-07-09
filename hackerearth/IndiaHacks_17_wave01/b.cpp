#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<int, int> pii;

int N;
string s;
vector<pii> couples;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> s;

	lli ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			for (int k = j + 1; k < N; ++k)
				for (int l = k + 1; l < N; ++l) 
					if ((s[i] == s[k]) && (s[j] == s[l])) ans++;


	cout << ans << '\n';

	return 0;
}
