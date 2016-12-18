#include<bits/stdc++.h>
using namespace std;

double Dist(double ox, double oy, double dx, double dy) {
	return sqrt(((ox - dx) * (ox - dx)) + ((oy - dy) * (oy - dy)));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	double ox, oy;
	cin >> ox >> oy;
	int N;
	cin >> N;
	double mint = 1000000.0;
	for (int i = 0; i < N; ++i) {
		double dx, dy, v;
		cin >> dx >> dy >> v;
		mint = min(mint, (Dist(ox, oy, dx, dy) / v));
	}
	cout << fixed << setprecision(9) << mint << '\n';
	return 0;
}