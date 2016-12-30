#include <cstdio>
#include <cstring>

int main() {
	int ini = 1, fin = 1000000, mid, ans;
	while (ini <= fin) {
		mid = (ini + fin) >> 1;
		printf("%d\n", mid);
		fflush(stdout);
		char response[3];
		scanf("%s", response);
		if (strcmp(response, "<") == 0)
			fin = mid - 1;
		else {
			ans = mid;
			ini = mid + 1;
		}
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}