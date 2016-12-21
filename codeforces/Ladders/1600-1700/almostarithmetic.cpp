#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000; 

int N, arr[MAXN], dp[MAXN][MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N;
	
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	map<int, int> mp;
	int id = 0;
	for (int i = 0; i < N; ++i)
		if (mp.find(arr[i]) == mp.end())
			mp[arr[i]] = id++;
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			dp[i][j] = 1;
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < i; ++j)
			dp[i][mp[arr[j]]] = max(dp[i][mp[arr[j]]], 1 + dp[j][mp[arr[i]]]);
	
	int mats = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			mats = max(mats, dp[i][j]);
	cout << mats << '\n';
	
	return 0;
}