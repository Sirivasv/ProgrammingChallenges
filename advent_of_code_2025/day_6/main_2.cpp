#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<long long>> cephalopodize(const vector<string> &input_numbers) {
  vector<vector<long long>> result;
  int rows = input_numbers.size();
  result.push_back({});
  for (int i = 0; i < input_numbers[0].size(); i++) {
    long long current_number = 0ll;
    bool found_digit = false;
    for (int j = 0; j < rows; j++) {
      if (input_numbers[j][i] < '0' || input_numbers[j][i] > '9') {
        continue;
      }
      found_digit = true;
      current_number = current_number * 10 + (input_numbers[j][i] - '0');
    }
    if (!found_digit) {
      current_number = 0ll;
      result.push_back({});
      continue;
    }
    result.back().push_back(current_number);
  }
  return result;
}

int main() {
  string input;
  long long answer = 0;
  vector<string> input_numbers;

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
      vector<vector<long long>> cephalopod_numbers = cephalopodize(input_numbers);
      int current_operation = 0;
      for (int i = 0; i < cephalopod_numbers.size(); i++) {
        long long current_value = (input_parts[current_operation] == "+") ? 0ll : 1ll;
        for (const auto &num : cephalopod_numbers[i]) {
          if (input_parts[current_operation] == "+") {
            current_value += num;
          } else {
            current_value *= num;
          }
        }
        answer += current_value;
        current_operation++;
      }
    } else {
      input_numbers.push_back(input);
    }
  }
  cout << answer << "\n";
  return 0;
}
