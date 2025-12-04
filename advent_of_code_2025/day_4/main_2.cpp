#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

int directions[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int count_rolls(vector<string> *inputs, int i, int j) {
  int many_rolls = 0;
  for (int d = 0; d < 8; d++) {
    int ni = i + directions[d][0];
    int nj = j + directions[d][1];
    if (ni >= 0 && ni < (*inputs).size() && nj >= 0 && nj < (*inputs)[ni].size()) {
      if ((*inputs)[ni][nj] == '@') {
        many_rolls++;
      }
    }
  }
  return many_rolls;
}

int main() {
  string input;
  vector<string> inputs;
  map<pair<int, int>, int> rolls_blocking;
  while (getline(cin, input)) {
    inputs.push_back(input);
  }
  priority_queue<pair<int, pair<int, int>>> lift_rolls;
  for (int i = 0; i < inputs.size(); i++){
    for (int j = 0; j < inputs[i].size(); j++){
      int rolls = count_rolls(&inputs, i, j);
      if (inputs[i][j] == '@') {
        rolls_blocking[{i, j}] = rolls;
        lift_rolls.push({rolls, {i, j}});
      }
    }
  }
  set<pair<int, int>> counted;
  while (!lift_rolls.empty()) {
    auto top = lift_rolls.top();
    lift_rolls.pop();
    int rolls = top.first;
    int i = top.second.first;
    int j = top.second.second;
    if (rolls_blocking[{i, j}] != rolls) {
      continue;
    }
    if (rolls <= 3) {
      counted.insert({i, j});
      for (int d = 0; d < 8; d++) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        if (ni >= 0 && ni < inputs.size() && nj >= 0 && nj < inputs[ni].size()) {
          if((inputs[ni][nj] == '@') && counted.find({ni, nj}) == counted.end()){
            rolls_blocking[{ni, nj}] -= 1;
            lift_rolls.push({rolls_blocking[{ni, nj}], {ni, nj}});
          }
        }
      }
    }
  }
  
  cout << counted.size() << "\n";
  return 0;
}
