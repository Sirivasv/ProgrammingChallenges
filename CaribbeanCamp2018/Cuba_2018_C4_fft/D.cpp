#include <bits/stdc++.h>
using namespace std;
typedef double Double;
typedef complex <Double> complejo;
const int MAXN = 2000000;
int rev[MAXN];

complejo wlen_pw[MAXN];

void fft ( vector<complejo>& a, int n, bool invert ) {
	for (int i = 0; i < n; ++i) {
		if (i < rev[i]) {
			swap(a[i], a[rev[i]]);		
		}
	}

	for (int len = 2; len <= n; len <<= 1) {
		Double ang = 2 * M_PI / len * (invert ? - 1 : + 1);
		int len2 = len >> 1;
		complejo wlen(cos(ang), sin(ang));
		wlen_pw[0] = complejo(1, 0);
		for (int i = 1; i < len2; ++i) {
			wlen_pw[i] = wlen_pw[i - 1] * wlen;		
		} 
		complejo t; int r, l;
		for (int i = 0; i < n; i += len) {
			for (int j = 0; j < len/2; ++j) {
				r = i + j + len / 2; l = i + j;
				t = a[r] * wlen_pw[j];
				a[r] = a[l] - t;
				a[l] += t;
			}
		}
	}
	if (invert)
		for (int i = 0; i < n; ++i)
			a[i] /= n;
} 

void calc_rev (int n, int log_n) {
	for (int i = 0; i < n; ++i) {
		rev[i] = 0;
		for (int j = 0; j < log_n; ++j) {
			if (i & (1 << j))
				rev[i] |= 1 << (log_n - 1 - j);		
		}
	}
}

void Multiplica( vector<complejo>& A, vector<complejo>& B ){
	fft( A, A.size(), false );
	fft( B, B.size(), false );
	for( int i = 0; i < A.size(); i++ ){
		A[i] *= B[i];
	}
	fft( A, A.size(), true );
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	string N, M;

	cin >> N >> M;

	if( N == "0" || M == "0" ){
		cout << "0\n";
		return 0;
	}
	
	int simbolo = 1;
	if( N[0] == '-' ){
		simbolo *= -1;
		N = N.substr(1);
	}
	if( M[0] == '-' ){ 
		simbolo *= -1;
		M = M.substr(1);
	}

	int len = max( N.size(), M.size() );

	int n = 1, logn = 0;
	while (n < len) n <<= 1, logn++;
	n <<= 1, logn++;

	vector<complejo> A(n),B(n);
	reverse(N.begin(), N.end());
	reverse(M.begin(), M.end());

	for( int i = 0; i < N.size(); i++ ){
		A[i] = complejo(Double(N[i]-'0'), 0);	
	}
	for( int i = 0; i < M.size(); i++ ){
		B[i] = complejo(Double(M[i]-'0'), 0);
	}
	
	calc_rev( n, logn );

	Multiplica( A, B );
	string res = "";


	int carry = 0;
	for( int i = 0; i < A.size(); i++ ){
		carry += (int)(A[i].real() + 0.5);
		res += carry%10 + '0';
		carry/=10;
	}

	while( carry ){
		res += carry%10 + '0';
		carry/=10;		
	}
	
	reverse( res.begin(), res.end() );
	int ini = 0;
	for( int i = 0; i < res.size(); i++ )
		if( res[i] != '0' ){
			ini = i;
			break;
		}

	if( simbolo < 0 ) cout << '-';
	cout << res.substr( ini ) << '\n';
	
	return 0;
}
