#include <iostream>
#include <string>
#include <vector>
using namespace std;

int directions[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool is_valid(vector<string> *inputs, int i, int j) {
  int many_rolls = 0;
  for (int d = 0; d < 8; d++) {
    int ni = i + directions[d][0];
    int nj = j + directions[d][1];
    if (ni >= 0 && ni < (*inputs).size() && nj >= 0 && nj < (*inputs)[ni].size()) {
      if ((*inputs)[ni][nj] == '@') {
        many_rolls++;
        if (many_rolls > 3) {
          return false;
        }
      }
    }
  }
  // cout << "Valid at " << i << "," << j << " with " << many_rolls << " rolls\n";
  return true;
}

int main() {
  string input;
  
  int answer = 0;
  vector<string> inputs;
  while (getline(cin, input)) {
    inputs.push_back(input);
  }
  for (int i = 0; i < inputs.size(); i++){
    for (int j = 0; j < inputs[i].size(); j++){
      if (inputs[i][j] == '@' && is_valid(&inputs, i, j)) {
        answer++;
        // cout << "Counting at " << i << "," << j << "answer:" << answer << "\n";
      }
    }
  }
  
  cout << answer << "\n";
  return 0;
}
