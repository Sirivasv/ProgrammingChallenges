#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;

typedef long long lli;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;	
	cin >> N;
	int impar = 0, par = 0;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		if (arr[i] & 1) impar++;
		else par++;
	}
	if (impar == 0) {
		cout << "Second\n";
		return 0;
	}
	//if (impar & 1){
	//	cout << "First\n";
	//	return 0;
	//}
	cout << "First\n";
	return 0;
}