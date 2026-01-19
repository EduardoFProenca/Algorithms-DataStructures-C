#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE	1
#define FALSE	0
#define EXEC_SUCCESS	0
#define MEMORY_ERROR	2

struct regLista
{
	int valor;
	struct regLista *prox;
};
typedef struct regLista TLista;

struct descrPilha
{
	TLista *topo;
	TLista *fim;
	int qtde;
};
typedef struct descrPilha DPilha;

int ExcluiItem(DPilha *, int );
void InicializaLista(DPilha *);
int IncluiItem(DPilha *, int );

int main(void)
{
	DPilha lista1;
	InicializaLista(&lista1);

	int n, reb;

	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;

		for(int i = 1; i <= n ; i++)
			IncluiItem(&lista1, i);

		printf("Discarded cards:");

		while(lista1.qtde > 1) {
			reb = lista1.topo->valor;
			printf(" %d",  reb);
			ExcluiItem(&lista1, reb);
			reb = lista1.topo->valor;
			IncluiItem(&lista1, reb);
			ExcluiItem(&lista1,reb);
			if(lista1.qtde > 1 )
			    printf(",");
		}
		reb = lista1.topo->valor;
        printf("\n");
		printf("Remaining card: %d\n", reb );
		ExcluiItem(&lista1,reb);
	}

	return EXEC_SUCCESS;
}

void InicializaLista(DPilha *lista) {
	lista->topo = NULL;
	lista->fim = NULL;
	lista->qtde = 0;
}

int IncluiItem(DPilha *lista, int valor) {
	TLista *novo = (TLista *) malloc(sizeof(TLista));


	if (novo == NULL) {
		puts("Erro fatal: Memoria insuficiente para esta operacao");
		return MEMORY_ERROR;
	}
	novo->valor = valor;
	novo->prox = NULL;

	if (lista->fim == NULL) {

		lista->topo = lista->fim = novo;
	} else {
		lista->fim->prox = novo;
		lista->fim = novo;
	}
	lista->qtde++;
	return TRUE;
}


int ExcluiItem(DPilha *lista, int valor) {
	if (lista->topo == NULL) {
		return FALSE;
	}
	TLista *temp = lista->topo;

	lista->topo = lista->topo->prox;
	if (lista->topo == NULL) {
		lista->fim = NULL;
	}
	free(temp);
	lista->qtde--;
	return TRUE;
}