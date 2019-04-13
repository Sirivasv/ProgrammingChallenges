#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int total_cases;
    cin >> total_cases;

    for (int i = 1; i <= total_cases; ++i) {
        string lottery_total, first_half, second_half;
        cin >> lottery_total;
        int lim = lottery_total.length();
        for (int j = lim - 1; j >= 0; j--) {
            if (lottery_total[j] == '4') {
                first_half += '2';
                second_half += '2';
            } else {
                first_half += '0';
                second_half += lottery_total[j];
            }
        }
        reverse(first_half.begin(), first_half.end());
        reverse(second_half.begin(), second_half.end());
        cout << "Case #" << i << ": " << first_half << ' ' << second_half << '\n';
    }

    return 0;
}