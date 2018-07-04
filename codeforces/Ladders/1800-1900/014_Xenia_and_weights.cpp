#include <bits/stdc++.h>
using namespace std;

int arr[20];
string s;
int M;

vector<int> vir;

int DFS(int sum, int prev_w, int step) {
	if (step == M) return 1;
	if (sum == 0) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '1') {
				if (DFS(i + 1, i, step + 1)) {
					vir.push_back(i + 1);
					return 1;
				}
			}
		}
	}
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') { 
			if (i == prev_w) continue;
			if (sum > 0) {
				if ((sum - (i + 1)) >= 0) continue;
				if (DFS((sum - (i + 1)), i, step + 1)) {
					vir.push_back(i + 1);
					return 1;
				}
			} else {
				if ((sum + (i + 1)) <= 0) continue;
				if (DFS((sum + (i + 1)), i, step + 1)) {
					vir.push_back(i + 1);
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	cin >> s >> M;

	if (DFS(0, 0, 0)) {
		cout << "YES\n";
		reverse(vir.begin(), vir.end());
		for (int i = 0; i < vir.size(); ++i) {
			if (i) cout << ' ';
			cout << vir[i];
		}
		cout << '\n';
		return 0;
	}
	cout << "NO\n";

	return 0;
}