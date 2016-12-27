#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;

int arr[MAXN];
bitset<MAXN> isp;
vector<pii> modu, modos;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int ok = 0, sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		sum += arr[i];
		ok |= (arr[i] == 0);
	}
	
	if (!ok) {
		cout << "-1\n";
		return 0;
	}
	
	sort(arr, arr + N, greater<int>());
	
	for (int i = 0; i < N; ++i)
		if ((arr[i] % 3) == 1)
			modu.push_back(pii(arr[i], i));
		else if ((arr[i] % 3) == 2)
			modos.push_back(pii(arr[i], i));
	
	if ((sum % 3) == 1) {
		if (modu.size()) {
			isp[modu[modu.size() - 1].second] = 1;
			sum -= modu[modu.size() - 1].first;
		} else {
			isp[modos[modos.size() - 1].second] = 1;
			isp[modos[modos.size() - 2].second] = 1;
			sum -= modos[modos.size() - 1].first;
			sum -= modos[modos.size() - 2].first;
		}
	}
	
	if ((sum % 3) == 2) {
		if (modos.size()) {
			isp[modos[modos.size() - 1].second] = 1;
			sum -= modos[modos.size() - 1].first;
		} else {
			isp[modu[modu.size() - 1].second] = 1;
			isp[modu[modu.size() - 2].second] = 1;
			sum -= modu[modu.size() - 1].first;
			sum -= modu[modu.size() - 2].first;
		}
	}
	
	if (sum == 0)
		cout << "0\n";
	else {
		for (int i = 0; i < N; ++i)
			if (!isp[i])
				cout << arr[i];
		cout << '\n';
	}
	
	return 0;
}