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
	int n;
	int pri = 1;

	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;

		
			
		
		pri = 0;

		while (1) {
			int priValor;
			scanf("%d", &priValor);
			if (priValor == 0)
				break;

			int permutacao[1000];
			permutacao[0] = priValor;
			for (int i = 1; i < n; i++) 
				scanf("%d", &permutacao[i]);
			

			DPilha estacao;
			InicializaLista(&estacao);

			int pro = 1;    
			int possivel = TRUE;

			for (int i = 0; i < n; i++) {
				int alvo = permutacao[i];

				while ((estacao.topo == NULL || estacao.topo->valor != alvo) && pro <= n) {
					IncluiItem(&estacao, pro);
					pro++;
				}

				if (estacao.topo != NULL && estacao.topo->valor == alvo)
					ExcluiItem(&estacao, alvo);
				else {
					possivel = FALSE;
					break;
				}

			}

			if (possivel)
				printf("Yes\n");
			else
				printf("No\n");


		}
		printf("\n");
	}

	return EXEC_SUCCESS;
}
void InicializaLista(DPilha *lista) {
	lista->topo = NULL;
	lista->qtde = 0;
}

int IncluiItem(DPilha *lista, int delimitadorEsperado) {
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

int ExcluiItem(DPilha *lista, int delimitadorAtual) {
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