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

bool invalid(unsigned long long int n) {
  string s = to_string(n);
  bool is_repeating = true;
  if (s.size() == 1) return false;

  int size_of_block = 1;
  for (int block_size = 1; block_size <= s.size()/2; ++block_size) {
    if (s.size()%block_size != 0) continue;
    is_repeating = true;
    for (int i = 0; i <= (s.size()/block_size)-1; ++i) {
      if (s.substr(0, block_size) != s.substr(i*block_size, block_size)) {
        is_repeating = false;
        break;
      }
    }
    if (is_repeating) {
      size_of_block = block_size;
      break;
    }
  }
  return is_repeating;
}

int main() {
  string input;
  
  unsigned long long int answer = 0;

  while (getline(cin, input)) {

    vector<string> input_parts;
    split(input, input_parts, ',');
    for (const string &part : input_parts) {
      vector<string> range_parts;
      split(part, range_parts, '-');
      unsigned long long int start = stoull(range_parts[0]);
      unsigned long long int end = stoull(range_parts[1]);
      for (unsigned long long int i = start; i <= end; ++i) {
        if(invalid(i)) answer += i;
      }
    }
  }
  cout << answer << "\n";
  return 0;
}
