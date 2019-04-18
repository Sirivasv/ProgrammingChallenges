#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    string genome = "ACTG";

    int N;
    cin >> N;
    string s;
    cin >> s;

    int mint = 1000000;
    for (int i = 0; i < N; ++i) {
        if ((i + 3) >= N) break;
        int opr = 0;
        for (int j = 0; j < 4; ++j) {
            if (genome[j] == s[i+j]) continue;
            int a = genome[j] - 'A';
            int b = s[i+j] - 'A';
            
            int op1, op2;
            if (b > a) {
                op1 = (('Z'-'A') - b + 1);
                op1 += a;
                op2 = b - a;
            } else {
                op1 = a - b;

                op2 = b + 1;
                op2 += (('Z'-'A') - a);
                
            }
            opr += min(op1, op2);
        } 
        mint = min(opr, mint);
    }
    cout << mint << '\n';
    return 0;
}