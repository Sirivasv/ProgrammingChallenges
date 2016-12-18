#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

lli arr[MAXN];
int N;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	
	if (N == 1) cout << "-1\n";
	else if (N == 2) {
		lli dif = arr[1] - arr[0];
		set<lli> vi;
		vi.insert(arr[0] - dif);
		if (!(dif & 1))
			vi.insert(arr[0] + (dif / 2));
		vi.insert(arr[1] + dif);
		cout << vi.size() << '\n';
		for (auto it: vi) {
			if (it != (*vi.begin()))
				cout << ' ';
			cout << it;
		}
	} else {
		map<lli, int> difs;
		int id = -1;
		lli matsd = -1;
		for (int i = 0; i < (N - 1); ++i) {
			difs[arr[i + 1] - arr[i]]++;
			if ((arr[i + 1] - arr[i]) > matsd) {
				matsd = arr[i + 1] - arr[i];
				id = i;
			}
		}
		if (difs.size() == 1) {
			lli dif = arr[1] - arr[0];
			set<lli> vi;
			vi.insert(arr[0] - dif);
			vi.insert(arr[N - 1] + dif);
			cout << vi.size() << '\n';
			for (auto it: vi) {
				if (it != (*vi.begin()))
					cout << ' ';
				cout << it;
			}
		} else if (difs.size() == 2) {
			auto it = difs.begin();
			it++;
			if ((it->second == 1) && (!(it->first & 1)) && ((it->first / 2) == (difs.begin()->first)))
				cout << "1\n" << (arr[id] + it->first / 2) << '\n';
			else
				cout << "0\n";
		} else
			cout << "0\n";
	}
	
	return 0;
}