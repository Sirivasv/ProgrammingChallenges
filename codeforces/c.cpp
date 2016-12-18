#include <cstdio>
#include <cstring>


int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
char response[10];

int main() {
	int isp = 1, cnt = 0;
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", primes[i]);
		fflush(stdout);
		scanf("%s", response);
		if (strcmp(response, "yes") == 0) {
			cnt++;
			if (cnt == 2) {
				isp = 0;
				break;
			}
		}
		printf("%d\n", primes[i] *  primes[i]);
		fflush(stdout);
		scanf("%s", response);
		if (strcmp(response, "yes") == 0) {
			cnt++;
			if (cnt == 2) {
				isp = 0;
				break;
			}
		}
	}
	for (int i = 4; i < 15; ++i) {
		printf("%d\n", primes[i]);
		fflush(stdout);
		scanf("%s", response);
		if (strcmp(response, "yes") == 0) {
			cnt++;
			if (cnt == 2) {
				isp = 0;
				break;
			}
		}
	}
	if (isp)
		printf("prime\n");
	else
		printf("composite\n");
	fflush(stdout);
	return 0;
}