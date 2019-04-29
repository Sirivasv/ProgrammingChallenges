#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 200009;

int arr_a[MAXN], arr_b[MAXN], arr_c[MAXN];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) { cin >> arr_a[i]; }

    set<pii> elmnts_b;
    for(int i = 0; i < N; ++i) {
        cin >> arr_b[i];
        pii elmnt_b;
        elmnt_b.first = arr_b[i];
        elmnt_b.second = i;
        elmnts_b.insert(elmnt_b);
    }

    int lft = 0;
    int rgt = N - 1;

    for (int i = 0; i < N; ++i) {

        auto low = elmnts_b.lower_bound (pii(N - arr_a[i], -1));
        
        if (low != elmnts_b.end()) {
            // cout << low->first << "-22" << ' ';
            // cout << low->second << "-22" << '\n';
            arr_c[i] = (arr_a[i] + low->first) % N;
            elmnts_b.erase(low);
        } else {
            // cout << "Not found\n";
            low = elmnts_b.begin();
            // cout << low->first << "-22" << ' ';
            // cout << low->second << "-22" << '\n';
            arr_c[i] = (arr_a[i] + low->first) % N;
            elmnts_b.erase(low);

        }
        


    }  

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << arr_c[i];
    }
    cout << '\n';

    return 0;
}   