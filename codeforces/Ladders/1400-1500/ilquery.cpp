#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int lim = s.size() - 1;
	
	for (int i = 0; i < lim; ++i)
		if (s[i] == s[i + 1])
			arr[i + 1] = 1;
	
	lim++;
	for (int i = 1; i <= lim; ++i)
		arr[i] += arr[i - 1];
	
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int I, J;
		cin >> I >> J;
		J--;
		cout << (arr[J] - arr[I - 1]) << '\n';
	}
	return 0;
}