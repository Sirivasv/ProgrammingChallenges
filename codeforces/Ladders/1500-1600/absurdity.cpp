#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const int MAXN = 200009;

int N, K;
lli arr[MAXN], barr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	lli sum = 0;
	for (int i = 0; i < K; ++i)
		sum += arr[i];
	barr[0] = sum;
	
	int le = 0;
	for (int i = K; i < N; ++i) {
		sum -= arr[le];
		sum += arr[i];
		le++;
		barr[le] = sum;
	}
	
	lli mats = -1LL, ansq = -1LL;
	int matsa, matsb, matsq;
	
	int lim = N - (2 * K);
	
	for (int i = lim; i >= 0; --i) {
		lli posa = barr[i];
		
		if (barr[i + K] >= ansq) {
			ansq = barr[i + K];
			matsq = i + K + 1;
		}
		
		posa += ansq;
		if (posa >= mats) {
			mats = posa;
			matsa = i + 1;
			matsb = matsq;
		}
		
	}
	cout << matsa << ' ' << matsb << '\n';
	return 0;
}