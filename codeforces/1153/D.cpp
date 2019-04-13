#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300009;

int has_son[MAXN];
int parent[MAXN];
int operation[MAXN];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    for (int i = 0; i < N; ++i) cin >> operation[i];
    int limi = N - 1;
    for (int i = 0; i < limi; ++i) {
        cin >> parent[i];
        parent[i]--;
        has_son[parent[i]] = 1;
    }

    return 0;
}