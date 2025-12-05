#include <iostream>
#include <string>
#include <vector>
using namespace std;

void split(const string &s, vector<string> &elems, char delim) {
  size_t start = 0;
  size_t end = s.find(delim);
  while (end != string::npos) {
    elems.push_back(s.substr(start, end - start));
    start = end + 1;
    end = s.find(delim, start);
  }
  elems.push_back(s.substr(start, end));
}

int main() {
  string input;
  int answer = 0;
  vector<pair<long long, long long>> ranges;
  while (getline(cin, input)) {
    vector<string> input_parts;
    split(input, input_parts, '-');
    if (input_parts.size() == 2) {
      long long start = stoll(input_parts[0]);
      long long end = stoll(input_parts[1]);
      ranges.push_back({start, end});
    } else if(input_parts[0] == "") {
      continue;
    } else if (input_parts.size() == 1) {
      long long number = stoll(input_parts[0]);
      for (const auto &range : ranges) {
        if (number >= range.first && number <= range.second) {
          answer++;
          break;
        }
      }
    }

  }
  cout << answer << "\n";
  return 0;
}
