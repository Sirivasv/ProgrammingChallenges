#include <bits/stdc++.h>
using namespace std;

const int MAXN = 809;
bitset<MAXN> PO;
long long NTC[MAXN];
vector<int> NC[MAXN], CC[MAXN];
int LC[MAXN];

long long gcd(long long a, long long b) {
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

long long lcm(long long a, long long b) {
    long long temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

void Process(int id, int currd = 0) {
	if (NTC[id])
		return NTC[id];
	if (PO[id]) 
		return 1;
	int cnt = 0;
	for (int i = 0; i < K; ++i)
		for (int j = CC[i].size() - 1; j >= 0; --j) {
			LC[cnt] = CC[i][j];
			NC[cnt % K].push_back(LC[cnt]);
			if (hr[LC[cnt]]) {
				cnt++;
				continue;
			}
			if (PO[LC[cnt]][cnt])
				hr[LC[cnt]] = 1;
			else
				PO[LC[cnt]][cnt] = 1;
			cnt++;
		}
	
	for (int i = 0; i < K; ++i) {
		CC[i] = NC[i];
		NC[i].clear();
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K;
	while (cin >> N >> K) {
		if (!(N | K))
			break;
		if (K >= N) {
			cout << "1\n";
			continue;
		}
		
		for(int i = 0; i < N; ++i)
			Process(i)
	
		long long result = accumulate(NTC, NTC + N, 1, lcm);
		cout << result << '\n';
	}
	return 0;
}