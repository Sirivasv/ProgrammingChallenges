#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    long long T;
    cin >> N >> T;
    long long marked = 0, first_to_appear = 1000000009LL;
    for (int i = 0; i < N; ++i) {

        long long si, di;
        cin >> si >> di;
        for (long long j = si;;) {
            if (j >= T) {
                if (j < first_to_appear) {
                    marked = i + 1;
                    first_to_appear = j;
                }
                break;
            }
            j += di;
        }
    }

    cout << marked << '\n';

    return 0;
}