#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
int arr[MAXN];
int vals[] = {1, 10, 100, 1000, 10000};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int NP, NM;
	while (cin >> NP >> NM) {
		int pgot = 0, phgot = 0; 
		for (int i = 0; i < NM; ++i) {
			int TOT;
			cin >> TOT;
			for (int j = 0; j < NP; ++j) {
				cin >>  arr[j];
				if (j)
					TOT -= arr[j];
			}
			if (arr[0] <= TOT)
				pgot += arr[0];
			for (int j = 4; j >= 0; --j) {
				if (vals[j] <= TOT) {
					phgot += vals[j];
					break;
				}
			}
		}
		cout << phgot - pgot << '\n';
	}
	return 0;
}