#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
int arr[MAXN];

int main() {
	for (int i = 1; i <= 20; ++i) {
		for (int j = i; j <= 20; ++j) {
			for (int k = i; k <= j; ++k)
				arr[k]++;
		}
	}
	for (int i = 1; i <= 20; ++i)
		cout << arr[i]  << ' ' << (arr[i] - arr[i - 1])<< '\n';
	return 0;
} 