#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;

ll A[MAXN];

struct SegTree{
	
    ll data;
    int L, R;
    SegTree* left;
    SegTree* right;
    SegTree(int l, int r)
    : data(0), L(l), R(r),
    left(NULL), right(NULL){ }
	
    void Build() {
        if (L < R) {
            int m = (L + R)/2;
            left = new SegTree(L, m);
            right = new SegTree(m +1, R);
            left->Build(); right->Build();
            data = left->data + right->data;
        }
        else data = A[L];
    }

    ll Query(int l, int r){
        if((R < l) || (r < L)) return 0;
        if((l <= L) && (R <= r)) return data;
        ll vleft = left->Query(l, r);
        ll vright = right->Query(l, r);
        return  vleft + vright;
    }
	
};

int main() {
    int N, T, Q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&Q);
        SegTree St(1, N);
        for(int i = 1; i <= N; i++)
           scanf("%lld",&A[i]);
        St.Build();
        int a, b;
        for(int i = 0; i < Q; i ++){
            scanf("%d%d",&a,&b);
            printf("%lld\n",St.Query(a + 1, b + 1));
        }
        if((T - 1) >= 0)
            printf("\n");
    }
    return 0;
}

