#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int games[MAXN], bills[MAXN];

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	int N, M;
	cin >> N >> M; 

	for (int i = 0; i < N; ++i) cin >> games[i];
	for (int i = 0; i < M; ++i) cin >> bills[i];
	
	int gb = 0, bll = 0;
	for (int i = 0; i < N; ++i) {
		if ((bll < M) && (games[i] <= bills[bll])){
			gb++;
			bll++;
		}
	}
	cout << gb << '\n';

	return 0;
}