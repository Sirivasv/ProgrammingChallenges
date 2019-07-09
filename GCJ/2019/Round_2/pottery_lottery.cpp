#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii vases_no[30];

int main() {
    
    int T;
    cin >> T;
    
    for (int case_no = 1; case_no <= T; ++case_no) { 
        int current_vase = 0;
        int selected_vase = 11;
        for (int curr_turn_i = 1; curr_turn_i <= 100; curr_turn_i++) {
            int curr_turn;
            cin >> curr_turn;
            if (curr_turn <= 71) {
                cout << (current_vase + 1) << ' ' << (curr_turn) << endl;
                current_vase++;
                current_vase %= 10;
            } else if ((curr_turn >= 72) && (curr_turn <= 81)){
                int inner_count = curr_turn - 61;
                cout << inner_count << " 0" << endl;
                int inner_N;
                cin >> inner_N;
                vases_no[curr_turn - 72] = pii(inner_N, inner_count);
                int dummy;
                for (int i = 0; i < inner_N; ++i) cin >> dummy;
            } else if ((curr_turn >= 82) && (curr_turn <= 99)) {

                if ((current_vase + 11) == selected_vase) {
                    current_vase++;
                    current_vase %= 10;
                }
                
                cout << (current_vase + 11) << ' ' << (curr_turn) << endl;
                current_vase += 1;
                current_vase %= 10;

            } else if (curr_turn == 100) {
                cout << selected_vase << ' ' << 100 << endl;
            }

            if (curr_turn == 81) {
                sort(vases_no, vases_no + 9);
                selected_vase = vases_no[0].second;
                current_vase = 0;
            }

        }

    }

    return 0;
}