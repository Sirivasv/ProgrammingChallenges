#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100009;

typedef long long lli;

lli arr[MAX_N];


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	//12
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	int conteo = 0, curstate = 2, prev = -1;
	for (int i = 0; i < N; ++i) {
		if ((prev == -1) && (!arr[i])) continue;
		if ((curstate == 1) && (arr[i] < prev)) curstate = 2;
		else if ((curstate == 2) && (arr[i] > prev)){
			conteo++;
			curstate = 1;
		}
		prev = arr[i];
	}
	cout << conteo << '\n';
	return 0;
}