#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string t;
    cin >> t;

    int N = t.size();
    int mna = 0;
    for (int i = 0; i < N; ++i) {
        mna += t[i] == 'a';
    }
    if ((N + mna) % 2) {
        cout << ":(\n";
        return 0;
    }
    int limit = ((N + mna) >> 1);
    int j = ((N + mna) >> 1);
    int valid = 1;
    
    for (int i = 0; (i < limit) && (j < N); ++i) {
        if (t[i] == 'a') continue;
        if (t[i] != t[j]) {
            valid = 0;
            break;
        } else {
            j++;
        }
    }

    if (!valid) {
        cout << ":(\n";
        return 0;
    }

    for (int i = 0;i < limit; ++i) cout << t[i];
    cout << '\n';

    return 0;
}