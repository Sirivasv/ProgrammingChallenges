#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k;

    cin >> n >> k;

    if (k == 1 || k == n) {
        cout << (((n - 2) * 3) + 6) << '\n';
    } else {
        cout << (6 + (4*(min(n - k - 1, k - 2)) + 1 + (3*(max(n - k, k - 1))) )) << '\n';
    }

    return 0;
}