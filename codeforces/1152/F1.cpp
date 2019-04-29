#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;
const int MAXK = 15;

lli memo[MAXN][MAXK];
int vis[MAXN][MAXK];
int ID;
int K;
lli DP(int id, int k) {
    if (k == K) return 1;
    
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;

    cin >> n >> m;

    int imprsi = 0, prsi = 0;
    for (int i = 0; i < n; ++i) {
        cin >> chst[i];
        if (chst[i] % 2) {
            imprsi++;
        } else {
            prsi++;
        }
    } 
    int imprsj = 0, prsj = 0;
    for (int i = 0; i < m; ++i){
        cin >> ky[i];
        if (ky[i] % 2) {
            imprsj++;
        } else {
            prsj++;
        }
    }

    cout << (min(imprsi, prsj) + min(prsi, imprsj)) << '\n';


    return 0;
}