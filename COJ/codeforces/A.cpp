#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int mtr[MAXN][MAXN];
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int disp = A * B - N;
    if (disp < 0) {
        cout << "-1\n";
        return 0;
    }
    int x_ = 1, y_ = 1, imp = 1, p = 2, cnt = 1;
    int NN = N;
    while (N) {
        cout << "imp " << y_ << " " << x_ << " " << mtr[y_ - 1][x_] << '\n';  
        if (mtr[y_ - 1][x_] == 0) {
            mtr[y_][x_] = min(imp, p);
            if (imp < p) imp += 2;
            else p += 2;
            N--;
        } else if (mtr[y_ - 1][x_]  % 2) {
            if (p <= NN) { 
                mtr[y_][x_] = p;
                p += 2;
                N--;
            } else mtr[y_][x_] = 0;
        } else {
            if (imp <= NN) { 
                mtr[y_][x_] = imp;
                imp += 2;
                N--;
            } else mtr[y_][x_] = 0;
        }
        x_++;
        x_ %= (B + 1);
        if (!x_) x_ = 1;
        if (x_ == 1) y_++;
    }
    int mats = 0;
    for (int i = 1; i <= A; ++i) 
        for (int j = 1; j <= B; ++j) mats = max(mats, mtr[i][j]);
    if (NN != mats) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= A; ++i) {
        for (int j = 1; j <= B; ++j) cout << mtr[i][j];
        cout << '\n';
    }
    return 0;
}