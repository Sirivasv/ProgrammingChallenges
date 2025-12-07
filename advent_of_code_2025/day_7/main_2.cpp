#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
long long answer = 0ll;
vector<string> inputs;
vector<vector<long long>> timelines;
vector<vector<bool>> visited;

long long timelines_search(int i, int j) {
  if (i == inputs.size() - 1) return timelines[i][j] = 1ll;
  
  long long current_timelines = 0ll;
  if (inputs[i][j] == '^') {
      int spi_1 = i + 1;
      int spi_2 = i + 1;

      int spj_1 = j - 1;
      int spj_2 = j + 1;

      if (spi_1 >= 0 && spi_1 < inputs.size() && spj_1 >= 0 && spj_1 < inputs[spi_1].size()) {
        if (!visited[spi_1][spj_1]) {
          visited[spi_1][spj_1] = true;
          current_timelines += timelines_search(spi_1, spj_1);
        } else {
          current_timelines += timelines[spi_1][spj_1];
        }
      }
      if (spi_2 >= 0 && spi_2 < inputs.size() && spj_2 >= 0 && spj_2 < inputs[spi_2].size()) {
        if (!visited[spi_2][spj_2]) {
          visited[spi_2][spj_2] = true;
          current_timelines += timelines_search(spi_2, spj_2);
        } else {
          current_timelines += timelines[spi_2][spj_2];
        }
      }
    } else {
      int ni = i + 1;
      int nj = j;
      if (ni >= 0 && ni < inputs.size() && nj >= 0 && nj < inputs[ni].size()) {
        if (!visited[ni][nj]) {
          visited[ni][nj] = true;
          current_timelines += timelines_search(ni, nj);
        } else {
          current_timelines += timelines[ni][nj];
        }
      }
    }
    return timelines[i][j] = current_timelines;
}

int main() {

  while (getline(cin, input)) {
    inputs.push_back(input);
    timelines.push_back(vector<long long>(input.size(), 0ll));
    visited.push_back(vector<bool>(input.size(), false));
  }

  for (int i = inputs.size()-1; i >= 0; i--){
    int found_s = false;
    for (int j = 0; j < inputs[i].size(); j++){
      if (inputs[i][j] == 'S') {
        visited[i][j] = true;
        answer = timelines_search(i, j);
        found_s = true;
        break;
      }
    }
    if (found_s) break;
  }

  cout << answer << "\n";
  return 0;
}
