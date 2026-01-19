#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

struct regNo
{
	struct regNo *esq;
	int valor;
	struct regNo *mae;
	struct regNo *dir;
};
typedef struct regNo TNo;

int PesquisaValor(TNo *, int);
TNo *Remove(TNo *, int);
TNo *AchaPai(TNo *, int);
void ImprimeArvorePre(TNo *r, int *primeiro);
void ImprimeArvoreIn(TNo *r, int *primeiro);
void ImprimeArvorePost(TNo *r, int *primeiro);
int IncluiItem(TNo **, int);
void DestroiLista(TNo *r);

int main(void)
{
	TNo *raiz = NULL;
	char e[8];
	int num;

	while (scanf(" %s", e) != EOF)
	{

		if (strcmp("INFIXA", e) == 0)
		{
			int primeiro = 0;
			ImprimeArvoreIn(raiz, &primeiro);
			printf("\n");
		}
		else if ('I' == e[0])
		{
			scanf(" %d", &num);
			if (IncluiItem(&raiz, num) == FALSE)
			{
				puts("Memoria insuficiente para inclusao");
				return 2;
			}
		}
		if (strcmp("PREFIXA", e) == 0)
		{
			int primeiro = 0;
			ImprimeArvorePre(raiz, &primeiro);
			printf("\n");
		}
		else if (strcmp("POSFIXA", e) == 0)
		{
			int primeiro = 0;
			ImprimeArvorePost(raiz, &primeiro);
			printf("\n");
		}
		else if (e[0] == 'P')
		{
			scanf(" %d", &num);
			if (PesquisaValor(raiz, num) != FALSE)
				printf("%d existe\n", num);
			else
				printf("%d nao existe\n", num);
		}
		if (e[0] == 'R')
		{
			TNo *pai = NULL;
			scanf(" %d", &num);
			raiz = Remove(raiz, num);
		}
	}

	DestroiLista(raiz);
	raiz = NULL;
	return 0;
}

int IncluiItem(TNo **r, int n)
{
	TNo *aux, *pai;

	aux = (TNo *)malloc(sizeof(TNo));
	if (aux == NULL)
		return FALSE;

	aux->valor = n;
	aux->dir = NULL;
	aux->esq = NULL;

	/* Fazendo o encadeamento do novo noh */
	pai = AchaPai(*r, n);
	if (pai == NULL)
	{
		*r = aux;
		aux->mae = NULL;
	}
	else
	{
		if (n <= pai->valor)
			pai->esq = aux;
		else
			pai->dir = aux;
		aux->mae = pai;
	}
	return TRUE;
}

TNo *AchaPai(TNo *r, int n)
{
	if (r == NULL)
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

void ImprimeArvorePre(TNo *r, int *primeiro)
{

	if (r != NULL)
	{

		if (*primeiro == 0)
		{
			printf("%d", r->valor);
			*primeiro = 1;
		}
		else
			printf(" %d", r->valor);

		ImprimeArvorePre(r->esq, primeiro);
		ImprimeArvorePre(r->dir, primeiro);
	}
}

void ImprimeArvoreIn(TNo *r, int *primeiro)
{

	if (r != NULL)
	{
		ImprimeArvoreIn(r->esq, primeiro);

		if (*primeiro == 0)
		{
			printf("%d", r->valor);
			*primeiro = 1;
		}
		else
			printf(" %d", r->valor);
		;

		ImprimeArvoreIn(r->dir, primeiro);
	}
}

void ImprimeArvorePost(TNo *r, int *primeiro)
{

	if (r != NULL)
	{
		ImprimeArvorePost(r->esq, primeiro);
		ImprimeArvorePost(r->dir, primeiro);

		if (*primeiro == 0)
		{
			printf("%d", r->valor);
			*primeiro = 1;
		}
		else
			printf(" %d", r->valor);
	}
}

void DestroiLista(TNo *r)
{

	if (r != NULL)
	{

		DestroiLista(r->esq);
		DestroiLista(r->dir);

		free(r);
	}
}

int PesquisaValor(TNo *r, int n)
{
	if (r == NULL)
		return FALSE;
	else if (r->valor == n)
		return TRUE;
	else if (r->valor > n)
		return PesquisaValor(r->esq, n);
	else
		return PesquisaValor(r->dir, n);
}

TNo *Remove(TNo *r, int n)
{
	if (r == NULL)
		return NULL;

	if (r->valor == n)
	{
		/* Caso 1 e 2: sem filhos ou um filho */
		if (r->esq == NULL && r->dir == NULL)
		{
			if (r->mae != NULL)
			{
				if (r->mae->esq == r)
					r->mae->esq = NULL;
				else
					r->mae->dir = NULL;
			}
			free(r);
			return NULL;
		}
		else if (r->esq == NULL || r->dir == NULL)
		{
			TNo *filho ;
			filho = (r->esq != NULL) ? r->esq : r->dir;
			
			if (r->mae != NULL)
			{
				if (r->mae->esq == r)
					r->mae->esq = filho;
				else
					r->mae->dir = filho;
				filho->mae = r->mae;
			}
			else
			{
				filho->mae = NULL;
			}
			free(r);
			return filho;
		}
		/* Caso 3: dois filhos - usar ANTECESSOR */
		else
		{
			TNo *antecessor ;
			antecessor = r->esq;

			while (antecessor->dir != NULL)
			{
				antecessor = antecessor->dir;
			}
			
			r->valor = antecessor->valor;
			r->esq = Remove(r->esq, antecessor->valor);
			return r;
		}
	}
	else
	{
		if (n < r->valor)
			r->esq = Remove(r->esq, n);
		else
			r->dir = Remove(r->dir, n);
		return r;
	}
}