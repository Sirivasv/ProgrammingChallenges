#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

lli arr[MAXN];

vector<lli> difs;

lli Abs(lli x) { return((x < 0LL)?(-x):(x)); }

int main() {
	lli N;
	cin >> N;
	lli sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort(arr, arr + N);
	
	lli sumdif = 0, tmpacum = 0;
	
	for (lli i = 0; i < N; ++i) {
		sumdif += (arr[i] * i) - tmpacum;
		tmpacum += arr[i];
	}
	lli A = sum + (2LL * sumdif);
	lli B = N;
	lli GCD = __gcd(A, B);
	cout << (A / GCD) << ' ' << (B / GCD) << '\n';
	return 0;
}