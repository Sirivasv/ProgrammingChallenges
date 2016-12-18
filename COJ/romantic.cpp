#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;

double arr[MAXN];

int LOG2(int x) {
	int res = 0;
	while (x) {
		x /= 2;
		res++;
	}
	res--;
	return res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	vector<double> curr(1);
	curr[0] = arr[0];
	int cori = 1;
	int logl = LOG2(N);
	//cout << logl << '\n';
	for (int i = 0; i < logl; ++i) {
		vector<double> arrn;
		int nori = (cori * 2);
		for (int j = 0; j < curr.size(); ++j) {
			double D = arr[j + cori];
			arrn.push_back(((2.0 * curr[j]) + (2.0 * D)) / 2.0);
			arrn.push_back(((2.0 * curr[j]) - (2.0 * D)) / 2.0);
		}
		curr = arrn;
		cori = nori;
	}
	for (int i = 0; i < curr.size(); ++i) {
		if (i)
			cout << ' ';
		cout << curr[i];
	}
	return 0;
}