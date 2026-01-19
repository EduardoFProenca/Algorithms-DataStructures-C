#include <stdio.h>

int main()
{
	int num;
	long long int resp;
	int i = 0;

	while(scanf(" %d", &num)!= EOF ) {

		i++;

		long long naoZero = 1;

		for (int i = 2; i <= num; i++) {

			naoZero = naoZero * i;

			while (naoZero % 10 == 0) {
				naoZero /= 10;
			}
			naoZero = naoZero % 1000000;
		}

		int resp = naoZero % 10;

		printf("Instancia %d\n",i);
		printf("%lld\n\n", resp % 10  );

	}

	return 0;
}
