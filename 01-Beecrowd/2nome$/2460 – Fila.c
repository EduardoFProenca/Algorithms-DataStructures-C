#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define MEMORY_ERROR	2
#define EXEC_SUCCESS	0

struct regLista	{
	int valor;
	struct regLista *prox;
};
typedef struct regLista TItem;

typedef  struct {
	TItem *inicio, *final;
	int qtde, soma;
} TLista;

void DestroiLista(TLista *);
int ExcluiItem(TLista *, int);
void ImprimeLista(TLista *);
int IncluiItem(TLista *, int);
void InicializaLista(TLista *);

int main(void)
{	int numero;
	TLista lista;

	InicializaLista(&lista);
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++)
	{
		scanf("%d", &numero);

		if (IncluiItem(&lista, numero) == FALSE)
		{	puts("Erro fatal: Memoria insuficiente para esta operacao");
			return MEMORY_ERROR;
		}
	}

	int m;
	scanf("%d",&m);
	for(int i = 0; i< m ; i++ )
	{
		scanf("%d", &numero);



		if (ExcluiItem(&lista, numero) == FALSE)
			puts("Valor informado nao existe na lista");


	}
	ImprimeLista(&lista);
	DestroiLista(&lista);

	return EXEC_SUCCESS;
}

void DestroiLista(TLista *lista)
{	TItem *aux, *seg;

	aux = lista->inicio;
	while (aux != NULL)
	{	seg = aux->prox;

		free(aux);

		aux = seg;
	}

	InicializaLista(lista);
}

int ExcluiItem(TLista *lista, int valor)
{	TItem *aux, *ant;

	/* Pesquisando na lista o item a ser excluido */
	ant = NULL;
	aux = lista->inicio;
	while (aux != NULL && aux->valor != valor)
	{	ant = aux;
		aux = aux->prox;
	}

	/* Removendo da lista o item solicitado */
	if (aux == NULL)
		return FALSE;
	else
	{	/* Acertando o encadeamento na lista */
		if (ant == NULL)
			lista->inicio = aux->prox;
		else
			ant->prox = aux->prox;

		/* atualizando os descritores complementares */
		lista->qtde = lista->qtde - 1;
		lista->soma = lista->soma - aux->valor;

		if (aux == lista->final)
			lista->final = ant;

		free(aux);
	}

	return TRUE;
}

void ImprimeLista(TLista *lista)
{	TItem *aux;

	/* imprimindo os valores da lista */
	if (lista->inicio == NULL)
		puts("Lista vazia");
	else
	{
		aux = lista->inicio;
		while (aux != NULL)
		{	printf("%d", aux->valor);

			aux = aux->prox;
			if(aux != NULL)
				printf(" ");
		}

	}
	printf("\n");
}

void InicializaLista(TLista *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->soma = 0;
}

int IncluiItem(TLista *lista, int valor)
{	TItem *aux;

	/* criando uma variC!vel struct regLista dinamicamente */
	aux = (TItem *) malloc(sizeof(TItem));

	if (aux == NULL)
		return TRUE;

	/* preenchendo os campos da variC!vel criada dinamicamente */
	aux->valor = valor;
	aux->prox = NULL;

	/* fazendo o encadeamento do novo item na lista */
	if (lista->inicio == NULL)
		lista->inicio = aux;
	else
		lista->final->prox = aux;

	/* atualizando os descritores complementares */
	lista->qtde = lista->qtde + 1;
	lista->soma = lista->soma + aux->valor;
	lista->final = aux;

	return TRUE;
}
