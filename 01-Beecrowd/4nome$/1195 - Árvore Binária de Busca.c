#include <stdio.h>
#include <stdlib.h>

#define FALSE	0
#define TRUE	1

struct regNo
{	struct regNo *esq;
	int valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
void ImprimeArvorePre(TNo *r, int n);
void ImprimeArvoreIn(TNo *r, int n);
void ImprimeArvorePost(TNo *r, int n);
int ContaNos(TNo *);
int SomaNos(TNo *);
int ContaPares(TNo *);
int IncluiItem(TNo **, int);

void DestroiLista(TNo *r, int n);


int main(void)
{	TNo *raiz = NULL;
    int numero, n, c;
    scanf("%d", &c);
    int i;
	for(i = 0; i < c ; i++ ) {
		
		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++ )
		{	scanf("%d", &numero);


			if (IncluiItem(&raiz, numero) == FALSE)
			{	puts("Memoria insuficiente para inclusao");
				return 2;
			}
		}
		printf("Case %d:\n", i+1);
		printf("Pre.:");
		ImprimeArvorePre(raiz, 0);
		printf("\n");
		printf("In..:");
		ImprimeArvoreIn(raiz, 0);
		printf("\n");
		printf("Post:");
		ImprimeArvorePost(raiz, 0);
		printf("\n\n");
		DestroiLista(raiz, 0);
		raiz = NULL;
	}
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

void ImprimeArvorePre(TNo *r, int n)
{	int c;


	if (r != NULL)
	{

		printf(" %d", r->valor);

		ImprimeArvorePre(r->esq, n + 1);
		ImprimeArvorePre(r->dir, n + 1);
	}
}

void ImprimeArvoreIn(TNo *r, int n)
{	int c;

	if (r != NULL)
	{
		ImprimeArvoreIn(r->esq, n + 1);

		printf(" %d", r->valor);

		ImprimeArvoreIn(r->dir, n + 1);

	}
}

void ImprimeArvorePost(TNo *r, int n)
{	int c;


	if (r != NULL)
	{
		ImprimeArvorePost(r->esq, n + 1);
		ImprimeArvorePost(r->dir, n + 1);

		printf(" %d", r->valor);


	}
}


int ContaNos(TNo *r)
{	if (r == NULL)
		return 0;
	else
		return 1 + ContaNos(r->esq) + ContaNos(r->dir);
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

