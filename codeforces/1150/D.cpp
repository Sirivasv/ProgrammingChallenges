#include <bits/stdc++.h>
using namespace std;

set<int> arr[50];
string rd[5];
int tkn_rd[5][300];
int tkn_id[5];

void restore_universe() {

    for (int i = 1; i <= 3; ++i) {
        int limit = tkn_id[i];
        tkn_id[i] = 0;
        for (int j = 0; j < limit; ++j) {
            arr[rd[i][j] - 'a'].insert(tkn_rd[i][j]);
        }
    }


}

int order_nw[] = {1, 2, 3};

int check_descs() {
    cout << "++++++++++++++++++++++++++++++++\n";
    order_nw[0] = 1;
    order_nw[1] = 2;
    order_nw[2] = 3;
    int found = 0;
    int cnt = 0;
    do {
        cnt++;
        cout << cnt << ' ' << order_nw[0] << ' ' << order_nw[1] << ' ' << order_nw[2] << '\n';
        int innr_flg = 1;
        for (int i = 0; (i < 3) && innr_flg; ++i) {
            int curr_id = order_nw[i];
            int limit = rd[curr_id].size();
            cout << "chk2 - " << rd[curr_id] << '\n';
            int lst_id = 0;
            for (int j = 0; (j < limit) && innr_flg; ++j) {
                auto it = arr[rd[curr_id][j] - 'a'].lower_bound(lst_id);
                if (it == arr[rd[curr_id][j] - 'a'].end()) {
                    restore_universe();
                    innr_flg = 0;
                    continue;
                }
                tkn_rd[curr_id][tkn_id[curr_id]++] = *it;
                arr[rd[curr_id][j] - 'a'].erase(it);
                lst_id = *it;
            }
        }
        restore_universe();
        if (innr_flg) {
            found = 1;
            break;
        }
    } while (next_permutation(order_nw, order_nw + 3));
    return found;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
   
    int N, Q;
    cin >> N >> Q;
    
    string s;
    cin >> s;
    int limit = s.size();
    for (int i = 0; i < limit; ++i) { arr[s[i] - 'a'].insert(i); }

    for (int i = 0; i < Q; ++i) {
        char op;
        int rs;
        char appnd;

        cin >> op;
        if (op == '+') {
            cin >> rs >> appnd;
            rd[rs] += appnd;
        } else {
            cin >> rs;
            rd[rs].pop_back();
        }
        if (!check_descs()) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}