#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char caractere;
	int i = 0, j = 0;
	char risadas [51], ris[51] ;

	scanf(" %s", ris);

	for (i = 0; i < strlen(ris) ; i++)
	{

		caractere = ris[i];

		switch(caractere) {

		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			risadas [j]  = caractere ;
			j++;
			break;
		default:
			break;
		}


	}
	risadas[j] = '\0';

	int f = strlen(risadas) - 1 ;
	int c;

	for( c = 0; c < (strlen(risadas) / 2); c++) {

		if(risadas[c] != risadas[f] ) {
			printf("N\n");
			return 0;
		}
		f--;
	}

	printf("S\n");

	return 0;
}
