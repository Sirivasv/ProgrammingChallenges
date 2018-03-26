#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef long long int Long;

int main(){
	
	Long a,b;
	Long x1,x2;
	Long mul = 1;
	optimizar_io(0);
	
	Long x;
	cin >> x1 >> x2 >> a >> b ; 
	x = x1;
	if(x2 < x1){
		swap(x1,x2);
		a *= -1;
		b *= -1;
		swap(a,b);
		mul = -1;
	}
	Long dist = x2 - x1 ;
	if( a < 0 ){
		if(b < 0 ){
			cout << "DRAW\n";
		} else {
			if(b >= dist){
				cout << "FIRST\n";
				cout << x + dist*mul << '\n';
			} else {
				cout << "DRAW\n";
			}
		}
	} else if(a == 0){
		if(b >= dist){
			cout << "FIRST\n";
			cout << x + dist*mul << '\n';
		} else {
			cout << "DRAW\n";
		}
	} else {
		dist %= (a+b);
		if(dist == 0 ){
			cout << "SECOND\n";
		} else if(dist >= a && dist <= b ){
			cout << "FIRST\n" << x + dist*mul << '\n';
		} else {
			cout << "DRAW\n";
		}
	}
	return 0;
}
