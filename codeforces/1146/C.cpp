#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int T;
    cin >> T;

    for (int case_no = 0; case_no < T; ++case_no) {
        int N;
        cin >> N;

        if (N == 1) {
            cout << "-1 0" << endl;
            continue;
        }

        string list_str;
        
        list_str = "";
        for (int i = 2; i <= N; ++i) {
            list_str += " " + to_string(i);
        }

        cout << "1 " << N - 1 << " 1" << list_str << endl;

        int mats_frst;
        cin >> mats_frst;
        // cout << mats_frst << "**\n";

        if (N == 2) {
            cout << "-1 " << mats_frst << endl;
            continue;
        }

        int frst = 2, lst = N, ans = 1;
        while (frst <= lst) {
            int mid = (frst + lst) >> 1;
            // cout << frst << ' ' << mid << ' ' << lst << " **\n";
            int mnask = 0;
            list_str = "";    
            for (int i = frst; i <= mid; ++i) {
                list_str += " " + to_string(i);
                mnask++;
            }
            cout << "1 " << mnask << " 1" << list_str << endl;
            int matq;
            cin >> matq;
            if (matq == mats_frst) {
                ans = mid;
                lst = mid - 1;
            } else {
                frst = mid + 1;
            }
        }

        list_str = "";
        for (int i = 1; i <= N; ++i) {
            if (i == ans) continue;
            list_str += " " + to_string(i);
        }
        cout << "1 " << (N - 1) << " " << ans << list_str << endl;
        int matlst;
        cin >> matlst;
        cout << "-1 " << matlst << endl; 


    }

    return 0;
}