#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300009;

char ans[MAXN];
int arr[MAXN];

int main() {
    // cin.tie(0); ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) cin >> arr[i];

    int lft = 0;
    int rgt = N - 1;
    int idans = 0;
    int lst = 0;
    while (1) {
        
        // cout << arr[lft] << ' ' << arr[rgt] << ' ' << lst << '\n';
        if ((arr[lft] < arr[rgt]) && (arr[lft] > lst)){
            ans[idans++] = 'L';
            lst = arr[lft];
            lft++;
        } else if ((arr[lft] > arr[rgt]) && (arr[rgt] > lst)) {
            ans[idans++] = 'R';
            lst = arr[rgt];
            rgt--;
        } else if (arr[lft] > lst) {
            ans[idans++] = 'L';
            lst = arr[lft];
            lft++;
        } else if (arr[rgt] > lst){
            ans[idans++] = 'R';
            lst = arr[rgt];
            rgt--;
        } else {
            break;
        }
        if (lft > rgt) break;
    }

    cout << idans << '\n';
    for (int i = 0; i < idans; ++i) {
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}