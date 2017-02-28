#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 109;

lli acumx[MAXN], acumy[MAXN];

int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	lli xi, yi, A, B;
	
	string s;
	
	cin >> A >> B >> s;
	
	for (int i = 0; i < s.size(); ++i) {
		lli vi = 0, vj = 0;
		if (s[i] == 'R') vi++;
		if (s[i] == 'U') vj++;
		if (s[i] == 'L') vi--; 
		if (s[i] == 'D') vj--;
		acumx[i + 1] = vi + acumx[i];
		acumy[i + 1] = vj + acumy[i];
	}
	
	lli sumtx = acumx[s.size()], sumty = acumy[s.size()];	
	
	int ok = 0;
	if ((!A) && (!B)) ok = 1;
	for (int i = 0; i < s.size(); ++i) {		
		if ((acumx[i + 1] == A) && (acumy[i + 1] == B)) { ok = 1;}
		else if ((sumtx) && (sumty) && (((A - acumx[i + 1]) % (sumtx)) == 0) && (((B - acumy[i + 1]) % (sumty)) == 0) && 
(((A - acumx[i + 1]) / (sumtx)) == ((B - acumy[i + 1]) / (sumty))) && ( ((B - acumy[i + 1]) / (sumty)) >= 0)) {  ok = 1; } 
		else if ((sumtx == 0) && (sumty)) {
			//puts("**");
			if ((A == acumx[i + 1]) && (((B - acumy[i + 1]) % (sumty)) == 0) && (((B - acumy[i + 1]) / (sumty)) >= 0)) ok = 1; 
		}else if ((sumty == 0) && (sumtx)) {
			if ((B == acumy[i + 1]) && (((A - acumx[i + 1]) % (sumtx)) == 0) && (((A - acumx[i + 1]) / (sumtx)) >= 0)) ok = 1;
		}
		
	}
	
	cout << ((ok)?("Yes\n"):("No\n"));
	
	return 0;
}

