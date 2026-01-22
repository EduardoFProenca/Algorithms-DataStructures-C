//EDUARDO FERREIRA PROENÇA – 0030482421038
//GABRIEL DOS REIS ANTUNES – 0030482421046
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MEMORY_ERROR 2
#define EXEC_SUCCESS 0

typedef struct regLista {
    char *produto;
    float quantidade;
    int foiComprado;
    struct regLista *prox;
    struct regLista *ant;
} TItem;

typedef struct {
    TItem *inicio, *final;
    int qtde, comprado;
} TLista;

void InicializaLista(TLista *lista);
int IncluiItem(TLista *lista, char nomeProduto[], float quantidade);
int AtualizacaoItem(TLista *lista,  char nomeProduto[]);
int ExcluiItem(TLista *lista, char nomeProduto[]);
void ImprimeListaInicio(TLista *lista);
void ImprimeListaReversa(TLista *lista);

#endif