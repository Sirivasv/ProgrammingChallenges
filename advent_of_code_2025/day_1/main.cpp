#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;

  short int dial = 50;
  
  int answer = 0;

  while (getline(cin, input)) {

    bool is_minus = (input[0] == 'L');
    short int value = stoi(input.substr(1, input.size() - 1));
    short int pre_dial = dial;
    cout << "Value: " << value << "\n";

    while (value >= 100) {
      value -= 100;
      answer++;
    }
    if (is_minus) {
      dial -= value;
    } else {
      dial += value;
    }
    cout << "Dial: " << dial << "\n";

    if (dial <= 0) {
      if (pre_dial > 0) answer++;
    } else if (dial > 99) {
      if (pre_dial <= 99) answer++;
    }
    cout << "Answer: " << answer << "\n";
    dial = (dial + 100) % 100;
    cout << "Normalized Dial: " << dial << "\n";
    cout << "----\n";
  }
  cout << answer << "\n";
  return 0;
}
