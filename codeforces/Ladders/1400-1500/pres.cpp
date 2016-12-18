#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;

int arr[MAXN];

int main() {
	int N; 
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		arr[a] = i + 1;
	}
	for (int i = 1; i <= N; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
	return 0;
}