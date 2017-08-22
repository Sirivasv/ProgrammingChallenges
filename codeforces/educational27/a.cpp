#include <bits/stdc++.h>
using namespace std;

const int MAXN = 209;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	N <<= 1;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < (N >> 1); ++i) 
		for (int j = (N >> 1); j < N; ++j) 
			if (arr[i] >= arr[j]) {
				cout << "NO\n";
				return 0;
			}
	cout << "YES\n"; 
	return 0;
}