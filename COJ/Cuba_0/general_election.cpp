 #include <bits/stdc++.h>
 using namespace std;
 int candidate[109];
 
 int main() {
	 cin.tie(0);
	 ios_base::sync_with_stdio(0);
	 int T, N, M, aux;
	 cin >> T;
	 while (T--) {
		 cin >> N >> M;
		 for (int j = 0; j < M; ++j)
			for (int i = 0; i < N; i++) {
				cin >> aux;
				candidate[i] += aux;
			}
		int mats = -1, ans = 0;
		for (int i = 0; i < N; i++) {
			if (candidate[i] > mats) {
				mats = candidate[i];
				ans = i + 1;
			}
			candidate[i] = 0;
		}
		cout << ans << '\n';
	 }
	 return 0;
 }