#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200002;

lli arr[MAXN], addval[MAXN];

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(6);
	
	int N;
	//cin >> N;	
	scanf("%d", &N);
	
	lli sum = 0, many = 1;
	
	for (int i = 0; i < N; ++i) {
		int tp;
		lli ai, xi;
		
		//cin >> tp;
		scanf("%d", &tp);
		
		if (tp == 1) {
			//cin >> ai >> xi;
			scanf("%lld%lld", &ai, &xi);
			addval[ai - 1] += xi;
			sum += (ai * xi); 
		} else if (tp == 2) {
			//cin >> xi;
			scanf("%lld", &xi);
			arr[many++] = xi;
			sum += xi;
		} else {
			many--;
			sum -= arr[many] + addval[many];
			addval[many - 1] += addval[many];
			addval[many] = 0;
		}
		printf("%.6lf\n", (((double)sum) / ((double)many)));
		//cout << (((double)sum) / ((double)many)) << '\n';
	}
	
	return 0;
}