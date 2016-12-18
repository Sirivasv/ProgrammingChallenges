#include <cstdio>
#include <algorithm>

using namespace std;

int pq[125005];

int main() {
	int N;
	
	scanf("%d", &N);
	
	int lim = (N / 2) + 1;
	for (int i = 0; i < lim; ++i)
		scanf("%d", &pq[i]);
	
	make_heap(pq, pq + N / 2 + 1);
	
	for (int i = lim; i < N; ++i) {
		scanf("%d", &pq[N / 2 + 1]);
		push_heap(pq, pq + N / 2 + 2);
		pop_heap(pq, pq + N / 2 + 2);
	}
	
	if (N & 1)
		printf("%d\n", pq[0]);
	else {
		double a = max(pq[1], pq[2]);
		printf("%.1f\n", ((a + (double)pq[0]) / 2.0));
	}
	return 0;
}