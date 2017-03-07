#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109;

double pi[MAXN];

int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i) 
		cin >> pi[i];
	
	sort(pi, pi + N, greater<double>());
	
	double ans = 0.0;
	
	for (int i = 0; i < N; ++i) {
		double sum = 0.0;
		for (int j = 0; j <= i; ++j) {
			double mult = pi[j];
			for (int k = 0; k <= i; ++k)
				if (k != j) mult *= (1.0 - pi[k]);
			sum += mult;
		}
		ans = max(ans, sum);
	}
	
	cout << fixed << setprecision(10) << ans << '\n';
	
	return 0;
}