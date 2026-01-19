#include <stdio.h>
#include <string.h>

int main() {
	int n;


	while (1) {
		int resolvido[26] = {0};
		int correct = 0;
		int incorretas[26] = {0};
		int tempoTotal = 0;

		scanf("%d", &n);
		if(n == 0)
			break;

		for (int i = 0; i < n; i++) {
            char problema;
            int tempo;
            char julgamento[10];
			scanf(" %c %d %s", &problema, &tempo, julgamento);

			int idx = problema - 'A';

			if (strcmp(julgamento, "correct") == 0) {
				resolvido[idx] = 1;
				correct++;
				tempoTotal += tempo + 20 * incorretas[idx];
			} else
				incorretas[idx]++;

		}

		printf("%d %d\n", correct, tempoTotal);
	}
	return 0;
}