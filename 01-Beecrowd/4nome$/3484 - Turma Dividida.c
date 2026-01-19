
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define EXEC_SUCCESS 0
#define MEMORY_ERROR 2

#define TRUE 1
#define FALSE 0
#define QTDE_MAX 500

struct regNo
{
	struct regNo *esq;
	int valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

struct regLista
{
	TNo *valor;
	struct regLista *prox;
};
typedef struct regLista TLista;

struct descrFila
{
	TLista *topo;
	TLista *fim;
	int qtde;
};
typedef struct descrFila DFila;

int ExcluiItemFila(DFila *, char *);
void InicializaFila(DFila *);
int IncluiItemFila(DFila *, TNo *);
TNo *DesemFilar(DFila *);

TNo *AchaPai(TNo *, int);

void ImprimeArvoreNvl(TNo *, int);
int IncluiItem(TNo **, int);
void DestroiLista(TNo *r, int n);

int main(void)
{
	TNo *raiz = NULL;
	int qt, numero, n;

	//scanf(" %d", &qt);

///	for(d = 0; d < qt; d++) {
	scanf(" %d", &n);

	for(int i = 0; i < n ; i++)
	{
		//printf("\nInforme o valor:\n");
		scanf("%d", &numero);

		if (numero == -999)
			break;

		if (IncluiItem(&raiz, numero) == FALSE)
		{
			puts("Memoria insuficiente para inclusao");
			return 2;
		}
	}

	ImprimeArvoreNvl(raiz, 0);
	DestroiLista(raiz, 0);
	raiz = NULL;
	//}


	return 0;
}


int IncluiItem(TNo **r, int n)
{	TNo *aux, *pai;

	aux = (TNo *) malloc(sizeof(TNo));
	if (aux == NULL)
		return FALSE;

	aux->valor = n;
	aux->dir = NULL;
	aux->esq = NULL;

	/* Fazendo o encadeamento do novo noh */
	pai = AchaPai(*r, n);
	if (pai == NULL)
		*r = aux;
	else if (n <= pai->valor)
		pai->esq = aux;
	else
		pai->dir = aux;

	return TRUE;
}

TNo *AchaPai(TNo *r, int n)
{	if (r == NULL)
		return NULL;
	else if (n <= r->valor)
		/* n C) descendente do lado esquerdo de r */
		if (r->esq == NULL)
			return r;
		else
			return AchaPai(r->esq, n);
	else
		/* n C) descendente do lado direito de r */
		if (r->dir == NULL)
			return r;
		else
			return AchaPai(r->dir, n);
}




void ImprimeArvoreNvl(TNo *r, int n)
{
	DFila fila;
	InicializaFila(&fila);
	int nivel = 0;

	if (r != NULL)
		IncluiItemFila(&fila, r);

	while (fila.qtde > 0)
	{
		int noNivel = fila.qtde;
		int menor = 9999;

		for (int i = 0; i < noNivel; i++)
		{
			TNo *atual = DesemFilar(&fila);
			if (atual->valor < menor)
				menor = atual->valor;

			if (atual->esq != NULL)
				IncluiItemFila(&fila, atual->esq);
			if (atual->dir != NULL)
				IncluiItemFila(&fila, atual->dir);
		}

		printf("%d %d\n", nivel, menor);
		nivel++;
	}
}
/// Fila

void InicializaFila(DFila *lista)
{
	lista->topo = NULL;
	lista->fim = NULL;
	lista->qtde = 0;
}

int IncluiItemFila(DFila *lista, TNo *valor)
{
	TLista *novo = (TLista *)malloc(sizeof(TLista));

	if (novo == NULL)
	{
		puts("Erro fatal: Memoria insuficiente para esta operacao");
		return MEMORY_ERROR;
	}
	novo->valor = valor;
	novo->prox = NULL;

	if (lista->topo == NULL)
	{
		lista->topo = novo;
		lista->fim = novo;
	}
	else
	{
		lista->fim->prox = novo;
		lista->fim = novo;
	}
	lista->qtde++;
	return TRUE;
}

TNo *DesemFilar(DFila *lista)
{
	if (lista->topo == NULL)
		return NULL;

	TLista *temp = lista->topo;
	TNo *valor = temp->valor;

	lista->topo = lista->topo->prox;

	if (lista->topo == NULL)
		lista->fim = NULL;

	free(temp);
	lista->qtde--;

	return valor;
}

void DestroiLista(TNo *r, int n)
{


	if(r != NULL)
	{

		DestroiLista(r->esq, n + 1);
		DestroiLista(r->dir, n + 1);

		free(r);
	}

}
