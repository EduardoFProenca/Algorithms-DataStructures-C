#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE	1
#define FALSE	0
#define EXEC_SUCCESS	0
#define MEMORY_ERROR	2

struct regLista
{
	char valor;
	struct regLista *prox;
};
typedef struct regLista TLista;

struct descrPilha
{
	TLista *topo;
	int qtde;
};
typedef struct descrPilha DPilha;

int ExcluiItem(DPilha *, char);
void InicializaLista(DPilha *);
int IncluiItem(DPilha *, char);

int main(void)
{
	DPilha lista;
	char expressao[1001];

	while(scanf(" %s", expressao) != EOF ) {
		int balanceado = TRUE;  
		InicializaLista(&lista);

		for (int i = 0; i < strlen(expressao); i++)
		{
			char caractere = expressao[i];
			switch(caractere) {
				case '(':
					IncluiItem(&lista, ')');
					break;
				case ')':
					balanceado = ExcluiItem(&lista, caractere);
					break;
				default:
					break;
			}
			if (!balanceado)
				break;
		}

		if (lista.topo == NULL && balanceado)
			printf("correct\n");
		else
			printf("incorrect\n");
	}
	return EXEC_SUCCESS;
}

void InicializaLista(DPilha *lista) {
	lista->topo = NULL;
	lista->qtde = 0;
}

int IncluiItem(DPilha *lista, char delimitadorEsperado) {
	TLista *aux;

	aux = (TLista *) malloc(sizeof(TLista));
	if (aux == NULL) {
		puts("Erro fatal: Memoria insuficiente para esta operacao");
		return MEMORY_ERROR;
	}

	aux->valor = delimitadorEsperado;
	aux->prox = lista->topo;

	lista->topo = aux;
	lista->qtde++;
	return TRUE;
}

int ExcluiItem(DPilha *lista, char delimitadorAtual) {
	TLista *aux;

	if (lista->topo == NULL) {
		return FALSE;
	}
	else if (lista->topo->valor == delimitadorAtual)
	{
		aux = lista->topo;
		lista->topo = lista->topo->prox;
		lista->qtde--;
		free(aux);
		return TRUE;
	}
	else
		return FALSE;
}