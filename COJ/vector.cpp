#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int A[MAXN], B[MAXN];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) 
		cin >> A[i];
	for (int i = 0; i < N; ++i) 
		cin >> B[i];
	sort(A, A + N);
	sort(B, B + N);
	int sum = 0;
	for (int i = 0; i < N; ++i) 
		sum += A[i] * B[N - i - 1];
	cout << sum << '\n';
	return 0;
}