#include<bits/stdc++.h>
using namespace std;

const int MAXN = 109;

int l[MAXN], r[MAXN];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    int k;
    cin >> k;
    for (int i = 0; i < n; ++i) if (k >= l[i] && k <= r[i]) {
        cout << (n - i) << '\n';
        break;
    }

    return 0;
}