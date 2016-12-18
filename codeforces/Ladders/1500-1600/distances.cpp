#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, L, xi, yi;
	cin >> N >> L >> xi >> yi;
	map<int, int> marks;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		marks[arr[i]]++;
	}
	//put first mark
	int posi;
	vector<int> vals;
	int found = 0;
	for (auto it: marks)
		if (marks.count(it.first - xi) || marks.count(it.first + xi))
			found = 1;
		
	if (!found) {
		for (auto it: marks) {
			if ((it.first - xi) < 0) continue;
			marks[it.first - xi] = 2;
			posi = it.first - xi;
		}
		for (int i = 0; i < N; ++i) {
			if ((arr[i] + xi) > L)
				break;
			marks[arr[i] + xi] = 2;
		}
		vals.push_back(posi);
	}
	found = 0;
	for (auto it: marks) {
		if (it.first == 0)
			continue;
		if ((marks.count(it.first - yi)) && (marks[it.first] == 1) && (marks[it.first - yi] == 1))
			found = 1;
	}
	if (!found) {
		for (auto it: marks) {
			if (it.first == 0)
				continue;
			if (marks.count(it.first - yi) && (((marks[it.first - yi] == 1) && (marks[it.first] == 2)) || ((marks[it.first] == 1) && (marks[it.first - yi] == 2)))) {
				cout << "1\n";
				if ((marks[it.first - yi] == 1) && (marks[it.first] == 2))
					cout << it.first << '\n';
				else
					cout << it.first - yi << '\n';
				return 0;
			}
		}
		for (auto it: marks) {
			if((it.first - yi) < 0) continue;
			if ((marks[it.first] == 2) && (it.first != posi)) continue;
			vals.push_back(it.first - yi);
			break;
		}
	} 
	cout << vals.size() << '\n';
	for (auto it : vals) {
		if (it != vals[0])
			cout << ' ';
		cout << it;
	}
	if (vals.size())
		cout << '\n';
	return 0;
}