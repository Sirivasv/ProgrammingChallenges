#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 1000000;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, Ni, Nj;
	cin >> N >> Ni >> Nj;
	if (Ni > Nj)
		swap(Ni, Nj);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		arr[i] = -arr[i];
	}
	sort(arr, arr + N);
	
	//tomar los primeros Ni
	
	double vali = 0;
	for (int i = 0; i < Ni; ++i)
		vali += (-arr[i]);
	vali = (vali / ((double)Ni)); 
	
	double valj = 0;
	int lim = Ni + Nj;
	for (int i = Ni; i < lim; ++i)
		valj += (-arr[i]);
	valj = (valj / ((double)Nj));
	
	cout << fixed << setprecision(8) << (vali + valj) << '\n';
	return 0;
}