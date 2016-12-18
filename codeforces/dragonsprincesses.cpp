#include <bits/stdc++.h>
using namespace std;

typedef int lli;

typedef pair<lli, lli> plli;

const int MAXN = 200009;

bitset<MAXN> arrd;

int main() {
	int N;
	scanf("%d", &N);
	priority_queue<plli, vector<plli>, greater<plli> > pq;
	
	char op;
	int v, aux;
	
	for (int i = 2; i < N; ++i) {
		getchar();
		scanf("%c%d", &op, &v);
		//printf("%c %d\n", op, v);
		if (op == 'd') {
			arrd[i] = 1;
			pq.push(plli(v, i));
		} else {
			aux = pq.size();
			while (aux >= v) {
				arrd[pq.top().second] = 0;
				pq.pop();
				aux--;
			}
		}
	}
	getchar();
	scanf("%c%d", &op, &v);
	//printf("%c %d\n", op, v);
	
	int many = pq.size();
	if (many < v) {
		printf("-1\n");
	} else {
		lli gold = 0;
		aux = pq.size();
		while (aux) {
			gold += pq.top().first;
			pq.pop();
			aux--;
		}
		//cout << gold << '\n';
		printf("%d\n", gold);
		printf("%d\n", many);
		
		int cnt = 0;
		for (int i = 2; i < MAXN; ++i) {
			if (arrd[i]) {
				if (cnt++)
					printf(" ");
				printf("%d", i);
				if (cnt == many)
					break;
			}
		}
	}
	
	return 0;
}