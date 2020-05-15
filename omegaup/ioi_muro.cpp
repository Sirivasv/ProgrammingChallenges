#include <bits/stdc++.h>
using namespace std;
const int SIZE = (1<<22)+5;

int mint[SIZE], mat[SIZE];
int N, K;

inline void Updatemint(int a, int b, int v, int n, int L, int R)
{
    if(L > b || R < a) return;
    if(L >= a && R <= b){
        mint[n] = min(mint[n], v);
        mat[n] = min(mat[n], v);
        return;
    }

    mint[2*n] = min(mint[2*n], mint[n]);
    mint[2*n] = max(mint[2*n], mat[n]);
    mat[2*n] = max(mat[2*n], mat[n]);
    mat[2*n] = min(mat[2*n], mint[n]);

    mint[2*n + 1] = min(mint[2*n + 1], mint[n]);
    mint[2*n + 1] = max(mint[2*n + 1], mat[n]);
    mat[2*n + 1] = max(mat[2*n + 1], mat[n]);
    mat[2*n + 1] = min(mat[2*n + 1], mint[n]);

    mint[n] = 2000001, mat[n] = 0;

    int mid = (L + R)/2;
    Updatemint(a, b, v, 2*n, L, mid);
    Updatemint(a, b, v, 2*n + 1, mid + 1, R);
}

inline void Updatemat(int a, int b, int v, int n, int L, int R)
{
    if(L > b || R < a) return;
    if(L >= a && R <= b){
        mint[n] = max(mint[n], v);
        mat[n] = max(mat[n], v);
        return;
    }

    mint[2*n] = min(mint[2*n], mint[n]);
    mint[2*n] = max(mint[2*n], mat[n]);
    mat[2*n] = max(mat[2*n], mat[n]);
    mat[2*n] = min(mat[2*n], mint[n]);

    mint[2*n + 1] = min(mint[2*n + 1], mint[n]);
    mint[2*n + 1] = max(mint[2*n + 1], mat[n]);
    mat[2*n + 1] = max(mat[2*n + 1], mat[n]);
    mat[2*n + 1] = min(mat[2*n + 1], mint[n]);

    mint[n] = 2000001 , mat[n] = 0;

    int mid = (L + R)/2;
    Updatemat(a, b, v, 2*n, L, mid);
    Updatemat(a, b, v, 2*n + 1, mid + 1, R);
}

inline void Query()
{
    for(int i = 1; i < (1 << 21) - 1; i++){
        mint[2*i] = min(mint[2*i], mint[i]);
        mint[2*i] = max(mint[2*i], mat[i]);
        mat[2*i] = max(mat[2*i], mat[i]);
        mat[2*i] = min(mat[2*i], mint[i]);

        mint[2*i + 1] = min(mint[2*i + 1], mint[i]);
        mint[2*i + 1] = max(mint[2*i + 1], mat[i]);
        mat[2*i + 1] = max(mat[2*i + 1], mat[i]);
        mat[2*i + 1] = min(mat[2*i + 1], mint[i]);
    }

    for(int i = (1 << 21); i <= (1 << 21) + N - 1; i++)
        printf("%d\n", min(mint[i],mat[i]));
}

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= K; i++){
        int t, a, b, v;
        scanf("%d%d%d%d", &t, &a, &b, &v);
        if(t == 1)
            Updatemat(a + 1, b + 1, v, 1, 1, (1<<21));
        else
            Updatemint(a + 1, b + 1, v, 1, 1, (1<<21));
    }
    Query();
}
