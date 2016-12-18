#include <cstdio>

const int MAXN = 1000005;

int arr[MAXN], mat[MAXN], S[MAXN], ids;

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	int mts = 0;
	for (i = N - 1; i >= 0; --i) {
		if (ids == 0) {
			S[ids++] = i;
		} else {
			int tp = S[ids - 1];
			while ((arr[i] > arr[tp]) && (ids)) {
				if (mat[i] < mat[tp]) {
					mat[i] = mat[tp];
				} else {
					mat[i]++;
				}
				ids--;
				if (ids)
					tp = S[ids - 1];
			}
			if(mat[i] > mts)
				mts = mat[i];
			S[ids++] = i;
		}
	}
	printf("%d\n", mts);
	return 0;
}