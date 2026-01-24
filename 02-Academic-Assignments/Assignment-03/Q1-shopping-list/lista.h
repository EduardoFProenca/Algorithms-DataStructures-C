/*
 * 
 * ARQUIVO: lista.h
 * 
 * Este arquivo contém as definições de tipos e os protótipos das funções
 * para manipulação de uma Lista Duplamente Encadeada de produtos.
 * 
 */

#ifndef LISTA_H
#define LISTA_H

// Definição de constantes e macros
#define TRUE            1
#define FALSE           0
#define MEMORY_ERROR    2
#define EXEC_SUCCESS    0

// Estrutura do nó da lista (Item individual)
struct Item {
    char *productName;  // Ponteiro para o nome do produto (alocado dinamicamente)
    float quantity;    // Quantidade do produto
    int isBought;      // Flag: 1 se comprado, 0 se não
    struct Item *next; // Ponteiro para o próximo nó
    struct Item *prev; // Ponteiro para o nó anterior
};

typedef struct Item TItem;

// Estrutura descritora da lista (cabeçalho da lista)
typedef struct {
    TItem *head;        // Ponteiro para o primeiro item
    TItem *tail;        // Ponteiro para o último item
    int count;          // Contador total de itens na lista
    int boughtCount;    // Contador de itens marcados como comprados
} TList;

// Protótipos das Funções
void InitializeList(TList *list);
int InsertItem(TList *list, char productName[], float quantity);
int UpdateItemStatus(TList *list, char productName[]);
int RemoveItem(TList *list, char productName[]);
void PrintListForward(TList *list);
void PrintListBackward(TList *list);

#endif // LISTA_H