#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{

	int quat;
	int num;
	char entrada[23];

	scanf("%d", &quat);

	for(int j = quat; j > 0 ; j-- ) {
		scanf(" %s", entrada);

		int i, quatI = 0;
		for(i = 0; i < sizeof(entrada) ; i ++) {
			if(entrada[i] == '!') {
				quatI ++;
				entrada[i] = ' ';
			}
		}
		num = atoi(entrada);
		long long int res = num;

		for(int i = num; i > 0 ;) {
			i = i - quatI;
			if(i <= 0)
				break;
			res =  res * i;
		}
		printf("%lld\n", res);
	}
	return 0;
}
