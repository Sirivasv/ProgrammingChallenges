#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
  string input;
  long long answer = 0;
  vector<vector<long long>> numbers_to_process;
  int current_operation = 0;

  while (getline(cin, input)) {
    vector<string> input_parts;
    stringstream ss(input);
    while (ss.good()) {
      string part;
      ss >> part;
      if (part == "") continue;
      input_parts.push_back(part);
    }
    
    if (input_parts[0] == "+" || input_parts[0] == "*"){
      for (const auto &part : input_parts) {
        long long current_result = (input_parts[current_operation] == "+") ? 0ll : 1ll;
        
        for (auto &number_list : numbers_to_process) {
          long long number_i = number_list[current_operation];
          if (input_parts[current_operation] == "+") {
            current_result += number_i;
          } else {
            current_result *= number_i;
          }
        }

        current_operation++;
        answer += current_result;
      }
    } else {
      numbers_to_process.push_back({});
      for (const auto &part : input_parts) {
        long long number = stoll(part);
        numbers_to_process.back().push_back(number);
      }
    }
  }
  cout << answer << "\n";
  return 0;
}
