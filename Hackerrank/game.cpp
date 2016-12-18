#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        cin >> n;
        priority_queue<pii> Q;
        for (int i = 0; i < n; ++i) {
            int xi;
            cin >> xi;
            Q.push(pii(xi, i));
        }
        int curr_l = n - 1;
        int i;
        for (i = 0; i < n; ++i) {
            if (Q.empty())
                break;
            while (Q.top().second > curr_l)
                Q.pop();
            if (Q.empty())
                break;
            curr_l = Q.top().second;
            Q.pop();
        }
        cout << ((i & 1)?("ANDY\n"):("BOB\n"));
    }
    return 0;
}
