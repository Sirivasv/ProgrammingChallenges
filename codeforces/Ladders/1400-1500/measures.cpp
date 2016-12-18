#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arr[MAXN];

int BusBin(int ini, int fin) {
	int val = arr[ini], m, res = -1;
	while (ini <= fin) {
		m = (ini + fin) / 2;
		if (arr[m] <= (2 * val)) {
			res = m;
			ini = m + 1;
		} else
			fin = m - 1;
	}
	return res;
} 

int main() {
	ifstream in("input.txt");
    ofstream out("output.txt");
	int N;
	in >> N;
	for (int i = 0; i < N; ++i) 
		in >> arr[i];
	sort(arr, arr + N);
	int ans = 200000;
	
	for (int i = 0; i < N; ++i) {
		int pans = i;
		int idj = BusBin(i, N - 1);
		if (idj == -1)
			continue;
		pans += (N - 1) - idj;
		ans = min(ans, pans);
	}
	
	out << ans << '\n';
	return 0;
}