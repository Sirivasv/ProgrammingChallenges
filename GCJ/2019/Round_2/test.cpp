#include <bits/stdc++.h>
using namespace std;

char arr[] = {'A', 'B', 'C', 'D', 'E'};

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int cnt = 0;
    do {

        for (auto it : arr) {
            cout << it;
        }
        cnt++;
        cout << ' ' << cnt << '\n';

    } while(next_permutation(arr, arr + 5));
    return 0;
}