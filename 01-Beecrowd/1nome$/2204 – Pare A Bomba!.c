#include <stdio.h>
#include <string.h>

int main() {
	int T;
	char A[1001], B[1001];

	scanf(" %d", &T);
	while (T > 0) {

		scanf(" %s %s", A, B);

		if (strcmp(A, B) == 0)
			printf("%s\n", A);
		else
			printf("1\n");

		T--;
	}
	return 0;
}