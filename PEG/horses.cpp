#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 500009;
const lli MOD = 1000000007LL;

lli ST[MAXN * 3], arrX[MAXN], invmX[MAXN];
int N;

inline lli Euclides(lli a, lli b, lli& x, lli& y) {
    if (!b) { x = 1, y = 0; return a; }
    lli gcd = Euclides(b, a % b, x, y);
    x = !MOD? x - y * (a / b):
        (MOD + x - (y * (a / b)) % MOD) % MOD;
    swap(x, y);
    return gcd;
}

inline lli InvMod(lli x) {
	lli res, tmpy;
	Euclides(x, MOD, res, tmpy);
	return res;
}

inline void Update(int id, lli v, int n = 1, int l = 1, int r = N) {
	if ((r < id) || (l > id))
		return;
	if ((l >= id) && (r <= id)) {
		ST[n] = v;
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Update(id, v, ls, l, m);
	Update(id, v, rs, m + 1, r);
	ST[n] = max(ST[ls], ST[rs]);
}

inline lli Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if ((r < L) || (l > R))
		return (-1LL);
	if ((l >= L) && (r <= R))
		return ST[n];
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	return max(Query(L, R, ls, l, m), Query(L, R, rs, m + 1, r));
}

set<int> NoOnes;
lli acumXT;

inline lli Process() {
	NoOnes.insert(1);
	NoOnes.insert(N);
	lli MV = Query(N, N);
	lli acumX = acumXT;
	lli ans = (acumX * MV) % MOD;
	
	for (set<int>::reverse_iterator it = NoOnes.rbegin(); it != NoOnes.rend(); it++) {
		int cx = (*it);
		lli qi = Query(cx, cx);  
		if (qi > MV) { 
			MV = qi;
			ans = (acumX * qi) % MOD;
		}
		//cout << cx << ' ' << ans << '\n';
		MV = (MV * arrX[cx]);
		if (MV > 1000000000LL)
			break;
		acumX = (acumX * invmX[cx]) % MOD;
		set<int>::reverse_iterator nit = it;
		nit++;
		if (nit == NoOnes.rend())
			continue;
		int le = (*nit) + 1;
		int ri = (*it) - 1;
		//cout << le << ' ' << ri << '\n';
		if (le <= ri) {
			lli yi = Query(le, ri);
			//cout << QueryBIT(le) << ' ' << yi << ' ' << MV << '\n';
			if (yi > MV) {
				MV = yi;
				ans = (acumX * yi) % MOD;
			}
		}
	}
	return ans;
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	acumXT = 1LL;
	//cin >> N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%lld", &arrX[i]);
		acumXT = (acumXT * arrX[i]) % MOD;
		invmX[i] = InvMod(arrX[i]);
		if (arrX[i] != 1LL) 
			NoOnes.insert(i);
	}
	for (int i = 1; i <= N; ++i) {
		lli a;
		scanf("%lld", &a);
		Update(i, a);
	}
	printf("%lld\n", Process());
	//cout << Process() << '\n';
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int tp, pos ;
		lli v;
		//cin >> tp >> pos >> v;
		scanf("%d%d%lld", &tp, &pos, &v);
		pos++;
		if (tp == 1) {
			if (v == 1LL)
				NoOnes.erase(pos);
			else
				NoOnes.insert(pos);
			acumXT = (acumXT * invmX[pos]) % MOD;
			acumXT = (acumXT * v) % MOD;
			arrX[pos] = v; 
			invmX[pos] = InvMod(v);
		} else
			Update(pos, v);
		//cout << Process() << '\n';
		printf("%lld\n", Process());
	}
	return 0;
}