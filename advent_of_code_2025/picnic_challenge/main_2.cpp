#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<pair<pair<pair<pair<pair<pair<pair<pair<pair<pair<int, int>, int>, int>, int>, int>, int>, int>, long long>, long long>, long long>, long long> memo;
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

bool valid(int current_element_id, int selected_slot, int pos_in_slot_1, int pos_in_slot_2, int pos_in_slot_3, int last_element_in_slot_1_id, int last_element_in_slot_2_id, int last_element_in_slot_3_id) {
  int pos_in_stack = 0;
  int last_element_id = -1;
  if (selected_slot == 1) {
    pos_in_stack = pos_in_slot_1;
    last_element_id = last_element_in_slot_1_id;
  }
  else if (selected_slot == 2) {
    pos_in_stack = pos_in_slot_2;
    last_element_id = last_element_in_slot_2_id;
  }
  else if (selected_slot == 3) {
    pos_in_stack = pos_in_slot_3;
    last_element_id = last_element_in_slot_3_id;
  }

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

long long get_value(int current_element_id) {
  string current_raw_weight = "";
  for (int i = 1; i < inputs[current_element_id].size(); i++) {
    current_raw_weight += inputs[current_element_id][i];
  }
  return stoll(current_raw_weight);
}

long long optimize(int current_element_id, int selected_slot, int pos_in_slot_1, int pos_in_slot_2, int pos_in_slot_3, int last_element_in_slot_1_id, int last_element_in_slot_2_id, int last_element_in_slot_3_id, long long sum_in_slot_1, long long sum_in_slot_2, long long sum_in_slot_3) {
  pair<pair<pair<pair<pair<pair<pair<pair<pair<pair<int, int>, int>, int>, int>, int>, int>, int>, long long>, long long>, long long> state = {{{{{{{{{{current_element_id, selected_slot}, pos_in_slot_1}, pos_in_slot_2}, pos_in_slot_3}, last_element_in_slot_1_id}, last_element_in_slot_2_id}, last_element_in_slot_3_id}, sum_in_slot_1}, sum_in_slot_2}, sum_in_slot_3};
  if (memo.find(state) != memo.end()) return memo[state];
  long long max_slot_sum = max(sum_in_slot_1, max(sum_in_slot_2, sum_in_slot_3));
  long long min_slot_sum = min(sum_in_slot_1, min(sum_in_slot_2, sum_in_slot_3));
  if (current_element_id >= inputs.size()) return memo[state] = 1000ll + pow(max_slot_sum - min_slot_sum, 2);

  long long current_answer = 999999999999ll;
  if (valid(current_element_id, selected_slot, pos_in_slot_1, pos_in_slot_2, pos_in_slot_3, last_element_in_slot_1_id, last_element_in_slot_2_id, last_element_in_slot_3_id)) {
    
    if (selected_slot == 1) {
      last_element_in_slot_1_id = current_element_id;
      sum_in_slot_1 += get_value(current_element_id);
    }
    else if (selected_slot == 2) {
      last_element_in_slot_2_id = current_element_id;
      sum_in_slot_2 += get_value(current_element_id);
    }
    else if (selected_slot == 3) {
      last_element_in_slot_3_id = current_element_id;
      sum_in_slot_3 += get_value(current_element_id);
    }
    
    current_answer = min(current_answer, optimize(current_element_id + 1, 1, pos_in_slot_1 + 1, pos_in_slot_2, pos_in_slot_3, last_element_in_slot_1_id, last_element_in_slot_2_id, last_element_in_slot_3_id, sum_in_slot_1, sum_in_slot_2, sum_in_slot_3));
    current_answer = min(current_answer, optimize(current_element_id + 1, 2, pos_in_slot_1, pos_in_slot_2 + 1, pos_in_slot_3, last_element_in_slot_1_id, last_element_in_slot_2_id, last_element_in_slot_3_id, sum_in_slot_1, sum_in_slot_2, sum_in_slot_3));
    current_answer = min(current_answer, optimize(current_element_id + 1, 3, pos_in_slot_1, pos_in_slot_2, pos_in_slot_3 + 1, last_element_in_slot_1_id, last_element_in_slot_2_id, last_element_in_slot_3_id, sum_in_slot_1, sum_in_slot_2, sum_in_slot_3));
  }

  long long ship_away_cost = 1000ll + pow(max_slot_sum - min_slot_sum, 2);
  current_answer = min(current_answer, optimize(current_element_id + 1, 1, 2, 0, 0, current_element_id, -1, -1, get_value(current_element_id), 0ll, 0ll) + ship_away_cost);
  current_answer = min(current_answer, optimize(current_element_id + 1, 2, 1, 1, 0, current_element_id, -1, -1, get_value(current_element_id), 0ll, 0ll) + ship_away_cost);
  current_answer = min(current_answer, optimize(current_element_id + 1, 3, 1, 0, 1, current_element_id, -1, -1, get_value(current_element_id), 0ll, 0ll) + ship_away_cost);

  current_answer = min(current_answer, optimize(current_element_id + 1, 1, 1, 1, 0, -1, current_element_id, -1, 0ll, get_value(current_element_id), 0ll) + ship_away_cost);
  current_answer = min(current_answer, optimize(current_element_id + 1, 2, 0, 2, 0, -1, current_element_id, -1, 0ll, get_value(current_element_id), 0ll) + ship_away_cost);
  current_answer = min(current_answer, optimize(current_element_id + 1, 3, 0, 1, 1, -1, current_element_id, -1, 0ll, get_value(current_element_id), 0ll) + ship_away_cost);

  current_answer = min(current_answer, optimize(current_element_id + 1, 1, 1, 0, 1, -1, -1, current_element_id, 0ll, 0ll, get_value(current_element_id)) + ship_away_cost);
  current_answer = min(current_answer, optimize(current_element_id + 1, 2, 0, 1, 1, -1, -1, current_element_id, 0ll, 0ll, get_value(current_element_id)) + ship_away_cost);
  current_answer = min(current_answer, optimize(current_element_id + 1, 3, 0, 0, 2, -1, -1, current_element_id, 0ll, 0ll, get_value(current_element_id)) + ship_away_cost);

  return memo[state] = current_answer;
}

int main() {
  string input;
  long long answer = 9999999999ll;
  vector<vector<bool>> visited;
  while (getline(cin, input)) {
    split(input, inputs, ' ');
  }
  answer = min(answer, optimize(1, 1, 2, 0, 0, 0, -1, -1, get_value(0), 0ll, 0ll));
  answer = min(answer, optimize(1, 2, 1, 1, 0, 0, -1, -1, get_value(0), 0ll, 0ll));
  answer = min(answer, optimize(1, 3, 1, 0, 1, 0, -1, -1, get_value(0), 0ll, 0ll));

  answer = min(answer, optimize(1, 1, 1, 1, 0, -1, 0, -1, 0ll, get_value(0), 0ll));
  answer = min(answer, optimize(1, 2, 0, 2, 0, -1, 0, -1, 0ll, get_value(0), 0ll));
  answer = min(answer, optimize(1, 3, 0, 1, 1, -1, 0, -1, 0ll, get_value(0), 0ll));

  answer = min(answer, optimize(1, 1, 1, 0, 1, -1, -1, 0, 0ll, 0ll, get_value(0)));
  answer = min(answer, optimize(1, 2, 0, 1, 1, -1, -1, 0, 0ll, 0ll, get_value(0)));
  answer = min(answer, optimize(1, 3, 0, 0, 2, -1, -1, 0, 0ll, 0ll, get_value(0)));
  cout << answer << endl;
  return 0;
}
