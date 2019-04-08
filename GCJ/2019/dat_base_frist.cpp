#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ter;

int N, B, F;
int two_pow[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
string responses[15];
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
    for (int i = 0; i < 10; ++i) {
        result += two_pow[i] * (responses[i][pos] - '0');
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
        cout << get_fill_pattern(0, N, 1) << endl;
        cin >> responses[0];
        cout << get_fill_pattern(0, N, 2) << endl;
        cin >> responses[1];
        cout << get_fill_pattern(0, N, 4) << endl;
        cin >> responses[2];
        cout << get_fill_pattern(0, N, 8) << endl;
        cin >> responses[3];
        cout << get_fill_pattern(0, N, 16) << endl;
        cin >> responses[4];
        cout << get_fill_pattern(0, N, 32) << endl;
        cin >> responses[5];
        cout << get_fill_pattern(0, N, 64) << endl;
        cin >> responses[6];
        cout << get_fill_pattern(0, N, 128) << endl;
        cin >> responses[7];
        cout << get_fill_pattern(0, N, 256) << endl;
        cin >> responses[8];
        cout << get_fill_pattern(0, N, 512) << endl;
        cin >> responses[9];
        
        map<int, int> mp_seen;
        int limRsp = responses[0].length();
        for (int j = 0; j < limRsp; ++j) {
            mp_seen[getID(j)] = 1;
        }

        int cnt = 0;
        for (int j = 0; j < 1024; ++j) {
            if (j == N) {
                break;
            }
            if (!mp_seen.count(j)) {
               if (cnt) cout << ' '; 
               cout << j;
            }
        }
        cout << endl;
        int response;
        cin >> response;
        if (response == -1) {return 0;}

    }
    return 0;
} 