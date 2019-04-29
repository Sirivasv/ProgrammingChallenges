#include <bits/stdc++.h>
using namespace std;

int is_ready(int xi) {

    int one_found = 0;
    int zero_found = 0;

    while (xi) {
        if (xi % 2) {
            if (zero_found) return 0;
            one_found = 1;
        } else {
            if (!one_found) return 0;
            zero_found = 1;
        }
        xi >>= 1;
    }
    
    return 1;
}

int main() {
    // cin.tie(0); ios_base::sync_with_stdio(0);

    int n;

    cin >> n;

    vector<int> ans;
    int ops = 0;
    int step = 0;
    int pos = (int)log2(n);
    while (!is_ready(n)) {
        while (pos) {
            if (n & (1 << pos)) {
                pos--;
                continue;
            }
            pos++;
            break;
        }

        // cout << n << ' ' << pos << '\n';
        ans.push_back(pos);
        n ^= ((1 << pos) - 1);
        ops++;
        if (is_ready(n)) break;
        n++;
        ops++;
        pos--;
    }
    cout << ops <<'\n';
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    if (ans.size()) cout << '\n';

    return 0;
}