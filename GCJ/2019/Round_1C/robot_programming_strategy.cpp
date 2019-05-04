#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;

string matches[MAXN];
int can_win[MAXN];
int seen_letters[50];
int N;

int always_win(const string& strategy) {

    for (int j = 0; j < N; ++j) {
        can_win[j] = 0;
    }

    int at_least_one_lost = 0;
    for (int i = 0; i < 260000; ++i) {
        int no_more_matches = 1;
        seen_letters['R' - 'A'] = 0;
        seen_letters['S' - 'A'] = 0;
        seen_letters['P' - 'A'] = 0;

        int curr_w = i;
        if (curr_w >= strategy.size()) curr_w = i % strategy.size();

        for (int j = 0; j < N; ++j) {
            if (can_win[j]) continue;
            
            int curr_i = i;
            if (curr_i >= matches[j].size()) curr_i = i % matches[j].size();
            
            no_more_matches = 0;
            if ((matches[j][curr_i] == 'R') && (strategy[curr_w] == 'P')) can_win[j] = 1;
            if ((matches[j][curr_i] == 'P') && (strategy[curr_w] == 'S')) can_win[j] = 1;
            if ((matches[j][curr_i] == 'S') && (strategy[curr_w] == 'R')) can_win[j] = 1;
        }

        if (no_more_matches) {
            return 1;
        }
        if ((seen_letters['R' - 'A'] == 1) && (seen_letters['P' - 'A'] == 0) && (seen_letters['S' - 'A'] == 0)) {
            if (strategy[curr_w] == 'S') at_least_one_lost = 1;
            else if (strategy[curr_w] == 'P'){
                return 1;
            }
        }
        if ((seen_letters['S' - 'A'] == 1) && (seen_letters['P' - 'A'] == 0) && (seen_letters['R' - 'A'] == 0)) {
            if (strategy[curr_w] != 'P') at_least_one_lost = 1;
            else if (strategy[curr_w] == 'R'){
                return 1;
            }
        }
        if ((seen_letters['P' - 'A'] == 1) && (seen_letters['R' - 'A'] == 0) && (seen_letters['S' - 'A'] == 0)) {
            if (strategy[curr_w] != 'R') at_least_one_lost = 1;
            else if (strategy[curr_w] == 'S'){
                return 1;
            }
        }
        if ((seen_letters['P' - 'A'] == 1) && (seen_letters['R' - 'A'] == 1) && (seen_letters['S' - 'A'] == 1)) {
            at_least_one_lost = 1;
            break;
        }
        if ((seen_letters['R' - 'A'] == 1) && (seen_letters['P' - 'A'] == 1)) {
            if (strategy[curr_w] != 'P') at_least_one_lost = 1; 
        } else if ((seen_letters['S' - 'A'] == 1) && (seen_letters['P' - 'A'] == 1)) {
            if (strategy[curr_w] != 'S') at_least_one_lost = 1;
        } else if ((seen_letters['S' - 'A'] == 1) && (seen_letters['R' - 'A'] == 1)) {
            if (strategy[curr_w] != 'R') at_least_one_lost = 1;
        }

        if (at_least_one_lost) return 0;

    }
    return 0;
} 

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    for (int nc = 1; nc <= T; ++nc) {

        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> matches[i];
            can_win[i] = 0;
        }

        int at_least_one_lost = 0;
        string winning_strategy = "";
        for (int i = 0; i < 500; ++i) {

            int no_more_matches = 1;
            seen_letters['R' - 'A'] = 0;
            seen_letters['S' - 'A'] = 0;
            seen_letters['P' - 'A'] = 0;
            for (int j = 0; j < N; ++j) {
                if (can_win[j]) continue;
                int curr_i = i;
                if (curr_i >= matches[j].size()) curr_i = i % matches[j].size();
                no_more_matches = 0;
                seen_letters[matches[j][curr_i] - 'A'] = 1;
            }
            if (no_more_matches) break;
            if ((seen_letters['R' - 'A'] == 1) && (seen_letters['P' - 'A'] == 0) && (seen_letters['S' - 'A'] == 0)) {
                winning_strategy += "P";
                break;
            }
            if ((seen_letters['S' - 'A'] == 1) && (seen_letters['P' - 'A'] == 0) && (seen_letters['R' - 'A'] == 0)) {
                winning_strategy += "R";
                break;
            }
            if ((seen_letters['P' - 'A'] == 1) && (seen_letters['R' - 'A'] == 0) && (seen_letters['S' - 'A'] == 0)) {
                winning_strategy += "S";
                break;
            }
            if ((seen_letters['P' - 'A'] == 1) && (seen_letters['R' - 'A'] == 1) && (seen_letters['S' - 'A'] == 1)) {
                at_least_one_lost = 1;
                break;
            }
            if ((seen_letters['R' - 'A'] == 1) && (seen_letters['P' - 'A'] == 1)) {
                winning_strategy += "P";   
            } else if ((seen_letters['S' - 'A'] == 1) && (seen_letters['P' - 'A'] == 1)) {
                winning_strategy += "S";
            } else if ((seen_letters['S' - 'A'] == 1) && (seen_letters['R' - 'A'] == 1)) {
                winning_strategy += "R";
            }

            for (int j = 0; j < N; ++j) {
                if (at_least_one_lost) continue;
                if (can_win[j]) continue;
                int curr_i = i;
                if (curr_i >= matches[j].size()) curr_i = i % matches[j].size();
                if ((matches[j][curr_i] == 'R') && (winning_strategy[i] == 'P')) can_win[j] = 1;
                if ((matches[j][curr_i] == 'P') && (winning_strategy[i] == 'S')) can_win[j] = 1;
                if ((matches[j][curr_i] == 'S') && (winning_strategy[i] == 'R')) can_win[j] = 1;
            }

        }
        if ((at_least_one_lost) || (!always_win(winning_strategy))) {
            cout << "Case #" << nc << ": IMPOSSIBLE\n";
            continue;
        } else {
            cout << "Case #" << nc << ": " << winning_strategy << '\n';
        } 

    }

    return 0;
}