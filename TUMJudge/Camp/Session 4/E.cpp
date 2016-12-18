#include <iostream>
#include <vector>
using namespace std;
const int MAXC = 500009;
#define ull unsigned long long

ull HB[MAXC], B = 71;

ull Subs( const vector<ull>& hasH, int a, int b ){
	return ( hasH[b] - hasH[a-1]*HB[b-a+1] );
}

ull F( char c ){
	return c - 'a' + 1;
}

void CB( ){
	HB[0] = 1; HB[1] = B;
	for( int i = 2; i < MAXC; i++ ){
		HB[i] = HB[i-1] *B;
	}
}

vector<ull> MhasH( string s ){
	vector<ull> hasH( s.size() + 1, 0 );
	for( int i = 1; i <= s.size(); i++ )
		hasH[i] = hasH[i-1]*B + F( s[i-1] );
	return hasH;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string cad, comp;
	CB();
	int casos;
	cin >> casos;
	for( int cases = 1; cases <= casos; cases++ ){
		cin >> cad >> comp;
		vector<ull> orig = MhasH( cad );
		vector<ull> otra = MhasH( comp );
		int res = 0;

		for( int i = 0; i < cad.size()-comp.size()+1; i++ ){
//			cout << Subs(orig ,i+1, comp.size() + i + 1) << ' ' << otra[comp.size()]<<endl;
			if( Subs(orig ,i+1, comp.size() + i) == otra[comp.size()] )
				res++;
		}

		cout << "Case #"<< cases <<": "<< res <<"\n";
	}
	return 0;
}