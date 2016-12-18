#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10009;

int N;
string s;
int vis[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	while (cin >> N) {
		if (!N)
			break;
		cin >> s;
		for (int i = 0; i < N; ++i)
			vis[i] = 0;
		int winp = 0, edw = 0;
		for (int i = 0; i < N; ++i) {
			if (i <= (N - 3)) {
				//cout << i << '\n';
				int cnt = 0;
				if (s[i] == 'X')
					cnt++;
				if (s[i + 1] == 'X')
					cnt++;
				if (s[i + 2] == 'X')
					cnt++;
				if ((cnt) && (cnt == 2))
					winp++;
				if (cnt) 
					vis[i] = vis[i + 1] = vis[i + 2] = 1;
			}
		}
		if (winp) {
			cout << "S\n";
			continue;
		}
		int tam = 0;
		for (int i = 0; i < N; ++i) {
			if (vis[i] == 0)
				tam++;
			else {
				if (tam % 3)
					edw += ((tam) / 3) + 1;
				else
					edw += tam / 3;
			}
				
		}
		//cout << tam << '\n';
	
		if (edw & 1) 
			cout << "S\n";
		else
			cout << "N\n";
	}
	return 0;
}