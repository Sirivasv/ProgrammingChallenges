#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<pair<pair<int, int>, int>, long long> memo;
vector<string> inputs;

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

long long get_cost(int pos_in_stack) {
  if (pos_in_stack == 0) return 0ll;
  if (pos_in_stack == 1) return 50ll;
  if (pos_in_stack == 2) return 25ll;
  if (pos_in_stack == 3) return 10ll;
  if (pos_in_stack == 4) return 0ll;
  return 999999999999ll;
}

bool valid(int current_element_id, int pos_in_stack, int last_element_id) {
  if (pos_in_stack > 4) return false;

  char current_type = inputs[current_element_id][0];
  string current_raw_weight = "";
  for (int i = 1; i < inputs[current_element_id].size(); i++) {
    current_raw_weight += inputs[current_element_id][i];
  }
  int current_weight = stoi(current_raw_weight);

  char last_type = inputs[last_element_id][0];
  string last_raw_weight = "";
  for (int i = 1; i < inputs[last_element_id].size(); i++) {
    last_raw_weight += inputs[last_element_id][i];
  }
  int last_weight = stoi(last_raw_weight);

  if (current_type == 'F') {
    if (last_type == 'F') {
      return current_weight <= last_weight;
    } else {
      return false;
    }
  } else if (current_type == 'C') {
    if (last_type == 'F' || last_type == 'C') {
      return current_weight <= last_weight;
    } else {
      return false;
    }
  }
  return current_weight <= last_weight;
}
long long optimize(int current_element_id, int pos_in_stack, int last_element_id) {
  pair<pair<int, int>, int> state = {{current_element_id, pos_in_stack}, last_element_id};
  if (memo.find(state) != memo.end()) return memo[state];
  if (current_element_id >= inputs.size()) return memo[state] = get_cost(pos_in_stack - 1);

  long long current_answer = 999999999999ll;
  if (valid(current_element_id, pos_in_stack, last_element_id)) {
    current_answer = min(current_answer, optimize(current_element_id + 1, pos_in_stack + 1, current_element_id));
  }
  current_answer = min(current_answer, optimize(current_element_id + 1, 2, current_element_id) + get_cost(pos_in_stack - 1));

  return memo[state] = current_answer;
}

int main() {
  string input;
  long long answer = 0ll;
  vector<vector<bool>> visited;
  while (getline(cin, input)) {
    split(input, inputs, ' ');
  }
  answer = optimize(1, 2, 0);
  cout << answer << endl;
  return 0;
}
