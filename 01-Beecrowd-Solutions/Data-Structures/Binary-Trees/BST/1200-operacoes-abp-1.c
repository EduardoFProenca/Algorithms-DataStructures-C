#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FALSE	0
#define TRUE	1

struct regNo
{	struct regNo *esq;
	char valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

TNo *Pesquisa(TNo *, char);
TNo *AchaPai(TNo *, char);
void ImprimeArvorePre(TNo *r,int *primeiro);
void ImprimeArvoreIn(TNo *r, int *primeiro );
void ImprimeArvorePost(TNo *r,int *primeiro);
int IncluiItem(TNo **, char);
void DestroiLista(TNo *r);


int main(void)
{	TNo *raiz = NULL;
	char e[8];
	char letra;

	while(scanf(" %s", e) != EOF ) {

		if(strcmp("INFIXA", e) == 0 ) {
			int primeiro = 0;
			ImprimeArvoreIn(raiz, &primeiro);
			printf("\n");
		} else if('I' == e[0]) {
			scanf(" %c", &letra) ;
			if (IncluiItem(&raiz, letra) == FALSE)
			{	puts("Memoria insuficiente para inclusao");
				return 2;
			}
		} 
		if(strcmp("PREFIXA",e) == 0) {
			int primeiro = 0;
			ImprimeArvorePre(raiz,&primeiro);
			printf("\n");
		}
		else if (strcmp("POSFIXA", e) == 0) {
			int primeiro = 0;
			ImprimeArvorePost(raiz,&primeiro);
			printf("\n");
		}
		else if (e[0] == 'P') {
        scanf(" %c", &letra);
        if (Pesquisa(raiz, letra) != NULL)
            printf("%c existe\n", letra);
        else
            printf("%c nao existe\n", letra);
    }
		


	}
	DestroiLista(raiz);
	raiz = NULL;
	return 0;
}

int IncluiItem(TNo **r, char n)
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

TNo *AchaPai(TNo *r, char n)
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

void ImprimeArvorePre(TNo *r, int *primeiro)
{	


	if (r != NULL)
	{

		if(*primeiro == 0){
			printf("%c", r->valor);
			*primeiro = 1;
		}else
			printf(" %c", r->valor);

		ImprimeArvorePre(r->esq,primeiro);
		ImprimeArvorePre(r->dir, primeiro);
	}
}

void ImprimeArvoreIn(TNo *r, int *primeiro)
{	

	if (r != NULL)
	{
		ImprimeArvoreIn(r->esq, primeiro );

		if(*primeiro == 0){
			printf("%c", r->valor);
			*primeiro = 1;
		}else
			printf(" %c", r->valor);;

		ImprimeArvoreIn(r->dir, primeiro);

	}
}

void ImprimeArvorePost(TNo *r, int *primeiro)
{	


	if (r != NULL)
	{
		ImprimeArvorePost(r->esq, primeiro);
		ImprimeArvorePost(r->dir, primeiro);

		if(*primeiro == 0){
			printf("%c", r->valor);
			*primeiro = 1;
		}else
			printf(" %c", r->valor);

	}
}




void DestroiLista(TNo *r)
{


	if(r != NULL)
	{

		DestroiLista(r->esq);
		DestroiLista(r->dir);

		free(r);
	}

}

TNo *Pesquisa(TNo *r, char n){
    if (r != NULL){
     	if( n > r->valor )
			return Pesquisa(r->dir, n);
		else if( n < r->valor )
			return Pesquisa(r->esq, n);
		else if (n == r->valor)
			return r;
	}
	return NULL; 
}

