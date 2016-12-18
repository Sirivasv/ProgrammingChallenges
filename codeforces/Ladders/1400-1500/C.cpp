#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pli;

const int MAXN = 300000;

pli spelli[MAXN], spellj[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli n, m, k, x, s;
	
	cin >> n >> m >> k;
	cin >> x >> s;
	
	for (int i = 0; i < m; ++i)
		cin >> spelli[i].second;
	for (int i = 0; i < m; ++i)
		cin >> spelli[i].first;
	
	for (int i = 0; i < k; ++i)
		cin >> spellj[i].second;
	for (int i = 0; i < k; ++i)
		cin >> spellj[i].first;
	
	sort(spelli, spelli + m);
	
	//first mana points;
	
	lli minT = (1LL << 62);
	lli cost = x;
	lli mcost = 0;
	int j = k - 1;
	for (int i = 0; i <= m; ++i) {
		lli timeT = cost * n;
		while ((j >= 0) && ((spellj[j].first + mcost) > s))
			j--;
		
		if (j >= 0)
			timeT -= (spellj[j].second * cost);
	  
		minT = min(timeT, minT);
	  
		cost = spelli[i].second;	
		mcost = spelli[i].first;
		if (mcost > s)
			break;
	}
	
	cout << minT << '\n';
	
	return 0;
}