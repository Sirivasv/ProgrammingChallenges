#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 150009; 

map<char, stack<int>> chars_seen_a, chars_seen_b;
vector<pii> boot_pairs;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
    string a, b;
    cin >> n >> a >> b;
    
    for (int i = 0; i < n; ++i) {
        chars_seen_a[a[i]].push(i + 1); chars_seen_b[b[i]].push(i + 1);
    }

    for (auto it = chars_seen_a.begin(); it != chars_seen_a.end(); it++) {
                
        if (it->first == '?') continue;

        while ((!chars_seen_a[it->first].empty()) && (!chars_seen_b[it->first].empty())) {

            int lb = chars_seen_a[it->first].top();
            int rb = chars_seen_b[it->first].top();
            chars_seen_a[it->first].pop(); chars_seen_b[it->first].pop();

            boot_pairs.push_back(pii(lb, rb));

        }

        while ((!chars_seen_a[it->first].empty()) && (!chars_seen_b['?'].empty())) {

            int lb = chars_seen_a[it->first].top();
            int rb = chars_seen_b['?'].top();
            chars_seen_a[it->first].pop(); chars_seen_b['?'].pop();

            boot_pairs.push_back(pii(lb, rb));

        }

        while ((!chars_seen_a['?'].empty()) && (!chars_seen_b[it->first].empty())) {

            int lb = chars_seen_a['?'].top();
            int rb = chars_seen_b[it->first].top();
            chars_seen_a['?'].pop(); chars_seen_b[it->first].pop();

            boot_pairs.push_back(pii(lb, rb));

        }

    }

    for (auto it = chars_seen_b.begin(); it != chars_seen_b.end(); it++) {
                
        if (it->first == '?') continue;

        while ((!chars_seen_a[it->first].empty()) && (!chars_seen_b[it->first].empty())) {

            int lb = chars_seen_a[it->first].top();
            int rb = chars_seen_b[it->first].top();
            chars_seen_a[it->first].pop(); chars_seen_b[it->first].pop();

            boot_pairs.push_back(pii(lb, rb));

        }

        while ((!chars_seen_a[it->first].empty()) && (!chars_seen_b['?'].empty())) {

            int lb = chars_seen_a[it->first].top();
            int rb = chars_seen_b['?'].top();
            chars_seen_a[it->first].pop(); chars_seen_b['?'].pop();

            boot_pairs.push_back(pii(lb, rb));

        }

        while ((!chars_seen_a['?'].empty()) && (!chars_seen_b[it->first].empty())) {

            int lb = chars_seen_a['?'].top();
            int rb = chars_seen_b[it->first].top();
            chars_seen_a['?'].pop(); chars_seen_b[it->first].pop();

            boot_pairs.push_back(pii(lb, rb));

        }

    }

    while ((!chars_seen_a['?'].empty()) && (!chars_seen_b['?'].empty())) {

        int lb = chars_seen_a['?'].top();
        int rb = chars_seen_b['?'].top();
        chars_seen_a['?'].pop(); chars_seen_b['?'].pop();

        boot_pairs.push_back(pii(lb, rb));

    }
    
    int lim = boot_pairs.size();
    cout << lim << '\n';
    for (int i = 0; i < lim; ++i) {
        cout << boot_pairs[i].first << ' ' << boot_pairs[i].second << '\n';
    }

    return 0;
}