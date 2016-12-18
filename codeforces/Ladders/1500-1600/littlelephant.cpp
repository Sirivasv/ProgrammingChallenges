#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;

int arr[MAXN], sarr[MAXN];
map<int, pii> ranges; 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		sarr[i] = arr[i];
	}
	sort(sarr + 1, sarr + N + 1);
	int preval = -1;
	for (int i = 1; i <= N; ++i) {
		if (sarr[i] != preval) {
			ranges[preval].second = i - 1;
			ranges[sarr[i]].first = i;
			preval = sarr[i];
		}
	}
	ranges[preval].second = N;
	int isB = 0, isL = 0, posL, posB;
	for (int i = 1; i <= N; ++i) {
		if ((ranges[arr[i]].first <= i) && (i <= ranges[arr[i]].second))
			continue;
		if (i < ranges[arr[i]].first) {
			isL++;
			posL = i;
		} else {
			isB++;
			posB = i;
		}
	}
	
	if ((((isL == 1) && (isB == 1)) && ((ranges[arr[posL]].first <= posB) && (posB <= ranges[arr[posL]].second)) && ((ranges[arr[posB]].first <= posL) && (posL <= ranges[arr[posB]].second))) || ((isL + isB) == 0))
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}