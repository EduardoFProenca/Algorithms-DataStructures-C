/*
 * 
 * ARQUIVO: lista_estatica.h
 * 
 * Este arquivo contém as definições de tipos e os protótipos das funções
 * para manipulação de uma Lista de Compras utilizando Vetor Estático (Array).
 * A lista mantém os itens ordenados alfabeticamente.
 * 
 */

#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

// Definição de constantes e macros
#define TRUE            1
#define FALSE           0
#define MEMORY_ERROR    2
#define EXEC_SUCCESS    0
#define MAX_ITEMS       50
#define MAX_NAME_LENGTH 26

// Estrutura do Item individual
typedef struct {
    char name[MAX_NAME_LENGTH];  // Nome do produto
    float quantity;              // Quantidade do produto
    int isBought;                // Flag: 1 se comprado, 0 se não
} Item;

// Estrutura da Lista (Vetor Estático)
typedef struct {
    Item items[MAX_ITEMS];       // Array fixo de itens
    int count;                   // Contador total de itens na lista
    int boughtCount;             // Contador de itens marcados como comprados
} TList;

// Protótipos das Funções
void InitializeList(TList *list);
int InsertItem(TList *list, char productName[], float quantity);
int UpdateItemStatus(TList *list, char productName[]);
int RemoveItem(TList *list, char productName[]);
void PrintListForward(TList *list);
void PrintListBackward(TList *list);

#endif // LISTA_ESTATICA_H