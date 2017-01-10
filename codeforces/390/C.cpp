#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 300009;

pii arr[MAXN];

map<pii, int> ID;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%lld%lld", &arr[i].first, &arr[i].second);
	sort(arr, arr + N);
	
	set<pii> fines, inicios, lon;
	
	lli mats = 0, matsl, matsr;

	
	for (int i = 0; i < N; ++i) {
		vector<int> erased;
		for (auto it = fines.begin(); it != fines.end(); it++) {
			if (it->first >= arr[i].first) break;
			erased.push_back(it->second);
		}
		for (int i = 0; i < erased.size(); ++i) {
			fines.erase(pii(arr[erased[i]].second, erased[i]));
			inicios.erase(pii(arr[erased[i]].first, erased[i]));
			lon.erase(pii(arr[erased[i]].second - arr[erased[i]].first + 1LL, erased[i]));
		}
		fines.insert(pii(arr[i].second, i));
		inicios.insert(pii(arr[i].first, i));
		lon.insert(pii(arr[i].second - arr[i].first + 1, i));
		while (fines.size() > K) {
			lli le = inicios.rbegin()->first;
			lli ri = fines.begin()->first;
			if ((ri - le + 1LL) > mats) {
				mats = ri - le + 1LL;
				matsl = inicios.rbegin()->second;
				matsr = fines.begin()->second;
			}
			int id = lon.begin()->second;
			lon.erase(lon.begin()); 
			inicios.erase(pii(arr[id].first, id)); 
			fines.erase(pii(arr[id].second, id)); 
		}
		if (fines.size() == K) {
			lli le = inicios.rbegin()->first;
			lli ri = fines.begin()->first;
			if ((ri - le + 1LL) > mats) {
				mats = ri - le + 1LL;
				matsl = inicios.rbegin()->second;
				matsr = fines.begin()->second;
			}
		}
	}
	
	printf("%lld\n", mats);
	if (mats == 0) {
		for (int i = 1; i <= K; ++i) {
			if (i > 1) printf(" ");
			printf("%d", i);
		}
	} else {
		fines.clear(); 
		inicios.clear();

		for (int i = 0; i < N; ++i) {
		vector<int> erased;
		for (auto it = fines.begin(); it != fines.end(); it++) {
			if (it->first >= arr[i].first) break;
			erased.push_back(it->second);
		}
		for (int i = 0; i < erased.size(); ++i) {
			fines.erase(pii(arr[erased[i]].second, erased[i]));
			inicios.erase(pii(arr[erased[i]].first, erased[i]));
			lon.erase(pii(arr[erased[i]].second - arr[erased[i]].first + 1LL, erased[i]));
		}
		fines.insert(pii(arr[i].second, i));
		inicios.insert(pii(arr[i].first, i));
		lon.insert(pii(arr[i].second - arr[i].first + 1LL, i));
		while (fines.size() > K) {
			lli le = inicios.rbegin()->first;
				lli ri = fines.begin()->first;
				if ((ri - le + 1LL) == mats) {
					int cnt = 0;
					for (auto it : inicios) {
						if (cnt) printf(" ");
						printf("%lld", it.second + 1);
						cnt++;
					}
					break;
				}
			int id = lon.begin()->second;
			lon.erase(lon.begin()); 
			inicios.erase(pii(arr[id].first, id)); 
			fines.erase(pii(arr[id].second, id)); 
		}
			if (fines.size() == K) {
				lli le = inicios.rbegin()->first;
				lli ri = fines.begin()->first;
				if ((ri - le + 1LL) == mats) {
					int cnt = 0;
					for (auto it : inicios) {
						if (cnt) printf(" ");
						printf("%lld", it.second + 1);
						cnt++;
					}
					break;
				}
			}
		}
	}
	
	return 0;
}