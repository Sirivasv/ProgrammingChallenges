#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30009;
const int MAXQ = 200009;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;
typedef pair<pii, pii> cuar;

int BIT[MAXN];

void Upd(int idx) {
	while (idx < MAXN) {
		BIT[idx]++;
		idx += (idx & (-idx));
	}
} 

int Query(int idx) {
	int res = 0;
	while (idx) {
		res += BIT[idx];
		idx -= (idx & (-idx)); 
	}
	return res;
}

int Range(int a, int b) {
	return (Query(b) - Query(a - 1)); 
}

int AnsQ[MAXQ];
pii PosN[MAXN];
cuar Ques[MAXQ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	
	
	for (int i = 1; i <= N; ++i) {
		int num;
		cin >> num;
		PosN[i - 1].first = -num;
		PosN[i - 1].second = i;
	}
	
	sort(PosN, PosN + N);
	
	int Q;
	cin >> Q;
	
	for (int i = 0; i < Q; ++i) {
		int I, J, K;
		cin >> I >> J >> K;
		
		Ques[i].first.first = -K;
		Ques[i].first.second = i;
		Ques[i].second.first = I;
		Ques[i].second.second = J;
	}
	
	sort(Ques, Ques + Q);
	
	int idN = 0;
	
	for(int i = 0; i < Q; ++i) {
		int k = -Ques[i].first.first;
		for(; idN < N;) {
			int v = -PosN[idN].first;
			if (v > k) {
				Upd(PosN[idN].second);
				idN++;
			} else break;
		}
		 
		int I = Ques[i].second.first, J = Ques[i].second.second, ida = Ques[i].first.second;
		AnsQ[ida] = Range(I, J);
	}
	for (int i  = 0; i < Q; ++i)
		cout << AnsQ[i] << '\n';
	return 0;
}