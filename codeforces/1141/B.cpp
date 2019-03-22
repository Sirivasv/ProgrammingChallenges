#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400009;

int schedule[MAXN];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> schedule[i];
        schedule[i + n] = schedule[i];
    }

    int max_seen = 0, current_size = 0;
    for (int i = 0; i < n+n; ++i) {
        if (schedule[i] == 1) {
            current_size++;
        } else {
            current_size = 0;
        }
        max_seen = max(max_seen, current_size);
    }
    cout << max_seen << '\n';
    return 0;
}