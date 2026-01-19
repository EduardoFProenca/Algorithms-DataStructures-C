#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE	1
#define FALSE	0
#define EXEC_SUCCESS	0
#define MEMORY_ERROR	2

struct regLista
{
	char valor[10];  
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

int ExcluiItem(DPilha *, char *);
void InicializaLista(DPilha *);
int IncluiItem(DPilha *, char *);

int main(void)
{
	DPilha lista1, lista2, lista3, lista4, lista5;
	InicializaLista(&lista1); 
	InicializaLista(&lista2); 
	InicializaLista(&lista3); 
	InicializaLista(&lista4); 
	InicializaLista(&lista5); 

	char expressao[10];
	int n;

	while (1) {
		scanf("%d", &n);
		if (n == 0) 
		    break;
		    
		scanf("%s", expressao);

		if (n == -1)
			IncluiItem(&lista1, expressao);
		else if (n == -2)
			IncluiItem(&lista2, expressao);
		else if (n == -3)
			IncluiItem(&lista3, expressao);
		else if (n == -4)
			IncluiItem(&lista4, expressao);
	}

	
	while (lista1.qtde > 0 || lista3.qtde > 0 || lista2.qtde > 0 || lista4.qtde > 0) {
		if (lista1.qtde > 0) {
			strcpy(expressao, lista1.topo->valor);
			ExcluiItem(&lista1, expressao);
			IncluiItem(&lista5, expressao);
		}
		if (lista3.qtde > 0) {
			strcpy(expressao, lista3.topo->valor);
			ExcluiItem(&lista3, expressao);
			IncluiItem(&lista5, expressao);
		}
		if (lista2.qtde > 0) {
			strcpy(expressao, lista2.topo->valor);
			ExcluiItem(&lista2, expressao);
			IncluiItem(&lista5, expressao);
		}
		if (lista4.qtde > 0) {
			strcpy(expressao, lista4.topo->valor);
			ExcluiItem(&lista4, expressao);
			IncluiItem(&lista5, expressao);
		}
	}

	TLista *atual = lista5.topo;
	int primeiro = 1;
	
	while (atual != NULL) {
		if (!primeiro) 
		    printf(" ");
		printf("%s", atual->valor);
		primeiro = 0;
		atual = atual->prox;
	}
	printf("\n");

	return EXEC_SUCCESS;
}

void InicializaLista(DPilha *lista) {
	lista->topo = NULL;
	lista->fim = NULL;  
	lista->qtde = 0;
}

int IncluiItem(DPilha *lista, char *valor) {
	TLista *novo = (TLista *) malloc(sizeof(TLista));
	
	
	if (novo == NULL) {
		puts("Erro fatal: Memoria insuficiente para esta operacao");
		return MEMORY_ERROR;
	}
	strcpy(novo->valor, valor);
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


int ExcluiItem(DPilha *lista, char *valor) {
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