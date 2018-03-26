#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
int cubeta[50];
Long fact[50];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string A;
	cin >> A;
	fact[0] = 1;
	for(int i = 1; i <= 15; i++)
		fact[i] = i*fact[i-1];

	Long res = fact[A.size()];
	for(int i = 0; i < A.size(); i++){
		cubeta[A[i]-'a']++;
	}

	for(int i = 0; i < 30; i++){
		if(cubeta[i] != 0) res /= fact[cubeta[i]];
	}

	cout << res << '\n';
	
	

	return 0;
}
