#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 1000004;

lli arr[MAXN];

bool bad(pii rect2, pii rect1, pii nr) {
	return ((nr.second - rect2.second) * (rect2.first - rect1.first)) < ((rect1.second - rect2.second) * (rect2.first - nr.first));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, T;
	cin >> T;
	while (T--) {
		cin >> N;
		lli a, b, c;
		cin >> a >> b >> c;
		for(int i = 1; i <= N; ++i) cin >> arr[i];
		vector<pii> rects;
		rects.push_back(pii(0, 0));
		lli DP = 0, sum = 0;
		int LP = 0;
		for (int i = 1; i <= N; ++i) {
			sum += arr[i];
			for (; LP < (rects.size() - 1); ++LP) {
				lli val1 = (rects[LP].first * sum) + rects[LP].second + ((a * sum * sum) + (b * sum) + c);
				lli val2 = (rects[LP + 1].first * sum) + rects[LP + 1].second + ((a * sum * sum) + (b * sum) + c);
				if (!(val1 <= val2)) break;
			}
			
			DP = (rects[LP].first * sum) + rects[LP].second + ((a * sum * sum) + (b * sum) + c);
			if (i <= N) {
				pii nr = pii(-2LL * a * sum, DP + (a * sum * sum) - (b * sum));
				while (((rects.size() - LP) >= 2) && (bad(rects[rects.size() - 2], rects[rects.size() - 1], nr))) rects.pop_back();
				rects.push_back(nr);
			}
		}
		
		cout << DP << '\n';
	}
	return 0;
}