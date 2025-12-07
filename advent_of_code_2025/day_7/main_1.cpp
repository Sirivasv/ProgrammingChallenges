#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string input;
  
  int answer = 0;
  vector<string> inputs;
  vector<vector<bool>> visited;
  while (getline(cin, input)) {
    inputs.push_back(input);
    visited.push_back(vector<bool>(input.size(), false));
  }
  queue<pair<int, int>> to_visit;

  for (int i = 0; i < inputs.size(); i++){
    for (int j = 0; j < inputs[i].size(); j++){
      if (inputs[i][j] == 'S') {
        to_visit.push({i, j});
        visited[i][j] = true;
        break;
      }
    }
  }
  while(!to_visit.empty()) {
    auto current = to_visit.front();
    to_visit.pop();
    int i = current.first;
    int j = current.second;

    if (inputs[i][j] == '^') {
      answer++;
      int spi_1 = i + 1;
      int spi_2 = i + 1;

      int spj_1 = j - 1;
      int spj_2 = j + 1;

      if (spi_1 >= 0 && spi_1 < inputs.size() && spj_1 >= 0 && spj_1 < inputs[spi_1].size() && !visited[spi_1][spj_1]) {
        to_visit.push({spi_1, spj_1});
        visited[spi_1][spj_1] = true;
      }
      if (spi_2 >= 0 && spi_2 < inputs.size() && spj_2 >= 0 && spj_2 < inputs[spi_2].size() && !visited[spi_2][spj_2]) {
        to_visit.push({spi_2, spj_2});
        visited[spi_2][spj_2] = true;
      }
    } else {
      int ni = i + 1;
      int nj = j;
      if (ni >= 0 && ni < inputs.size() && nj >= 0 && nj < inputs[ni].size() && !visited[ni][nj]) {
        to_visit.push({ni, nj});
        visited[ni][nj] = true;
      }
    }
  }
  
  cout << answer << "\n";
  return 0;
}
