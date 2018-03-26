#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
const Long MOD = 1000000000LL;

vector<string> sol1, sol2;

Long Euclides( Long a, Long b){
	if(!b){
		return a;
	}
	return Euclides(b, a%b);
}

Long pEuclides( Long a, Long b, int tp = 0){
	if(!b){
		return a;
	}
	
	Long times = a / b;	
	
	if (tp) {
		if(times != 0){
			string cur;
			if( times > 0 )
				cur = "a -= ";
			else
				cur = "a += ";			
			cur += to_string(abs(times));
			cur += " * b";
			sol1.push_back(cur);
		}
		sol1.push_back("swap(a, b)");		
	} else {
		sol2.push_back("swap(a, b)");
		if(times != 0){		
			string cur;
			if( times > 0 )
				cur = "b += ";
			else
				cur = "b -= ";			
			cur += to_string(abs(times));
			cur += " * a";		
			sol2.push_back(cur);
		}
	}
	return pEuclides(b, a%b, tp);;
}

int main() {
	
	Long a, b, c, d;
	cin >> a >> b >> c >> d;
	// cout << Euclides(a, b, xi, yi, 0) << " -- " << Euclides(c, d, xi, yi, 0) << '\n'; 
	Long gcd1 = Euclides(a, b);
	Long gcd2 = Euclides(c, d);
	
	if (abs(gcd1) != abs(gcd2)) {
		cout << "No solution.\n";	
		return 0;
	}
	
	int bandera = (gcd1 != gcd2);
	 
	pEuclides(a, b, 1);
	pEuclides(c, d, 0);
	cout << sol1.size() + sol2.size() + (bandera? 3 : 0) << '\n';
	reverse(sol2.begin(), sol2.end());
	for (auto it: sol1) cout << it << '\n';
	if(bandera){
		cout << "b -= 1 * a\n";
		cout << "swap(a, b)\n";
		cout << "b += 1 * a\n";
	}
	for (auto it: sol2) cout << it << '\n';	
	return 0;
}
