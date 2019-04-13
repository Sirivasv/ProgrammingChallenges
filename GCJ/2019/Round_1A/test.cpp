#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, string> pis;

const int MAXN = 1009;

struct Cuart {
    int i;
    int j;
    string suff; 
    int mn;
    Cuart(int _i, int _j, int _mn, const string &_suff) : i(_i), j(_j), mn(_mn), suff(_suff) {}
    Cuart() {}
    bool operator<(Cuart const &r) const { return mn < r.mn; } 
};

Cuart couples[MAXN * MAXN];
string alien_word[MAXN];
int selected[MAXN];
unordered_map<string, int> selected_suff;



Cuart try_match(int xi, int xj) {
    int limi = min(alien_word[xi].length(), alien_word[xj].length());
    string curr_match = "";
    int mn = 0;
    for (int i = 0; i < limi; ++i) {
        if (alien_word[xi][i] != alien_word[xj][i]) break;
        curr_match += alien_word[xi][i];
        mn++;
    }
    return Cuart(xi, xj, mn, curr_match);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int total_cases;
    cin >> total_cases;
    for (int no_case = 1; no_case <= total_cases; ++no_case) {

        int N;
        cin >> N;
        int couples_no = 0;
        selected_suff.clear();
        for (int i = 0; i < N; ++i) {
            cin >> alien_word[i];
            reverse(alien_word[i].begin(), alien_word[i].end());
            selected[i] = 0;
            for (int j = 0; j < i; ++j) {
                couples[couples_no++] = try_match(i, j);
            }
        }
        sort(couples, couples + couples_no);

        // for (int i = 0; i < couples_no; ++i) {
        //     cout << "************\n";
        //     cout << "Couple i: " << couples[i].i << " j: " << couples[i].j << '\n';
        //     cout << "------>    " << alien_word[couples[i].i] << " " << alien_word[couples[i].j] << '\n';
        //     cout << "------>    " << couples[i].mn << " ->" << couples[i].suff << "<-\n";
        // }
        // cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        int ans = 0;
        for (int i = couples_no - 1; i >= 0; --i) {
            if (couples[i].mn == 0) continue;
            if (selected[couples[i].i] || selected[couples[i].j]) continue;
            if (selected_suff.count(couples[i].suff)) continue;
            ans++;
            selected_suff[couples[i].suff] = 1;
            selected[couples[i].i] = 1;
            selected[couples[i].j] = 1;
        }
        ans <<= 1;
        cout << "Case #" << no_case << ": " << ans << '\n';

    }

    return 0;
}