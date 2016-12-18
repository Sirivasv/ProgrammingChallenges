#include <bits/stdc++.h>
using namespace std;

int arr[25];

int main() {
	int N;
	cin >> N;
	while(N--) {
		int tmp;
		cin >> tmp;
		for (int i = 0; i < 20; ++i)
			cin >> arr[i];
		vector<int> lst;
		lst.push_back(arr[0]);
		int cnt = 0;
		for (int i = 1; i < 20; ++i) {
			vector<int>::iterator it = upper_bound(lst.begin(), lst.end(), arr[i]);
			if (it != lst.end()) {
				//cout << *it << '\n';
				//cout << "__\n";
				cnt += (lst.size() + 1) - ((it - lst.begin()) + 1);
				//cout << "++" << ((it - lst.begin()) + 1) << '\n';
				lst.insert(it, arr[i]);
			} else
				lst.push_back(arr[i]);
			//cout << "**\n";
			//for (int j = 0; j < lst.size(); ++j)
				//cout << lst[j] << '\n';
		}
		cout << tmp << ' ' << cnt << '\n';
	}
	return 0;
}