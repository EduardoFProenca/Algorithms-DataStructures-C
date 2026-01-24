/*
 * 
 * ARQUIVO: lista.c
 * 
 * Implementação das funções de manipulação da Lista de Compras.
 * Mantém os itens ordenados alfabeticamente e permite inserção, remoção,
 * marcação de compra e impressão (normal e reversa).
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Inicializa os ponteiros da lista e os contadores
void InitializeList(TList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    list->boughtCount = 0;
}

// Insere um novo item na lista de forma ordenada (ordem alfabética)
int InsertItem(TList *list, char productName[], float quantity)
{
    TItem *newNode, *prevNode, *currNode;  

    // Aloca memória para o novo nó
    newNode = (TItem *) malloc(sizeof(TItem));

    if (newNode == NULL){
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }

    // Copia o nome e preenche os dados
    newNode->productName = strdup(productName);
    newNode->quantity = quantity;
    newNode->isBought = FALSE;

    list->count = list->count + 1;

    // Caso 1: Lista vazia, o novo nó é o único elemento
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->prev = NULL;     
        newNode->next = NULL;
    }
    else {
        // Caso 2: Percorre a lista para encontrar a posição correta (ordem alfabética)
        prevNode = NULL;     
        currNode = list->head;
        
        // Avança enquanto o nome atual for alfabeticamente menor que o novo nome
        while (currNode != NULL && strcmp(currNode->productName, productName) < 0)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }

        // Insere na posição encontrada
        if (currNode != NULL)
        {
            // Caso 2a: Inserção no início da lista
            if (prevNode == NULL) {
                list->head = newNode;
                currNode->prev = newNode;       
                newNode->next = currNode;
                newNode->prev = NULL;        
            }
            // Caso 2b: Inserção no meio da lista
            else {
                currNode->prev = newNode;        
                prevNode->next = newNode;
                newNode->next = currNode;
                newNode->prev = prevNode;    
            }
        }
        else
        {
            // Caso 3: Inserção no final da lista
            list->tail->next = newNode;
            newNode->prev = list->tail;    
            list->tail = newNode;
            newNode->next = NULL;
        }
    }

    return TRUE;
}

// Marca um produto como comprado
int UpdateItemStatus(TList *list, char productName[])
{
    TItem *aux, *prevNode;  

    prevNode = NULL;
    aux = list->head;
    
    // Busca linear pelo produto
    while (aux != NULL && strcmp(aux->productName, productName) != 0)
    {
        prevNode = aux;
        aux = aux->next;
    }

    // Produto não encontrado
    if (aux == NULL) {
        printf("Produto '%s' nao encontrado\n", productName);
        return FALSE;
    }

    // Produto já marcado
    if (aux->isBought == 1) {
        printf(" %s ja foi comprado \n ", productName);
        return FALSE;
    }
    else
    {
        // Marca como comprado e atualiza o contador
        list->boughtCount = list->boughtCount + 1;
        aux->isBought = 1;
    }
    return TRUE;
}

// Remove um produto da lista
int RemoveItem(TList *list, char productName[])
{
    TItem *aux, *prevNode;  

    prevNode = NULL;
    aux = list->head;
    
    // Busca o item a ser removido
    while (aux != NULL && strcmp(aux->productName, productName) != 0)
    {
        prevNode = aux;
        aux = aux->next;
    }

    // Item não encontrado
    if (aux == NULL){
        printf("Valor informado nao existe na lista\n");
        return FALSE;
    }
    else
    {
        // Caso: Remover o primeiro item
        if (prevNode == NULL) {
            list->head = aux->next;
            if(list->head != NULL)
                aux->next->prev = NULL;  
        }
        // Caso: Remover item do meio ou fim
        else {
            prevNode->next = aux->next;
            if(aux->next != NULL) {
                aux->next->prev = prevNode;  
            }
        }
        
        // Atualiza contadores
        list->count = list->count - 1;
        if (aux->isBought == 1)
            list->boughtCount--;

        // Se removeu o último item, atualiza a cauda
        if (aux == list->tail)
            list->tail = prevNode;
            
        // Libera memória
        free(aux->productName); // Libera a string alocada com strdup
        free(aux);
    }

    return TRUE;
}

// Imprime a lista do início ao fim (ordem alfabética)
void PrintListForward(TList *list)
{
    TItem *aux;

    if (list->head == NULL)
        puts("Lista vazia");
    else
    {
        printf("\n Lista de compras (do inicio) \n");

        aux = list->head;
        while (aux != NULL)
        {
            printf("%s  %.2f  %d \n", aux->productName, aux->quantity, aux->isBought);
            aux = aux->next;
        }
        printf("Total itens: %d Itens comprados: %d\n\n", list->count, list->boughtCount);
    }
}

// Imprime a lista do fim para o início (ordem reversa)
void PrintListBackward(TList *list)
{
    TItem *aux;

    if (list->head == NULL)
        puts("Lista vazia");
    else
    {
        printf("\n Lista de compras (do final) \n");

        aux = list->tail;
        while (aux != NULL)
        {
            printf("%s  %.2f  %d \n", aux->productName, aux->quantity, aux->isBought);
            aux = aux->prev; 
        }
        printf("Total itens: %d | Itens comprados: %d\n\n", list->count, list->boughtCount);
    }
}