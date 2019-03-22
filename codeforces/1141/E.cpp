#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200009; 

lli d[MAXN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	lli H, n;
    
    cin >> H >> n;

    lli min_threshold = 0, relative_hp = 0, first_try = H;

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        relative_hp += d[i];
        first_try += d[i];
        if (first_try <= 0) {
            cout << (i + 1) << '\n';
            return 0;
        }
        min_threshold = min(min_threshold, relative_hp);
    }
    if (relative_hp >= 0) {
        cout << "-1\n";
        return 0;
    }
    // cout << "A: " << relative_hp << '\n';
    // cout << "B: " << min_threshold << '\n';
    // cout << "C: " << (H + min_threshold) << '\n';

    double rounds = ceil((double(H + min_threshold)) / (double(-relative_hp)));
    // cout << "D: " << rounds << '\n';

    lli new_H = H + (rounds * relative_hp);
    lli current_minutes = rounds * n;
    // cout << "E: " << new_H << '\n';

    for (int i = 0; i < n; ++i) {
        new_H += d[i];
        if (new_H <= 0) {
            cout << (current_minutes + (i + 1)) << '\n';
            return 0;
        }
    }

    return 0;
}