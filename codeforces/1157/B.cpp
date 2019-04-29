#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int nwVl[MAXN];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N;
    string s;

    cin >> N;
    cin >> s;
    for (int i = 0; i < 10; ++i) cin >> nwVl[i + 1];

    int lim = s.size();
    int fnd_bgr = 0;
    for (int i = 0; i < lim; ++i) {
        int curr = s[i] - '0';
        if (curr < nwVl[curr]) {
            fnd_bgr = 1;
            // cout << s[i] << '\n';
            s[i] = '0' + nwVl[curr];
            // cout << s[i] << '\n';
        } else if (curr > nwVl[curr]){
            if (fnd_bgr) {
                break;
            }
        }
    }

    cout << s << '\n';
    return 0;
}