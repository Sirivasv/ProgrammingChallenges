#include <bits/stdc++.h>
using namespace std;

int apply(int xi) {
    xi++;
    while ((xi % 10) == 0) {
        xi/=10;
        if (xi == 0) break;
    }
    return xi;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    set<int> seen;

    int n;
    cin >> n;
    while (1) {
        if (seen.count(n)) break;
        seen.insert(n);
        n = apply(n);
        // cout << n << '\n';
    }

    cout << seen.size() << '\n';

    return 0;
}