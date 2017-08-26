#include <bits/stdc++.h>
using namespace std;
int F[1000009];
string s;

void CF() {
    F[0] = -1;
    for (int i = 0, j = -1; s[i]; ) {
        while (~j && s[i] != s[j]) j = F[j];
        F[++i] = ++j;
    }
}

int main (){
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N, k = 1;
    for (; ;) {
        cin >> N;
        if (!N) break;
        cin >> s;
        CF();
        cout << "Test case #" << k++ << '\n';
        for (int i = 2; i <= N; ++i)
            if (F[i] && !(i % (i - F[i])))
                cout << i << ' ' << i / (i - F[i]) << '\n';
        cout << '\n';
    }
    return 0;
}
