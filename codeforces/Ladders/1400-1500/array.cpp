#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int arr[MAXN], tkn[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	//fill first set with one negative number
	for (int i = 0; i < N; ++i)
		if (arr[i] < 0) {
			tkn[i] = 1;
			cout << 1 << ' ' << arr[i] << '\n';
			break;
		}

	//try fill second set with one positive integer
	int ok = 0;
	for (int i = 0; i < N; ++i)
		if (arr[i] > 0) {
			tkn[i] = 2;
			ok = 1;
			cout << 1 << ' ' << arr[i] << '\n';
			break;
		}
	if (!ok) {
		cout << 2 << ' ';
		ok = 0;
		for (int i = 0; i < N; ++i) {
			if (tkn[i])
				continue;
			if (arr[i] < 0) {
				tkn[i] = 2;
				ok++;
				cout << arr[i] << ' ';
				if (ok == 2)
					break;
			}
		}
		cout << '\n';
	}
	cout << ((ok == 1)?(N - 2):(N - 3)) << ' ';
	for (int i = 0; i < N; ++i)
		if (tkn[i] == 0)
			cout << arr[i] << ' ';
		
	return 0;
}