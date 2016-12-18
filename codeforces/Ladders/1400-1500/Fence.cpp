#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;

int arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	int sum = 0;
	for (int i = 0; i < K; ++i)
		sum += arr[i];
	
	int mint = sum;
	int id = 1;
	int i = 0, j = K;
	
	while (j < N) {
		sum -= arr[i];
		i++;
		sum += arr[j];
		if (sum < mint) {
			mint = sum;
			id = (i + 1);
		}
		j++;
	}
	cout << id << '\n';
	return 0;
}