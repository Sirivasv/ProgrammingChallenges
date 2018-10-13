#include <bits/stdc++.h>
using namespace std;

typedef int Dato;
typedef pair<Dato, Dato> pii;
typedef pair<pii, Dato> ter;

const Dato MAXN = 100009;
const Dato MINF = -10009;

pii candies[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	Dato N;
	cin >> N;
	for (Dato i = 0; i < N; ++i) { 
		Dato pi, ti;
		cin >> pi >> ti; 
		candies[i].first = pi + ti; // to reach the point by pos we have time ti
		candies[i].second = ti - pi; // to reach the point by time we have dist pi
	}

	// order by pos
	sort(candies, candies + N);
	vector<int> chains;
	vector<ter> output;
	for (Dato i = 0; i < N; ++i) {
		Dato reachByHPos = candies[i].first, reachByTime = -candies[i].second;
		int chainID = lower_bound(chains.begin(), chains.end(), reachByTime) - chains.begin();
		if (chainID == chains.size()) {
			chains.push_back(reachByTime);
		} else {
			chains[chainID] = reachByTime;
		}
		Dato originalPos = (reachByHPos + reachByTime) / 2;
		Dato originalTime = (reachByHPos - reachByTime) / 2;
		output.push_back(ter(pii(originalPos, originalTime), chainID + 1));
	}

	cout << chains.size() << '\n';
	for (int i = 0; i < N; i++) {
		cout << output[i].first.first << ' ' << output[i].first.second << ' ' << output[i].second << '\n';
	}

	return 0;
} 