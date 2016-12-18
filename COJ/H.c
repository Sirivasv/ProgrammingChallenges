//Rivas - Arreglote
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const long long MAXN = 1000000000000LL;

int IsVowel(char c) {
	if (c == 'a')
		return 1;
	if (c == 'e')
		return 1;
	if (c == 'i')
		return 1;
	if (c == 'o')
		return 1;
	if (c == 'u')
		return 1;
	return 0;
}

int main() {
	
	char *str = (char*)malloc(sizeof(char) *  MAXN);
	char *nstr = (char*)malloc(sizeof(char) *  MAXN);
	
	while (scanf("%s", str) != EOF) {
		int lim = strlen(str), tam = 0, i;
		
		for (i = 0; i < lim; ++i)
			if (IsVowel(str[i]))
				nstr[tam++] = str[i];
		
		nstr[tam] = '\0';
		
		lim = (tam / 2);
		
		i = 0;
		int j = tam - 1, ok = 1;
		
		for (;i < j;) {
			if (nstr[i] != nstr[j])
				ok = 0;
			i++;
			j--;
		}
		
		if (ok)
			printf("N\n");
		else
			printf("N\n");
		
	}
	return 0;
}
