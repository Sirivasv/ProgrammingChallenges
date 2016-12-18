 #include <bits/stdc++.h>
 using namespace std;
 const int MAXN  = 100009;
 const long long INF = 10000000000;
 long long ST[MAXN * 3], price[MAXN], aux;
 int days[MAXN], N;
 
 inline void Update(int a, int b, long long val, int n, int L, int R) {
	 if (b < L || a > R) return; 
	 if (L >= a && R <= b) {
		ST[n] = val;
		return;
	 }
	 int lc = n << 1, rc = (n << 1) + 1, mid = (L + R) >> 1;
	 Update( a, b, val, lc, L, mid);
	 Update( a, b, val, rc, mid + 1, R);
	 ST[n] = min(ST[lc], ST[rc]);
	 return;
 }
 
 inline long long Query(int a, int b, int n, int L, int R) {
	 if (b < L || a > R) return INF; 
	 if (L >= a && R <= b) return ST[n];
	 int lc = n << 1, rc = (n << 1) + 1, mid = (L + R) >> 1;
	 return min(Query( a, b, lc, L, mid), Query( a, b, rc, mid + 1, R));
 }

 int main() {
	 cin.tie(0);
	 ios_base::sync_with_stdio(0);
	 while (cin >> N) {
		 for (int i = 1; i <= N; ++ i) {
			 Update(i, i, INF, 1, 1, N + 1);
			 cin >> price[i - 1];
		 }
		 for (int i = 0; i < N; ++ i) cin >> days[i];
		 Update(N + 1, N + 1, 0, 1, 1, N + 1);
		 for (int id = N - 1; id >= 0; --id) {
			 aux = price[id] + Query(id + 2, min(id + 1 + days[id], N + 1), 1, 1, N + 1);
			 Update(id + 1, id + 1, aux, 1, 1, N + 1);
		}
		 cout << aux << '\n';
	}
	 return 0;
 }