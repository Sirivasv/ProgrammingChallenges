#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int MAXC = 100009;

ull HB[MAXC], B = 71;

ull F(char c){
    return c - 'a' + 1;
}

void CB(){
    HB[0] = 1; HB[1] = B;
    for (int i = 2; i < MAXC; ++i) 
        HB[i] = HB[i - 1] * B;
}

vector<ull> MHash(string s){
    vector<ull> hash(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); ++i) 
        hash[i] = hash[i - 1] * B + F(s[i - 1]); 
    return hash;
}

ull Subs(const vector<ull>& hash, int a, int b){
    return hash[b] - hash[a - 1] * HB[b - a + 1];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    CB();
    int T, N;
    cin >> T;
    for(; T; --T) {
        string s, ss;
        cin >> s;
        int N = s.size();
        ss = s + s;
        vector<ull> THash = MHash(ss);
        int i = 0, k = 1, ans = 0;
        for (; k < N; ++k) {
            //cout << Subs(THash, i + 1, i + N) << " - " << Subs(THash, k + 1, k + N) << '\n';
            if (Subs(THash, i + 1, i + N) == Subs(THash, k + 1, k + N)) continue;
            int in = 1, fin = N + 1, mid;
            while (in < fin) {  
                mid = (in + fin) / 2;
                if (Subs(THash, i + 1, i + mid) != Subs(THash, k + 1, k + mid)) fin = mid;
                else in = mid + 1;
            }
            //cout << "Comparamos: " << ss.substr(i, N) << " Con: " << ss.substr(k, N) << '\n';
            //cout << "Salieron diferentes del caracter: " << fin << '\n';
            if (ss[i + fin - 1] > ss[k + fin - 1]) {
                //cout << ss[i + fin - 1] << " - " << ss[k + fin - 1] << " " << k << '\n';
                ans = k;
                i = k;
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}
