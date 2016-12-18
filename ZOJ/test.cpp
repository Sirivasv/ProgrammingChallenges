 #include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define N 50050
#define INF 999999999

using namespace std;

int n;
int val[N],day[N];
ll dp[N];

struct Que {
    ll val,day;
    bool operator < (const Que &b)const {
        if(val==b.val)return day>b.day;
        return val>b.val;
    }
};

priority_queue<Que>que;

int main() {
    //freopen("test.in","r",stdin);
    //debug();
    while(cin>>n) {
        for(int i=1; i<=n; i++) {
            scanf("%d",&val[i]);
        }
        for(int i=1; i<=n; i++) {
            scanf("%d",&day[i]);
        }
        while(que.size())que.pop();
        Que it;
        for(int i=1; i<=n; i++) {
            it.val=dp[i-1]+val[i],it.day=day[i]+i-1;
            while(que.size()&&que.top().day<i)que.pop();
            que.push(it);
            dp[i]=que.top().val;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}