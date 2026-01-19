#include <stdio.h>
#include <string.h>

int main() {
	char amigos[10000];
	char novos[10000];
	char indicar[30];

    fgets(amigos, sizeof(amigos), stdin);
    fgets(novos, sizeof(novos), stdin);
    amigos[strcspn(amigos, "\n")] = '\0';
    novos[strcspn(novos, "\n")] = '\0';
     
	scanf("%s", indicar);

	if (strcmp(indicar, "nao") == 0) {
		printf("%s %s\n", amigos, novos);
		return 0;
	}
	
	char *pos = strstr(amigos, indicar);
    
    int posicao;
    posicao = pos - amigos; 
    for (int i = 0; i < posicao; i++) 
        printf("%c", amigos[i]);

    printf("%s %s\n", novos, pos);
    

    return 0;
}