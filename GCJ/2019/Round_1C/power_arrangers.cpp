#include <bits/stdc++.h>
using namespace std;

int seen_last_letter[50];
int main() {
    
    int T, F;
    cin >> T;
    cin >> F;
    for (int case_no = 1; case_no <= T; ++case_no) {
        
        
        string missing_set = "";

        map< char, vector<int> > seen_in_column[9];
        map<int, char> frequency_per_letter;
        int repeated_frequency;
        char curr_char;
        
        //******************* 1 ***********************

        for (int row = 1; row <= 119; ++row) { // Asks for the first row
            int figure_to_look = ((row - 1) * 5) + 1;
            cout << figure_to_look << endl;
            
            char letter_in_figure;
            cin >> letter_in_figure;
            seen_in_column[1][letter_in_figure].push_back(row);
        }

        frequency_per_letter.clear();
        repeated_frequency = 0;
        for (auto it : seen_in_column[1]) {
            if (frequency_per_letter.count(it.second.size())) repeated_frequency = it.second.size();
            frequency_per_letter[it.second.size()] = it.first;
        }
        for (auto it : frequency_per_letter) {
            if (it.first == repeated_frequency) continue;
            missing_set += it.second;
        }

        //******************* 2 ***********************
        curr_char = missing_set[0];
        for (auto it: seen_in_column[1][curr_char]) {
            int figure_to_look = ((it - 1) * 5) + 2;
            cout << figure_to_look << endl;
            
            char letter_in_figure;
            cin >> letter_in_figure;
            seen_in_column[2][letter_in_figure].push_back(it);
        }

        frequency_per_letter.clear();
        repeated_frequency = 0;
        for (auto it : seen_in_column[2]) {
            if (frequency_per_letter.count(it.second.size())) repeated_frequency = it.second.size();
            frequency_per_letter[it.second.size()] = it.first;
        }
        for (auto it : frequency_per_letter) {
            if (it.first == repeated_frequency) continue;
            missing_set += it.second;
        }

        //******************* 3 ***********************
        curr_char = missing_set[1];
        for (auto it: seen_in_column[2][curr_char]) {
            int figure_to_look = ((it - 1) * 5) + 3;
            cout << figure_to_look << endl;
            
            char letter_in_figure;
            cin >> letter_in_figure;
            seen_in_column[3][letter_in_figure].push_back(it);
        }

        frequency_per_letter.clear();
        repeated_frequency = 0;
        for (auto it : seen_in_column[3]) {
            if (frequency_per_letter.count(it.second.size())) repeated_frequency = it.second.size();
            frequency_per_letter[it.second.size()] = it.first;
        }
        for (auto it : frequency_per_letter) {
            if (it.first == repeated_frequency) continue;
            missing_set += it.second;
        }
        
        //******************* 4 ***********************
        curr_char = missing_set[2];
        for (auto it: seen_in_column[3][curr_char]) {
            int figure_to_look = ((it - 1) * 5) + 4;
            cout << figure_to_look << endl;
            
            char letter_in_figure_fifth;
            cin >> letter_in_figure_fifth;

            figure_to_look = ((it - 1) * 5) + 5;
            cout << figure_to_look << endl;

            char letter_in_figure_fourth;
            cin >> letter_in_figure_fourth;

            missing_set += letter_in_figure_fourth;
            missing_set += letter_in_figure_fifth;
            break;
        }

        cout << missing_set << endl;
        char response;
        cin >> response;
        if (response == 'N') {return 0;}
    }

    return 0;
} 