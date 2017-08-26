#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<int, int> pii;
typedef pair<pii, int> ter;
typedef pair<lli, lli> pli;

const int MAXN = 1004;
const int MAXL = 12009;
const lli MOD = 1000000007LL;
const lli MOD2 = 1000000013LL;
const lli BAS = 67LL;
const lli BAS2 = 23LL;

char arr[MAXN][MAXN];
lli currS[MAXL], PB[MAXL], Hash[MAXL], Nhash[MAXN];
lli PB2[MAXL], Hash2[MAXL], Nhash2[MAXN];
int limCurrS, parent[MAXN];
map<pli, vector<int>> msets;

inline int toVal(char c) { 
	if ((c >= 'A') && (c <= 'Z')) return (c - 'A');
	if ((c >= 'a') && (c <= 'z')) return (c -'a') + 26;
	if ((c >= '0') && (c <= '9')) return (c - '0') + 52;
	if (c == '+') return 62;
	return 63;
}

inline void fillCurrS(int idx) {
	limCurrS = strlen(arr[idx]) * 6;
	int lim = strlen(arr[idx]);
	int j = 0;
	for (int i = 0; i < lim; ++i) {
		int val = toVal(arr[idx][i]);
		for (int j = 0; j < 6; ++j) {
			int id = (i + 1) * 6 - 1 - j; 
			currS[id] = currS[id + limCurrS] = (val & 1) + 1LL;
			val >>= 1;
		}
	}
	limCurrS <<= 1;
}

inline void getHash() { 
	for (int i = 0; i < limCurrS; ++i) Hash[i + 1] = (((Hash[i] * BAS) % MOD) + currS[i]) % MOD; 
	for (int i = 0; i < limCurrS; ++i) Hash2[i + 1] = (((Hash2[i] * BAS2) % MOD2) + currS[i]) % MOD2; 
}

inline pli getSubHash(int I, int J) { 
	return pli((Hash[J] - ((Hash[I - 1] * PB[J - I + 1]) % MOD) + MOD) % MOD, (Hash2[J] - ((Hash2[I - 1] * PB2[J - I + 1]) % MOD2) + MOD2) % MOD2); 
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	PB[0] = PB2[0] = 1LL; 
	for (int i = 1; i < MAXL; ++i) {
		PB[i] = (PB[i - 1] * BAS) % MOD;
		PB2[i] = (PB2[i - 1] * BAS2) % MOD2;
	}
	int N, nc = 1;
	while (scanf("%d", &N)) {
		if (!N) break;
		for (int i = 0; i < N; ++i) {
			//cin >> arr[i];
			scanf("%s", arr[i]);
			//printf("%s\n", arr[i]);
			parent[i] = i;
			fillCurrS(i);
			getHash();
			int lim = limCurrS >> 1;
			pli prev = getSubHash(1, lim);
			Nhash[i] = prev.first;
			Nhash2[i] = prev.second;
			for (int j = 2; j <= lim; ++j) {
				pli res = getSubHash(j, lim + j - 1);
				if (res < prev) {
					Nhash[i] = res.first;
					Nhash2[i] = res.second;
					prev = res;
				}
			}
			msets[{Nhash[i], Nhash2[i]}].push_back(i + 1);
		}
		vector<vector<int>> lsts;
		for (auto it = msets.begin(); it != msets.end(); ++it) lsts.push_back(it->second);	
		sort(lsts.begin(), lsts.end(), [&](const vector<int>& a, const vector<int>& b){
			if (a.size() != b.size()) return a.size() < b.size();
			return a[0] < b[0];
		});
		printf("Case %d:\n", nc++);
		for (int i = 0; i < lsts.size(); ++i) {
			int cnt = 0;
			for (auto it : lsts[i]) {
				if (cnt++) printf(" "); //cout << ' ';
				printf("%d", it); //cout << it;
			}
			puts(""); //cout << '\n';
		}
		msets.clear();
	}
	return 0;
}