#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;

int q[MAXN], p[MAXN];
unordered_map<int, int> seen_numbers;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) cin >> q[i];

    int min_number = n, current_number = n;
    seen_numbers[n] = 1;
    p[0] = n;
    for (int i = 1; i < n; ++i) {
        current_number += q[i];
        seen_numbers[current_number] = 1;
        p[i] = current_number;
        min_number = min(min_number, current_number);
    }

    int valid_q = 1;
    for (int i = 0; i < n; ++i) {
        if (!seen_numbers[min_number + i]) {
            valid_q = 0;
            break;
        }
    }

    if (!valid_q) {
        cout << "-1\n";
        return 0;
    }

    int offset = 1 - min_number;
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << (p[i] + offset);
    }
    cout << '\n';

    return 0;
}