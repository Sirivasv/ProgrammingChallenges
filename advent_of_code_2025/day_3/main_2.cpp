#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int main() {
  string input;
  long long answer = 0ull;
  while (getline(cin, input)) {
    map<pair<int, int>, long long> memo;
    for (int options_left = 12; options_left >= 2; --options_left){
      memo[pair<int, int>((input.length() - 1), options_left)] = -9223372036854775807ll;
    }
    memo[pair<int, int>((input.length() - 1), 1)] = (long long)(input[(input.length() - 1)] - '0');
    memo[pair<int, int>((input.length() - 1), 0)] = 0ll;
    for (int i = input.length() - 2; i >= 0; --i) {
      for (int options_left = 0; options_left <= 12; ++options_left){
        long long best_value = -9223372036854775807ll;
        best_value = max(best_value, memo[pair<int, int>(i + 1, options_left)]);
        if (options_left == 0) {
          memo[pair<int, int>(i, options_left)] = best_value;
          continue;
        }
        long long current_number =  (long long)(input[i] - '0') * (pow(10ll, (long long)(options_left - 1)));
        best_value = max(best_value, current_number + memo[pair<int, int>(i + 1, options_left - 1)]);
        memo[pair<int, int>(i, options_left)] = best_value;
      }
    }
    answer += memo[pair<int, int>(0, 12)];
  }
  cout << answer << "\n";
  return 0;
}
