#include <bits/stdc++.h>
using namespace std;

string s, si, sir;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int limi;
    cin >> limi;
    cin >> s;
    if (limi % 2) {
        cout << ":(\n";
        return 0;
    }
    if (limi == 2) {
        if ((s == "((") || (s == "))") || (s == ")(")) {
            cout << ":(\n";
            return 0;
        }
        cout << "()\n";
        return 0;
    } 

    if (s[0] == '?') s[0] = '(';
    if (s[1] == '?') s[1] = '(';
    if (s[limi - 2] == '?') s[limi - 2] = ')';
    if (s[limi - 1] == '?') s[limi - 1] = ')';
    
    si = s;

    if (!((s[0] == '(') && (s[1] == '(') && (s[limi - 2] == ')') && (s[limi - 1] == ')'))) {
        cout << ":(\n";
        return 0; 
    }

    int cnt = 1;
    int failed_err = 0;
    for (int i = 2; i < (limi - 1); ++i) {
        if (s[i] == '?') {
            si[i] = '(';
            cnt++;
        } else if (s[i] == ')') {
            cnt--;
            if (cnt < 0) {
                failed_err = 1;
                break;
            }
        } else {
            cnt++;
        }
    }
    if (failed_err) {
        cout << ":(\n";
        return 0;
    }

    sir = si;
    for (int i = limi - 3; i >= 2; --i) {
        if (si[i] == '(') {
            if (cnt) {

                if (s[i] == '?') {
                    cnt -= 2;
                    sir[i] = ')';
                } 

            }
        } 
    }
    if (cnt != 0) {
        cout << ":(\n";
        return 0;
    }

    cout << sir << '\n';
    return 0;
}