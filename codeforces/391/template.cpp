#include <bits/stdc++.h>
using namespace std;

//Si ordenas recuerda los ID XD

//Binaria, Greedy, Sortings, Estructuras, Strings, Grafos, Mates, DP, combinaciones entre las anteriores

typedef long long lli;

const int MAXN = 100009;

lli arr[MAXN];
int N;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	scanf("%d", &N);
	//cin >> N; 
	for (int i = 0; i < N; ++i) //cin >> arr[i];
		scanf("%lld", &arr[i]);
	//cout << arr[N - 1] << '\n';
	printf("%lld\n", arr[N - 1]);
	return 0;
}