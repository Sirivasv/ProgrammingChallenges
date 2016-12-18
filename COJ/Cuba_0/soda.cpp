 #include <bits/stdc++.h>
 using namespace std;
 
 int main() {
	 cin.tie(0);
	 ios_base::sync_with_stdio(0);
	 int N, E, F, C;
	 cin >> N;
	 while (N--){
		 cin >> E >> F >> C;
		 E += F;
		 int ans = 0;
		 int rem = 0;
		 int prevval = E;
		 bool flag = false;
		 while(E) {
			 if (E > C) rem = E % C;
			 else rem = 0;
			 E /= C;
			 ans += E;
			 E += rem;
			 if (prevval == E) {
				 cout << "0\n";
				 flag = true;
				 break;
			 }
			 prevval = E;
		 }
		 if (!flag) cout << ans << '\n';
	 }
	 return 0;
 }