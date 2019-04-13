#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ter;

int N, B, F;
int two_pow[] = {1, 2, 4, 8};
string responses[9];
vector<ter> incomplete_groups;
vector<int> broken_machines;

string get_fill_pattern(int ori, int endi, int total) {
    string result = "";
    for (int i = ori; i < endi; ++i) {
        result += '0' + ((i / total) % 2);
    }
    return result;
}

int getID(int pos) {
    int result = 0;
    for (int i = 1; i <= 4; ++i) {
        result += two_pow[i - 1] * (responses[i][pos] - '0');
    }
    return result; 
}

int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    
    int T;
    cin >> T;
    for (int case_no = 1; case_no <= T; ++case_no) {
        cin >> N >> B >> F;
        cout << get_fill_pattern(0, N, 16) << endl;
        cin >> responses[0];
        cout << get_fill_pattern(0, N, 1) << endl;
        cin >> responses[1];
        cout << get_fill_pattern(0, N, 2) << endl;
        cin >> responses[2];
        cout << get_fill_pattern(0, N, 4) << endl;
        cin >> responses[3];
        cout << get_fill_pattern(0, N, 8) << endl;
        cin >> responses[4];
        // cout << "****\n";
        // for (int i = 0; i <= 4; ++i) {
        //     cout << responses[i] << '\n';
        // }
        incomplete_groups.clear();
        broken_machines.clear();

        int limRspns = responses[0].length();
        int group_start = 0;
        int current_group_block = 0;
        int last_pattern = '0';
        int current_size = 0;
        for (int i = 0; i < limRspns; ++i) {
            if (responses[0][i] != last_pattern) {
                if (current_size != 16) {
                    incomplete_groups.push_back(ter(current_group_block, pii(group_start, i - 1)));
                }
                current_size = 1;
                last_pattern = responses[0][i];
                group_start = i;
                current_group_block++;
            } else {
                current_size++;
            }
        }
        if (current_size != 16) {
            incomplete_groups.push_back(ter(current_group_block, pii(group_start, limRspns - 1)));
        }

        int limInc = incomplete_groups.size();
        for (int i = 0; i < limInc; ++i) {
            // cout << "A: " << incomplete_groups[i].first << " B: " << incomplete_groups[i].second.first << " C: " << incomplete_groups[i].second.second << '\n';
            map<int, int> mp_seen;
            for (int j = incomplete_groups[i].second.first; j <= incomplete_groups[i].second.second; ++j) {
                // cout << getID(j) << '\n';
                mp_seen[getID(j)] = 1;
            }
            for (int j = 0; j < 16; ++j) {
                if (!mp_seen.count(j)) {
                    int broken_id = (incomplete_groups[i].first * 16) + j;
                    if (broken_id < N) {
                        broken_machines.push_back(broken_id);
                    } 
                }
            }
        }

        int limBM = broken_machines.size();
        string rest= "";
        for (int i = 0; i < limBM; ++i) {
            if (i) rest += " ";
            rest += to_string(broken_machines[i]);
        }
        cout << rest << endl;
        int response;
        cin >> response;
        if (response == -1) {return 0;}

    }
    return 0;
} 