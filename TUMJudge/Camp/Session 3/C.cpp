#include<bits/stdc++.h>   
using namespace std;
const int MAXN = 809;

int vis[MAXN],nxt[MAXN];  

long long gcd(long long a, long long b) {  
    if(a < b)
		return gcd(b, a);
    if(b == 0)  
        return a;  
    return gcd(b,a % b);  
}  

long long lcm(long long a,long long b) {  
    return a / gcd(a, b) * b;  
}  

int main() {  
	cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;  
    while(cin >> n >> m) {
		if (!(n || m))
			break;
        if(n <= m) {  
            cout << "1\n";
            continue;  
        }
		int k = n;
        for(int i = m; i >= 1; --i)
            for(int j = i; j <= n; j += m)
                nxt[k--] = j;
			
        long long ans = 1LL;  
        memset(vis, 0, sizeof(vis));  
        for(int i = 1; i <= n; ++i) {  
            if(vis[i])  
                continue;  
            long long temp = nxt[i] , res = 1LL;  
            while(temp != i) {  
                vis[temp] = 1;  
                temp = nxt[temp];  
                res++;
            }  
            ans = lcm(ans, res);  
        }  
		cout << ans << '\n';
    }  
}  