#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> parent;
map<int, pair<long long, long long>> range_map;

int Find(int u) { return ((parent[u] == u)? (u): (parent[u] = Find(parent[u]))); }

void Union(int u, int v) {
	if (Find(u) == Find(v)) return;
	parent[Find(u)] = Find(v);
}

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
  long long answer = 0;
  vector<pair<long long, long long>> ranges;
  while (getline(cin, input)) {
    vector<string> input_parts;
    split(input, input_parts, '-');
    if (input_parts.size() == 2) {
      long long start = stoll(input_parts[0]);
      long long end = stoll(input_parts[1]);
      ranges.push_back({start, end});
    } else {
      continue;
    }
  }
  for (int i = 0; i < ranges.size(); i++) parent.push_back(i);
  
  for (int i = 0; i < ranges.size(); i++) {
    for (int j = i + 1; j < ranges.size(); j++) {
      if (!(ranges[i].second < ranges[j].first || ranges[j].second < ranges[i].first)) {
        Union(i, j);
      }
    }
  }
  for (int i = 0; i < ranges.size(); i++) {
    int p = Find(i);
    if (range_map.find(p) == range_map.end()) {
      range_map[p] = ranges[i];
    } else {
      range_map[p].first = min(range_map[p].first, ranges[i].first);
      range_map[p].second = max(range_map[p].second, ranges[i].second);
    }
  }
  for (const auto &entry : range_map) {
    answer += (entry.second.second - entry.second.first + 1);
  }
  cout << answer << "\n";
  return 0;
}
