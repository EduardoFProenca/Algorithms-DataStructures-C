#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		char linha1[105], linha2[105], resultado[210];
		scanf(" %[^\n]", linha1);
		scanf(" %[^\n]", linha2);

		int i = 0, j = 0, k = 0;
		int from1 = 1; 

		while (i < strlen(linha1) || j < strlen(linha2)) {
			if (from1) {
				if (i < strlen(linha1))
					resultado[k++] = linha1[i++];
				if (i < strlen(linha1))
					resultado[k++] = linha1[i++];
				from1 = 0;
			} else {
				if (j < strlen(linha2))
					resultado[k++] = linha2[j++];
				if (j < strlen(linha2))
					resultado[k++] = linha2[j++];
				from1 = 1;
			}
		}
		resultado[k] = '\0';
		printf("%s\n", resultado);
	}

	return 0;
}