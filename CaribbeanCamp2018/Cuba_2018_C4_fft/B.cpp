#include <bits/stdc++.h>
using namespace std;
typedef double Double;
typedef long long int Long;
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
	
	string S;

	cin >> S;

	int m = S.size();
	int n = 1, logn = 0;
	while (n < m) n <<= 1, logn++;
	n <<= 1, logn++;

	vector<complejo>A(n);
	vector<Long> pares(n) , orig(n), doble(n);
	for(int i  = 0 ; i < m ; i++){
		if(S[i] == '1'){ 
			A[i] = complejo(1,0);		
			orig[i] = 1;
			doble[i*2] = 1;
		}
	}

	calc_rev (n, logn);
	
	fft(A,n,false);
	for(int i = 0 ;  i < n ; i++)
		A[i] *= A[i];
	fft(A,n,true);

	Long res = 0;
	for(int i = 0 ; i < n ; i++)
		pares[i] = int(A[i].real()+0.5);
	for(int i = 0 ; i < n ; i++){
		pares[i] -= doble[i];
		if( pares[i] && ( i & 1 ) == 0 )
			if(orig[i/2]) 
				res += pares[i]/2;
	}
	cout << res << '\n';
		
	
	return 0;
}
