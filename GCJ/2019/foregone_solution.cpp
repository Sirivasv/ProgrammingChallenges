#include <bits/stdc++.h>
using namespace std;

bool has_digit_four(int number) {
    while (number) {
        if (number % 10 == 4) return true;
        number /= 10;
    }
    return false;
}

pair<int, int> split_without_digit_four(int number_to_print) {

    for (int first_half = 0; first_half < number_to_print; ++first_half) {
        int second_half = number_to_print - first_half;
        if (has_digit_four(first_half) || has_digit_four(second_half)) continue;
        return {first_half, second_half};
    }
    return {-1, -1};
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int total_cases;
    cin >> total_cases;

    for (int i = 1; i <= total_cases; ++i) {
        int lottery_total;
        cin >> lottery_total;
        pair<int, int> result = split_without_digit_four(lottery_total);
        cout << "Case #" << i << ": " << result.first << ' ' << result.second << '\n';
    }

    return 0;
}