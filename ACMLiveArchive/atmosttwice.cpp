#include<bits/stdc++.h>
using namespace std;
int dig[15];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string N;
    while (cin >> N) {
        for (int i = 0; i < 10; ++i) dig[i] = 0;
        int id = 0;
        int lim = N.size();
        string ns = N;
        int furthest = 0;
        while (id < lim) {
            if ((dig[N[id] - '0']) <= 1) {
                ns[id] = N[id];
                dig[N[id] - '0']++;
            } else {
                int j = N[id] - '0';
                while ((j >= 0) && (dig[j] == 2)) j--;
                if (j == -1) {
                    j = id;
                    while (id >= 0) {
                        if (N[id] - '0' - 1 < 0) {
                            id--;
                            dig[N[id] - '0']--;
                            continue;
                        } else {
                            int k =(N[id] - '0') - 1;
                            while (k >= 0) {
                                if(dig[k] < 2) {
                                    dig[k]++;
                                    ns[id] = k  + '0';
                                    break;
                                }
                                k--;
                            }
                            if (k < 0) {
                                id--;
                                dig[(N[id] - '0')]--;
                                continue;
                            }
                            break;
                        }
                    }
                } else { 
                    ns[id] = ((char)j) + '0';
                    dig[j]++;
                }
                break;
            }
            id++;
        }
        for (int i = 0; i <= min(id, lim - 1); ++i) {
            if ((!i) && (ns[i] == '0'))continue;
            cout << ns[i];
        }
        int digi = 9;
        for (int i = id + 1; i < lim; ++i) {
            while (dig[digi] == 2) digi--;
            cout << digi;
            dig[digi]++;
        }
        cout << '\n';
    }
}