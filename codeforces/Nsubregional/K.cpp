#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;

const int MAXN = 109;

ter arr[MAXN], cf;

map<ter, int> ID;

bool IsE(int xi) {
	int an = (cf.first.first - 1) - arr[xi].first.first;
	if (cf.first.second > arr[xi].first.second) an++;
	else if ((cf.first.second == arr[xi].first.second) && (cf.second >= arr[xi].second)) an++;
	return (an >= 18);
}

int main() {
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> cf.second >> cf.first.second >> cf.first.first;
	
	int N; 
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].second >> arr[i].first.second >> arr[i].first.first;
		ID[arr[i]] = i + 1;
	}
	
	sort(arr, arr + N);
	
	int idans = -1;
	
	for (int i = N - 1; i >= 0; --i)
		if (IsE(i)) {
			idans = ID[arr[i]];
			break;
		}
	
	cout << idans << '\n';
	
	return 0;
}