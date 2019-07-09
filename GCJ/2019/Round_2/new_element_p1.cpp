#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;
typedef pair<pii, pii> ter;

const int MAXN = 10;

ter arr[MAXN];
int nsq[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
set<string> seqs;
int N;

int is_valid_arr() {

    lli last1 = -1;
    lli last2 = -1;
    lli last3 = -1;
    int ok1 = 1;
    int ok2 = 1;
    int ok3 = 1;
    string s;
    
    for (int i = 0; i < N; ++i) {
        
         
        lli curr1 = arr[nsq[i]].second.first + arr[nsq[i]].second.second;
        
        
        
        
        lli curr2 = (arr[nsq[i]].second.first * 2LL) + arr[nsq[i]].second.second;
        
        
        
        lli curr3 = arr[nsq[i]].second.first + (arr[nsq[i]].second.second * 2LL);
        
    
        
        if (curr1 <= last1) {
            ok1 = 0;
        }
        if (curr2 <= last2) {
            ok2 = 0;
        }
        if (curr3 <= last3) {
            ok3 = 0;
        }

        last1 = curr1;
        last2 = curr2;
        last3 = curr3;
        s += ('A' + arr[nsq[i]].first.second);
    }
    if (ok1 || ok2 || ok3) seqs.insert(s);
    return 1;

}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int case_no = 1; case_no <= T; ++case_no) {
        cin >> N;
        seqs.clear();
        for (int i = 0; i < N; ++i) {
            cin >> arr[i].second.first >> arr[i].second.second;
            arr[i].first.first = arr[i].second.first + arr[i].second.second;
            arr[i].first.second = i;
        }
        sort(arr, arr + N);
        do {    
            is_valid_arr();
        } while(next_permutation(nsq, nsq + N));
    
        cout << "Case #" << case_no << ": " << seqs.size() << '\n';

    }
    return 0;
}