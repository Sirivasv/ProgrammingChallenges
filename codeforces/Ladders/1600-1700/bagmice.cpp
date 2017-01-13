#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

map<pii, double> memo;

double DP(int w, int b) {
	if (w <= 0) return 0;
	if (b <= 0) return 1;
	pii args = pii(w, b);
	if (memo.find(args) != memo.end())
		return memo[args];
	double ret = (w * 1.0) / (w + b); // winning prob
	double contp = (b * 1.0) / (w + b); //grab a b prob
	b--;
	contp *= (b * 1.0) / (w + b); //prob of dragon grab b
	b--;
	if (contp > 1e-13) { //if still have a chance
		double p_black = DP(w, b - 1) * ((b * 1.0) / (w + b));
		double p_white = DP(w - 1, b) * ((w * 1.0) / (w + b));
		ret += contp * (p_black + p_white);
	}
	return memo[args] = ret;
} 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	
	cin >> N >> M;
	
	cout << fixed << setprecision(10);
	
	cout << DP(N, M) << '\n';
	
	return 0;
}