#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
lli MAXN = 800009;

lli primes[800009];
lli criba[800009];
lli arr[5];
lli MnyPrms;

void Criba(){
	lli raiz = MAXN;
	for( lli i = 4; i <= MAXN; i +=2 )
		criba[i] = 2;
	for( lli i = 3; i <= MAXN; i += 2 )
		if( !criba[i] )
			for( lli j = i * i; j <= MAXN; j+= i )
				if( !criba[j] ) criba[j] = i;

	for(lli i = 2; i <= MAXN; i++ ){
		if( !criba[i] ){
			primes[MnyPrms++] = i;
		}		
	}
}	

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    Criba();
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int op;
        cin >> op;
        arr[op]++;
    }

    int lst = 0;
    int idPrm = 0;
    int mnyAns = 0;
    while (1) {
        if (mnyAns++) cout << " ";
        if ((primes[idPrm] - lst) >= 2) {
            if (arr[2]) {
                cout << "2";
                arr[2]--;
                lst += 2;
            } else if (arr[1]){
                cout << "1";
                arr[1]--;
                lst++;
            } else {
                break;
            }
        } else if ((primes[idPrm] - lst) == 1) {
            if (arr[1]) {
                cout << "1";
                arr[1]--;
                lst++;
            } else if (arr[2]){
                cout << "2";
                arr[2]--;
                lst+=2;
            } else {
                break;
            }
        }
        if (lst >= primes[idPrm]) idPrm++;
        if (idPrm == MnyPrms) break;   
    }
    cout << '\n';

    return 0;
}