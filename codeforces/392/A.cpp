#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 100009;

lli arr[MAXN];
int N;

int main() {
	
	//cin.tie(0); ios_base::sync_with_stdio(0);
	//scanf("%d", &N);
	cin >> N;
	
	lli mats = -1;
	
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		mats = max(arr[i], mats);
		//scanf("%lld", &arr[i]);
	}
	
	lli sum = 0;
	
	for (int i = 0; i < N; ++i) sum += mats - arr[i];
	
	cout << sum << '\n';
	
	//printf("%lld\n", arr[0]);
	
	return 0;
}