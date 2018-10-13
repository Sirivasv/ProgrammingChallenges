#include <bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	int N;
	cin >> N; 

	map<int, int> pushed;
	vector<int> dirtyPushes;

	for (int i = 0; i < N; ++i) { 
		int dayPush;
		cin >> dayPush;
		pushed[dayPush] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= 365; ++i) {

		if (pushed[i]) {
			dirtyPushes.push_back(0);
		}

		int needsClean = 0;
		int currentDirtiness = 0;
		for (int j = 0; j < dirtyPushes.size(); ++j) {
			dirtyPushes[j]++;
			currentDirtiness += dirtyPushes[j];
			if (currentDirtiness >= 20) {
				needsClean = 1;
			}
		}

		if (needsClean) {
			dirtyPushes = vector<int>();
			ans++;
		}

	}

	if (dirtyPushes.size()) ans++;

	cout << ans << '\n';

	return 0;
}