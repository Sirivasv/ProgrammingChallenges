#include <bits/stdc++.h>
using namespace std;

typedef int Dato;
typedef pair<Dato, Dato> pii;

const Dato MAXN = 100009;
const Dato MINF = -10009;

pii dolls[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	vector<pii> chains;

	Dato T;

	cin >> T;

	for (Dato nc = 0; nc < T; ++nc) {
		Dato N;
		cin >> N;
		chains.clear();
		for (Dato i = 0; i < N; ++i) { cin >> dolls[i].first >> dolls[i].second; dolls[i].second = -dolls[i].second; }
		sort(dolls, dolls + N);
		multiset<pii> SH;
		vector<pii> smw;
		int ans = N;
		for (Dato i = 0; i < N; ++i) {
			pii nord = pii(dolls[i].second, dolls[i].first);
			if (SH.upper_bound(nord) != SH.end()) {
				SH.erase(SH.upper_bound(nord));
				ans--;
			}
			smw.push_back(nord);
			if (((i + 1) < N) && (dolls[i].first < dolls[i + 1].first)) {
				SH.insert(smw.begin(), smw.end());
				smw.clear();
			}
		}
		cout << ans << '\n';
	}

	return 0;
}