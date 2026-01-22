//EDUARDO FERREIRA PROENÇA – 0030482421038
//GABRIEL DOS REIS ANTUNES – 0030482421046
#include "Q1-lista.h"

void InicializaLista(TLista *lista)
{
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->comprado = 0;
}

int IncluiItem(TLista *lista, char nomeProduto[], float quantidade)
{
	TItem *aux, *anterior, *atual;  

	aux = (TItem *) malloc(sizeof(TItem));

	if (aux == NULL){
		puts("Erro fatal: Memoria insuficiente para esta operacao");
		return MEMORY_ERROR;
	}

	aux->produto = strdup(nomeProduto);
	aux->quantidade = quantidade;
	aux->foiComprado = 0;

	lista->qtde = lista->qtde + 1;

	if (lista->inicio == NULL) {
		lista->inicio = aux;
		lista->final = aux;
		aux->ant = NULL;     
		aux->prox = NULL;
	}
	else {
		anterior = NULL;     
		atual = lista->inicio;
		while (atual != NULL && strcmp(atual->produto, nomeProduto) < 0)
		{
			anterior = atual;
			atual = atual->prox;
		}
	
	
		if (atual != NULL)
		{
			if (anterior == NULL) {
				lista->inicio = aux;
				atual->ant = aux;       
				aux->prox = atual;
				aux->ant = NULL;        
			}
			else {
				atual->ant = aux;        
				anterior->prox = aux;
				aux->prox = atual;
				aux->ant = anterior;    
			}
		}
		else
		{
			lista->final->prox = aux;
			aux->ant = lista->final;    
			lista->final = aux;
			aux->prox = NULL;
		}
	}

	return TRUE;
}

int AtualizacaoItem(TLista *lista, char nomeProduto[])
{
	TItem *aux;  
	aux = lista->inicio;

	while (aux != NULL && strcmp(aux->produto, nomeProduto) != 0)
	{
		aux = aux->prox;
	}

	if (aux == NULL) {
		printf("Produto '%s' nao encontrado\n", nomeProduto);
		return FALSE;
	}

	if (aux->foiComprado == 1) {
		printf(" %s ja foi comprado \n ", nomeProduto);
		return FALSE;
	}
	else
	{
		lista->comprado = lista->comprado + 1;
		aux->foiComprado = 1;
	}
    
	return TRUE;
}

void ImprimeListaInicio(TLista *lista)
{
	TItem *aux;

	if (lista->inicio == NULL)
		puts("Lista vazia");
	else
	{
		printf("\n Lista de compras (do inicio) \n");

		aux = lista->inicio;
		while (aux != NULL)
		{
			printf("%s  %.2f  %d \n", aux->produto, aux->quantidade, aux->foiComprado);
			aux = aux->prox;
		}
		printf("Total itens: %d Itens comprados: %d\n\n", lista->qtde, lista->comprado);
	}
}

void ImprimeListaReversa(TLista *lista)
{
	TItem *aux;

	if (lista->inicio == NULL)
		puts("Lista vazia");
	else
	{
		printf("\n Lista de compras (do final) \n");

		aux = lista->final;
		while (aux != NULL)
		{
			printf("%s  %.2f  %d \n", aux->produto, aux->quantidade, aux->foiComprado);
			aux = aux->ant; 
		}
		printf("Total itens: %d | Itens comprados: %d\n\n", lista->qtde, lista->comprado);
	}
}

int ExcluiItem(TLista *lista, char nomeProduto[])
{
	TItem *aux, *anterior;  

	anterior = NULL;
	aux = lista->inicio;

	anterior = aux->ant ;

	while (aux != NULL && strcmp(aux->produto, nomeProduto) != 0)
	{
		anterior = aux;
		aux = aux->prox;
	}

	if (aux == NULL){
		printf("Valor informado nao existe na lista\n");
		return FALSE;
	}
	else
	{
		if (anterior == NULL) {
			lista->inicio = aux->prox;
			if(lista->inicio != NULL)
				aux->prox->ant = NULL;  
		}
		else {
			anterior->prox = aux->prox;
			if(aux->prox != NULL) {
				aux->prox->ant = anterior;  
			}
		}
		lista->qtde = lista->qtde - 1;

		if (aux->foiComprado == 1)
			lista->comprado--;

		if (aux == lista->final)
			lista->final = anterior;
		free(aux);
	}

	return TRUE;
}
